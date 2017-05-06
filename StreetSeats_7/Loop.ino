volatile boolean alarmIsrWasCalled = false; 

// Jeana's Notes// 
    // If I declare alarmIsrWasCalled = false, where am I saying how it's determined to be false?
    // Also if alarmIsrWasCalled false, does this also mean that it's associated with one of the Alarms being on or off?
    // Originally I thought that if alarmIsrWasCalled = false then that must follow in line with ALARM_1 being false
    // but now, I'm not sure if this is the right logic. And if it starts off as false, what is enabling it to turn true 
    // in the void alarmIsr() below. 
    
    //To try and solve this I rewrote some of the code to reflect how I was approaching it. I also considered creating 
    //two different alarmStates... void alarmState1 () would set ALARM_2 and then void alarmState2() would set ALARM_1 
    
    //I also rearranged the order of this loop tab to see if it would help but it may be possible that I've caused the code
    //because I'm calling something too soon. 

//When I test the code I'm having a problem with these items 
    //*ALARM_2 Waking up and staying on -- I thought since it's a boolean only one can be on at a time, but
    // when I'm testing the code sometimes it seems that both are on, this could definitely be something 
    // I'm missing. 
    //*Sleep -- Sometimes after one lap, it will stay in sleep mode. 
  


void alarmIsr()
{
    alarmIsrWasCalled = true;
    //alarmIsrWasCalled = false;
}


void alarmState() {

if (alarmIsrWasCalled = true) {
    (RTC.alarm(ALARM_2)) {
    printDateTime( RTC.get() );
    Serial << " --> Alarm 2 is true?" << endl;

    alarmIsrWasCalled = true;
}

  
if (alarmIsrWasCalled = false){
         (RTC.alarm(ALARM_1)) {
         printDateTime( RTC.get() );
         Serial << " --> Alarm 1! is false" << endl;
        }
//        if (RTC.alarm(ALARM_2)) {
//            printDateTime( RTC.get() );
//            Serial << " --> Alarm 2!" << endl;
//        }
        alarmIsrWasCalled = false; // Don't understand why this would be called false? Does it 
        //turn alarmIsrWasCalled to false after it's complete? //are Alarm 1/alarmIsrWasCalled/night boolean working 
        //as the same varibale?
    }
}


void loop() {

  alarmState();

   //While awake, let's switch to ALARM_1 to wake the arduino for sensing every X minutes
   RTC.alarmInterrupt(ALARM_1, true);
   RTC.alarm (ALARM_1); 
   RTC.alarmInterrupt(ALARM_2, false);
   RTC.alarm (ALARM_2);


   Serial.println(counter++);
   delay(1000);

    if (counter == 5){
      lap++;
      Serial << "Lap: " << lap << ' ';
      counter = 0;
      sleep();
    }
  // put your main code here, to run repeatedly:

///Relay();

lighTest(); 


//if (lightAvg < darkVal) {
//    night = true; 
//}
//
//else {
//    night = false; 
//}
//
//
//if (night = true) { 
//  nightCounter >= nightCountMax;
//  RTC.alarmInterrupt(ALARM_1, false);
//  RTC.alarm (ALARM_1);
//  Serial.println ("night equals true and counter == countMax");
//  RTC.alarmInterrupt(ALARM_2, true);
//  RTC.alarm (ALARM_2);
//
//    if (RTC.alarm(ALARM_2)) {
//            printDateTime( RTC.get() );
//            Serial << " --> Alarm 2 is back on!" << endl;
//        }
//}

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


//Where I'm getting stuck is trying to add the variable to reset Alarm 1 and also making sure that the counter is 
//checking every couple minutes instead it goes back to sleep after the first lap...//





