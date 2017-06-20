volatile boolean alarmIsrWasCalled = false; 

void alarmIsr()
{
    alarmIsrWasCalled = true;
    //alarmIsrWasCalled = false;
}


void loop() {

  alarmState();


  Serial.println(counter++);
  delay(1000);


if (counter == 5){
      lap++;
      alarmCycle++;


      Serial << "Lap: " << lap << ' '<< "alarmCycle" <<alarmCycle<< ' ';

      if (alarmCycle == 0){
        RTC.setAlarm(ALM1_MATCH_SECONDS,10,0,0,1);
        Serial.println ("Next alarm: 10 secs"); 
      }

      if (alarmCycle == 1){
        RTC.setAlarm (ALM1_MATCH_SECONDS, 20,0,0,1);
        Serial.println ("Next alarm: 20secs");
      }

      if (alarmCycle == 2) {
        RTC.setAlarm (ALM1_MATCH_SECONDS, 30,0,0,1);
        Serial.println ("Next alarm: 30sec");
      }

      if (alarmCycle == 3) {
        RTC.setAlarm (ALM1_MATCH_SECONDS, 40,0,0,1);
        Serial.println ("Next alarm: 40sec");
      }

      if (alarmCycle == 4) {
        RTC.setAlarm (ALM1_MATCH_SECONDS, 50,0,0,1);
        Serial.println ("Next alarm: 50sec");
      }

      if (alarmCycle == 5) {
        RTC.setAlarm (ALM1_MATCH_SECONDS, 0,0,0,1);
        Serial.println ("Next alarm: 0 secs");
        alarmCycle = -1; //this resets the counter to zero? 
      }
      
      counter = 0;
      //placing light test before it returns to sleep after short check...
      

     if (lap == 7){
      //After a number of loop statements (laps), switch to a daily alarm to wake up the arduino on a different schedule (e.g. every day at 3 pm).
      RTC.setAlarm(ALM1_MATCH_HOURS, 0, 04, 11, 1);    //(SS, MM, HH, 1) daydate parameter should be between 1 and 7
      RTC.alarm(ALARM_1);                   //ensure RTC interrupt flag is cleared
      RTC.alarmInterrupt(ALARM_1, true); 
      alarmCycle = -1;    //reset the counter uses to cycle through periodic checks while awake
      lap = 0;            //reset the counter for number of loops
      Serial.println("Changed to a daily alarm - ALARM_1B Launched");
      delay(200);
      //sleep();

    }

    lighTest(); 

    } 



oid printDateTime(time_t t)
{
    Serial << ((day(t)<10) ? "0" : "") << _DEC(day(t)) << ' ';
    Serial << monthShortStr(month(t)) << " " << _DEC(year(t)) << ' ';
    Serial << ((hour(t)<10) ? "0" : "") << _DEC(hour(t)) << ':';
    Serial << ((minute(t)<10) ? "0" : "") << _DEC(minute(t)) << ':';
    Serial << ((second(t)<10) ? "0" : "") << _DEC(second(t));
}

void alarmState() {

//this is necessary in order for the interrupt to be called
//remember the example about instead of a physical interruption 
//were calling it to interrupt when we want through the code

if (alarmIsrWasCalled){
        if (RTC.alarm(ALARM_1)) {
            printDateTime( RTC.get() );
            Serial << " --> Alarm 1!" << endl;
        }
        if (RTC.alarm(ALARM_2)) {
            printDateTime( RTC.get() );
            Serial << " --> Alarm 2!" << endl;
        }
        alarmIsrWasCalled = false;
    }
}
    
  

