//StreetSeats_Test #1


//Libraries 
#include <Wire.h>


//Libraries for RTC Breakout Precision Timer 
//#include "RTClib.h"

//Libraries for Lux Sensor 
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2561_U.h>



int ledPin12  = 12;




Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 12345);

/**************************************************************************/
/*
    Displays some basic information on this sensor from the unified
    sensor API sensor_t type (see Adafruit_Sensor for more information)
*/
/**************************************************************************/
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

/**************************************************************************/
/*
    Configures the gain and integration time for the TSL2561
*/
/**************************************************************************/
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

/**************************************************************************/



void setup() {
  // put your setup code here, to run once:

//pinMode (ledPin12, OUTPUT)

Serial.begin (9600);



//Lux Sensor 
Serial.println ("Light Sensor Test"); Serial.println ("");

//Initialize lux sensor 

if (!tsl.begin())

{
  Serial.println("No TSL2561 detected...Check your wiring or I2C ADDR");
}

//Display basic information about the lux sensor
displaySensorDetails ();

//Setup the lux sensor gain and integration time 
configureSensor();

Serial.println("Ready! Now reading light.");

}

void loop() {
  // put your main code here, to run repeatedly:

/*Get a new Lux Sensor event*/
  sensors_event_t event;
  tsl.getEvent(&event);

/*Display the results that are pulled from the event*/
if (event.light <= 148) 

{
  digitalWrite(ledPin12, HIGH);
  Serial.print(event.light); Serial.println ("   Nighttime - below lux value");
}
else
{
  digitalWrite(ledPin12,LOW);
  Serial.print (event.light); Serial.println ("  Daytime - above lux value");
}

delay (3000);
}

  


  


