void lighTest(){

  /* Get a new sensor event */ 
  sensors_event_t event;
  tsl.getEvent(&event);

  Serial.print(event.light);
  Serial.print("\t");

  if (lightReading == 3){
    lightReading = 0;
  }

  Serial.print(lightReading);
  Serial.print("\t");

  lightVals[lightReading] = event.light;

  if (lightAvg < darkVal) 
  {
    nightCounter++;
    Serial.print("Nighttime below: "); 
    Serial.print(darkVal);
    Serial.print(" ");
    Serial.print("nightCounter: "); //we're keeping a count of the loops to turn lights off after a while
    Serial.print(nightCounter);
    Serial.print(" ");

    unsetRelays();
    Serial.println ("Light avg is below dark value"); 

  }

  if (nightCounter >= nightCountMax){ //check if it's time to turn lights off

      setRelays();
      Serial.println ("Night counter reached max. All Relays Off");

  }else {

    setRelays();
    nightCounter = 0;
    RTC.setAlarm(ALM1_MATCH_HOURS, 0, 04, 11, 1);    //(SS, MM, HH, 1) daydate parameter should be between 1 and 7
    RTC.alarm(ALARM_1);                   //ensure RTC interrupt flag is cleared
    RTC.alarmInterrupt(ALARM_1, true); 
    Serial.println("Changed to a daily alarm - ALARM_1B Launched");
    delay(200);
  }

  lightReading++ // check if you need this 
  Serial.println ("lightreading counter...");
  delay (lighCheckTime);

}}
  
}

