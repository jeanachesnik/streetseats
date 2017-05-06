//void Relay () {
//  
//}

//relay lights off
void setRelay () {
  digitalWrite (setRelay1, HIGH); 
  digitalWrite (unsetRelay1, LOW);
  digitalWrite (setRelay2, HIGH); 
  digitalWrite (unsetRelay2, LOW);
  digitalWrite (setRelay3, HIGH); 
  digitalWrite (unsetRelay3, LOW);
  digitalWrite (setRelay4, HIGH); 
  digitalWrite (unsetRelay4, LOW);
  digitalWrite (setRelay5, HIGH); 
  digitalWrite (unsetRelay5, LOW);
  Serial.println ("Light are off");
  
}


//relay lights all on 
void unsetRelay () {
  digitalWrite (setRelay1, LOW); 
  digitalWrite (unsetRelay1, HIGH);
  digitalWrite (setRelay2, LOW); 
  digitalWrite (unsetRelay2, HIGH);
  digitalWrite (setRelay3, LOW); 
  digitalWrite (unsetRelay3, HIGH);
  digitalWrite (setRelay4, LOW); 
  digitalWrite (unsetRelay4, HIGH);
  digitalWrite (setRelay5, LOW); 
  digitalWrite (unsetRelay5, HIGH);
  Serial.println ("All Relays are ON");
}




void unsetRelaySeq() {
  Serial.println ("Running Twinkle");
  digitalWrite (setRelay1, HIGH); //A
  digitalWrite (unsetRelay1, LOW); //A
  delay (1000);
  digitalWrite (setRelay2, LOW); //B
  digitalWrite (unsetRelay2, HIGH);//B
  delay (1000);
  digitalWrite (setRelay3, HIGH);//C 
  digitalWrite (unsetRelay3, LOW);//C
  delay (1000);
  digitalWrite (setRelay4, LOW);//D 
  digitalWrite (unsetRelay4, HIGH);//D
  delay (1000);
  digitalWrite (setRelay5, HIGH);//E 
  digitalWrite (unsetRelay5, LOW);//E
  digitalWrite (setRelay1, HIGH); //A
  digitalWrite (unsetRelay1, LOW); //A
  delay (1000);
  digitalWrite (setRelay2, LOW); //B
  digitalWrite (unsetRelay2, HIGH);//B
  delay (1000);
  digitalWrite (setRelay3, HIGH);//C 
  digitalWrite (unsetRelay3, LOW);//C
  delay (1000);
  digitalWrite (setRelay4, LOW);//D 
  digitalWrite (unsetRelay4, HIGH);//D
  delay (1000);
  digitalWrite (setRelay5, HIGH);//E 
  digitalWrite (unsetRelay5, LOW);//E
  Serial.println ("Ending Twinkle");
}


