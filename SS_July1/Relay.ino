void setRelays () {
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
  Serial.println ("All Relays are OFF");
}

void unsetRelays () {
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

   
