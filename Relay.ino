void Relay() {
  //Unset relay1
  digitalWrite (setRelay1,LOW);
  digitalWrite (unsetRelay1,HIGH);
  Serial.println ("Relay1: UNSET");
  
  delay(frequency);
  
  //Set relay1 
  digitalWrite (setRelay1, HIGH);
  digitalWrite (unsetRelay1,LOW);
  Serial.println ("Relay1: SET");
  
  delay(frequency);
}


void UnsetRelay1() {  
  digitalWrite (setRelay1,LOW);
  digitalWrite (unsetRelay1,HIGH);
  Serial.println ("Relay1: UNSET");  
}

void SetRelay1() {
  digitalWrite (setRelay1, HIGH);
  digitalWrite (unsetRelay1,LOW);
  Serial.println ("Relay1: SET");
}



