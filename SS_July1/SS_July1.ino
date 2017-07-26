//Code is collaborated and created by the following:
//MFA DT Student: Jeana Chesnik
//Professor: Carlos Gomez 
//Project: Parsons Street Seats 2017
//GitHub Link: 


//**Libraries**//


       //**SleepMode Library**
       //Remove this one if need be since it's not
       //selected in the other code//
       #include <LowPower.h> 
    
        //RTC Breakout Precision Timer Library
        #include "RTClib.h"

        RTC_DS3231 rtc;
    
         //RTC Timer Libraries 
        #include "LowPower.h"
        #include <DS3232RTC.h>        //http://github.com/JChristensen/DS3232RTC
        #include <Streaming.h>        //http://arduiniana.org/libraries/streaming/
        #include <time.h>             //http://playground.arduino.cc/Code/Time
        #include <TimeLib.h>
        #include <Wire.h> 
    
        //Lux Sensor Library
        #include <Adafruit_Sensor.h>
        #include <Adafruit_TSL2561_U.h>

//**Calling out the Relays - On & Off Switches**//

        //Area E Lighting 
        #define setRelay1 13 //(solid green)
        #define unsetRelay1 12 //(spotted green)
        
        //Area D Lighting
        #define setRelay2 11 //(solid green)
        #define unsetRelay2 10 //(spotted green)
        
        //Area C Lighting
        #define setRelay3 9 //(solid green)
        #define unsetRelay3 8 //(spotted green)
        
        //Area B Lighting
        #define setRelay4 7
        #define unsetRelay4 6
        
        //Area A Lighting 
        #define setRelay5 5
        #define unsetRelay5 4

//****RTC Additions...Timer Pin Definition**// 
        #define SQW_PIN 2    
    
  
//***Calling out other integers and booleans**//

    int counter; //used to count seconds while awake
    int lap; //used to count times the loop routine has been called
    int alarmCycle = -1; 
    int frequency = 5000; //for relay tests
    int lighCheckTime = 30000; //how often we check light sensor. 10 minutes will be 600000 milliseconds
    int lightVals[3]; //an array to store light readings (3 of them)
    int lightReading = 0; //an index we use to cound numbers of readings in our lightTest loop
    int lightTotal;
    int lightAvg;
    int darkVal = 90; //this is our night threshold value in lux
    int nightCounter = 0; //this may be used to track how long the lights should be on
    int nightCountMax = 3;//340 for 3 hours; // 18 times 10 minutes will be about 3 hours (10 miuntes / 60 = 6 light tests per hour)
    boolean night = false; // it's night (true) or not (false) *** do i still need this? 



//***SETTING UP LIGHT SENSOR***////
//Need to also set up the light sensor, below initiate display 
//settings and configuration for it to run

Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 12345);
    
    void displaySensorDetails(void)
    {
      sensor_t sensor;
      tsl.getSensor(&sensor);
      Serial.println("------------------------------------");
      Serial.print  ("Sensor:       "); Serial.println(sensor.name);
      Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
      Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
      Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" lux");
      Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" lux");
      Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" lux");  
      Serial.println("------------------------------------");
      Serial.println("");
      delay(500);
    }
    
    void configureSensor(void)
    {
      /* You can also manually set the gain or enable auto-gain support */
      // tsl.setGain(TSL2561_GAIN_1X);      /* No gain ... use in bright light to avoid sensor saturation */
      // tsl.setGain(TSL2561_GAIN_16X);     /* 16x gain ... use in low light to boost sensitivity */
      tsl.enableAutoRange(true);            /* Auto-gain ... switches automatically between 1x and 16x */
      
      /* Changing the integration time gives you better sensor resolution (402ms = 16-bit data) */
      tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_13MS);      /* fast but low resolution */
      // tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_101MS);  /* medium resolution and speed   */
      // tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_402MS);  /* 16-bit data but slowest conversions */
    
      /* Update these values depending on what you've set above! */  
      Serial.println("------------------------------------");
      Serial.print  ("Gain:         "); Serial.println("Auto");
      Serial.print  ("Timing:       "); Serial.println("13 ms");
      Serial.println("------------------------------------");
    }


///*** Jeana's Light Sensor Additions END *///////

//Now we SETUP//

void setup() {

///*** Jeana's Setup RTC Sensor Additions BEGIN *///////
{
    Serial.begin(115200);
    Serial.println("Street Seats Beta 1.0 Initializing");


 //setSyncProvider() causes the Time library to synchronize with the
    //external RTC by calling RTC.get() every five minutes by default.
    setSyncProvider(RTC.get);
    Serial << "RTC Sync";
    if (timeStatus() != timeSet){
        Serial << " FAIL!";
    }
    Serial << endl;

   // printDateTime ( RTC.get() );
    //Serial << " --> Current RTC time." << endl;

    //Disable the default square wave of the SQW pin.
    RTC.squareWave(SQWAVE_NONE);

}


///***Designating the pins in the Arduino and numbering them to each Relay being used***///
    pinMode (setRelay1, OUTPUT);
    pinMode (unsetRelay1, OUTPUT);
    pinMode (setRelay2, OUTPUT);
    pinMode (unsetRelay2, OUTPUT);
    pinMode (setRelay3, OUTPUT);
    pinMode (unsetRelay3, OUTPUT);
    pinMode (setRelay4, OUTPUT);
    pinMode (unsetRelay4, OUTPUT);
    pinMode (setRelay5, OUTPUT);
    pinMode (unsetRelay5, OUTPUT);


//Telling the relays to turn off when initiating//
    setRelays();
    Serial.println ("All Relays are turned off"); 

///*Jeana's Set UP Additions*////
  Serial.println("Light Sensor Test"); Serial.println("");

//this area of the code is telling the Arduino to recognize the sensor a.k.a "initalise"//
  /* Initialise the sensor */
  if(!tsl.begin())
  {
    /* There was a problem detecting the TSL2561 ... check your connections */
    Serial.print("Ooops, no TSL2561 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  
  /* Display some basic information on this sensor */
  displaySensorDetails();
  
  /* Setup the sensor gain and integration time */
  configureSensor();
  
  /* We're ready to go! */
  Serial.println("");


///*End of SET UP Additions*//

Serial.println("============================");

delay(5000);
}


