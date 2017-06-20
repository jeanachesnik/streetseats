/***Using the RTC Example Code and incorporating Sleep Mode **/

//Jeana's Notes - Tried to set alarm to wake up the RTC//
// Date and time functions using a DS3231 RTC connected via I2C and Wire lib
#include <Wire.h>
#include "RTClib.h"


//Sleep Mode library//
#include <LowPower.h>

RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int pin13 = 13;
int pin12 = 12;

//additional code 
const byte seconds = 0;
const byte minutes = 0;
const byte hours = 0;



void setup () {
  pinMode (pin13, OUTPUT);
  pinMode (pin12, OUTPUT);  


#ifndef ESP8266
  while (!Serial); // for Leonardo/Micro/Zero
#endif

  Serial.begin(9600);

  delay(3000); // wait for console opening

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

  setAlarmTime(0,1,0);
  enableAlarm (MARTCH_HHMMSS);
  
}

void loop () {
    DateTime now = rtc.now();
    
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    
    Serial.print(" since midnight 1/1/1970 = ");
    Serial.print(now.unixtime());
    Serial.print("s = ");
    Serial.print(now.unixtime() / 86400L);
    Serial.println("d");
    
    // calculate a date which is 7 days and 30 seconds into the future
    DateTime future (now + TimeSpan(7,12,30,6));
    
    Serial.print(" now + 7d + 30s: ");
    Serial.print(future.year(), DEC);
    Serial.print('/');
    Serial.print(future.month(), DEC);
    Serial.print('/');
    Serial.print(future.day(), DEC);
    Serial.print(' ');
    Serial.print(future.hour(), DEC);
    Serial.print(':');
    Serial.print(future.minute(), DEC);
    Serial.print(':');
    Serial.print(future.second(), DEC);
    Serial.println();
    
    Serial.println();
    delay(3000);
}

void sleeptime() {

  setAlarmTime 
  if (event.light <= 148) 
    
    {
      digitalWrite(pin12, HIGH);
      digitalWrite(pin13,HIGH);
      Serial.print(event.light); Serial.println ("   Nighttime - below lux value");
    }
    else
    {
      delay (3000);
      digitalWrite (pin12,LOW);
      digitalWrite(pin13,LOW);
      Serial.println ("Arduino on Low - Powering Down");
      Serial.print (event.light); Serial.println ("  Daytime - above lux value");
      LowPower.powerDown(SLEEP_2S, ADC_OFF, BOD_OFF);
    }
}

}
    
  //delay (3000);

  //digitalWrite(13,HIGH);
  //Serial.println ("Arduino on High");
  
//  delay(2000);
//  digitalWrite(13,LOW);
//  Serial.println ("Arduino on LOW - going into Power Down mode");
//  LowPower.powerDown(SLEEP_2S, ADC_OFF, BOD_OFF);
//}

