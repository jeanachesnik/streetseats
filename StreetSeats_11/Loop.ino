volatile boolean alarmIsrWasCalled = false; 

void alarmIsr()
{
    alarmIsrWasCalled = true;
}


void loop () {
  alarmState (); 

  //Serial.println (counter++);
  delay (1000); 


}

if {
    RTC.setAlarm (ALM2_MATCH_HOURS, 0, 28, 21,1);
    RTC.alarm(ALARM_2);
    RTC.alarmInterrupt (ALARM_2, true);
    Serial.println ("Alarm 1B is running"); 
    //alarmCycle = -1;
    //lap = 0;
    Serial.println ("Daily Alarm - ALARM_1B Launched");
    delay (200);
    lighTest();
    //sleep ();
  }


//
//  if (counter == 5) {
//    lap++;
//    alarmCycle++;
//
//
//    Serial << "Lap:  " << lap << ' ' << "alarmCycle: " <<alarmCycle << ' ';
//    Serial.println ("Five alarm cycles initializing");
//      if (alarmCycle == 0) {
//        RTC.setAlarm (ALM1_MATCH_SECONDS, 10, 0, 0, 1);
//        Serial.println ("Alarm Cycle 0:10 secs");
//      }
//
//      if (alarmCycle == 1 ) {
//        RTC.setAlarm(ALM1_MATCH_SECONDS, 20,0,0,1);
//        Serial.println ("Alarm Cycle 1: 20sec"); 
//      }
//
//       if (alarmCycle == 2){
//        RTC.setAlarm(ALM1_MATCH_SECONDS, 30, 0, 0, 1);
//        Serial.println("Alarm Cycle 2: 30 secs");
//        }
//    
//        if (alarmCycle == 3){
//        RTC.setAlarm(ALM1_MATCH_SECONDS, 40, 0, 0, 1);
//        Serial.println("Alarm Cycle 3: 40 secs");
//        }
//    
//        if (alarmCycle == 4){
//        RTC.setAlarm(ALM1_MATCH_SECONDS, 50, 0, 0, 1);
//        Serial.println("Alarm Cycle 4: 50 secs");
//        }
//
//      if (alarmCycle == 5){
//        RTC.setAlarm(ALM1_MATCH_SECONDS, 0, 0, 0, 1);
//        Serial.println("Alarm cycle 5: 0 secs");
//        alarmCycle = -1;
//        } 
//
//        counter = 0;
//        lighTest();
//        sleep();
//    
//      }   
//  
//

}

void printDateTime(time_t t)
{
    Serial << ((day(t)<10) ? "0" : "") << _DEC(day(t)) << ' ';
    Serial << monthShortStr(month(t)) << " " << _DEC(year(t)) << ' ';
    Serial << ((hour(t)<10) ? "0" : "") << _DEC(hour(t)) << ':';
    Serial << ((minute(t)<10) ? "0" : "") << _DEC(minute(t)) << ':';
    Serial << ((second(t)<10) ? "0" : "") << _DEC(second(t));
}

void alarmState() {
  
if (alarmIsrWasCalled){
  //if ALARM_1 is called, get the date and time 
        if (RTC.alarm(ALARM_1)) {
            printDateTime( RTC.get() );
            Serial << " --> Alarm 1!" << endl;
        }

   //if ALARM_2 is called, get the date and time
        if (RTC.alarm(ALARM_2)) {
            printDateTime( RTC.get() );
            Serial << " --> Alarm 2!" << endl;
        }

  alarmIsrWasCalled = false;
    }
}



