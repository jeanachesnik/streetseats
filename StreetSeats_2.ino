
//SleepMode Library
//#include <LowPower.h>

//RTC Breakout Precision Timer Library
//#include "RTClib.h"

//Lux Sensor Library
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2561_U.h>

//Included in RTC and LUX Library
#include <Wire.h>


#define setRelay1 13
#define unsetRelay1 12
//const latchrelay2 = 12
//const latchrelay3 = 11
//const latchrelay4 = 10
//const latchrelay5 = 9

int frequency = 5000; //for relay tests
int lighCheckTime = 3000; //how often we check light sensor. 10 minutes will be 600000 milliseconds
int lightVals[3]; //an array to store light readings (3 of them)
int lightReading = 0; //an index we use to cound numbers of readings in our lightTest loop
int lightTotal;
int lightAvg;
int darkVal = 140; //this is our night threshold value in lux
int nightCounter = 0; //this may be used to track how long the lights should be on
int nightCountMax = 10; // 18 times 10 minutes will be about 3 hours (10 miuntes / 60 = 6 light tests per hour)
boolean night = false; // it's night (true) or not (false)



///*** Jeana's Light Sensor VARIABLE Additions BEGIN *///////

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


void setup() {
  // put your setup code here, to run once:
pinMode (setRelay1, OUTPUT);
pinMode (unsetRelay1, OUTPUT);

Serial.begin (9600);
Serial.println("Street Seats Beta 1.0");

////These will turn Relay1 lights OFF
digitalWrite (setRelay1,LOW);
digitalWrite (unsetRelay1,HIGH);
Serial.println ("Relay1: UNSET");

//These will turn Relay1 lights ON
//digitalWrite (setRelay1, HIGH);
//digitalWrite (unsetRelay1,LOW);
//Serial.println ("Relay1: SET");


///*Jeana's Set UP Additions*////
  Serial.println("Light Sensor Test"); Serial.println("");
  
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

delay(1000);
}

