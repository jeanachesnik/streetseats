volatile boolean alarmIsrWasCalled = false;

void alarmIsr()
{
    alarmIsrWasCalled = true;
}


void loop() {

  alarmState();

   //While awake, let's switch to ALARM_1 to wake the arduino for sensing every X minutes
   RTC.alarmInterrupt(ALARM_1, true);
   RTC.alarmInterrupt(ALARM_2, false);
//
// RTC.alarmInterrupt(ALARM_1, false);
// RTC.alarmInterrupt(ALARM_2, true);

   Serial.println(counter++);
   delay(1000);

    if (counter == 3){
      lap++;
      Serial << "Lap: " << lap << ' ';
      counter = 0;
      //sleep();
    }
  // put your main code here, to run repeatedly:

///Relay();

lighTest(); 

//there should be a variable that tracks nigh time, 
//eg. if its night then nightTime = 1 if it's day it's 0
//then if nightTime equals 1, we can start a counter that will count every time the arduino wakes up from now on
//then say after 3 hours, the counter is at 18, then we will shut off lights
 

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
      if (RTC.alarm(ALARM_1)) {
            printDateTime( RTC.get() );
            Serial << " --> Alarm 1!" << endl;
        }
//        
       if (RTC.alarm (ALARM_2)) {
          printDateTime( RTC.get() );
            Serial << " --> Alarm 2! - Reading Light Alarm" << endl;
        }
        alarmIsrWasCalled = true;
    }
}



