volatile boolean alarmIsrWasCalled = false;

void alarmIsr()
{
    alarmIsrWasCalled = true;
}


void loop() {

  alarmState();

   //While awake, let's switch to ALARM_1 to wake the arduino for sensing every X minutes
   //RTC.alarmInterrupt(ALARM_1, true);
   //RTC.alarmInterrupt(ALARM_2, false);

  
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
            Serial.println("ALARM 1 Going off ---6:45PM___ WHOOOOOOOOOOAHOAHSHAHHAH");
            Serial << " --> Alarm 1!" << endl;
            //sleep();
            //Serial.println ("sleep loop called");
            
            unsetRelays();
            
            //lighTest(); 
        }
        if (RTC.alarm(ALARM_2)) {
            printDateTime( RTC.get() );
            Serial << " --> Alarm 2!" << endl;
            Serial.println("Alarm 2 --11:35PM---- ZZZZZZZZZZZZZZ");
            //lighTest();

             //unsetRelays();
            setRelays();
            
            sleep();
        }
       
        alarmIsrWasCalled = true;
    }

 //sleep ();
}

//ask Carlos about this above function



