void lighTest(){
  //paste your light sensr loop code here

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


    for(int i = 0; i < 3; i++)
{
  Serial.print(lightVals[i]);
  Serial.print(", ");
}

  if (lightReading > 2) {
    lightReading = -1;
  }

//a bit of math...
lightTotal = lightVals[0] + lightVals[1] + lightVals[2]; //add the 3 light values...
lightAvg = lightTotal / 3; // divide them by 3
Serial.print(" Avg: ");
Serial.print(lightAvg);
Serial.print(" "); 

 
  /* Display the results (light is measured in lux) */
  if (lightAvg < darkVal) // NIGHT TIME: replace with average values from your array 
  {
    nightCounter++;
    Serial.print("Nighttime below: "); 
    Serial.print(darkVal);
    Serial.print(" ");
    Serial.print("nightCounter: "); //we're keeping a count of the loops to turn lights off after a while
    Serial.print(nightCounter);
    Serial.print(" ");


    UnsetRelay1();// relay1 lights on 
    UnsetRelay2();// relay2 lights on
    UnsetRelay3();// relay3 lights on
    UnsetRelay4();// relay4 lights on
    UnsetRelay5();// relay5 lights on

    UnsetRelay1(),UnsetRelay2(),UnsetRelay3(),UnsetRelay4(),UnsetRelay5();

    if (nightCounter >= nightCountMax){ //check if it's time to turn lights off
      SetRelay1();
      SetRelay2();
      SetRelay3();
      SetRelay4();
      SetRelay5();

     // SetRelay1(),SetRelay2(),SetRelay3(),SetRelay4(),SetRelay5;
      //set lights off
    }
    
  }
  else
  {
    /* If event.light = 0 lux the sensor is probably saturated
       and no reliable data could be generated! */
    //Serial.println("Sensor overload");
     SetRelay1();
     SetRelay2();
     SetRelay3();
     SetRelay4();
     SetRelay5();
     nightCounter = 0; //resets the counter when it's bright again
  }

  lightReading++;
  delay(lighCheckTime);

}


