
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


//void 

//void Relay() {
//  //Unset relay1
//  digitalWrite (setRelay1,LOW);
//  digitalWrite (unsetRelay1,HIGH);
//  Serial.println ("Relay1: UNSET");
//
////Unset relay2
//  digitalWrite (setRelay2,LOW);
//  digitalWrite (unsetRelay2,HIGH);
//  Serial.println ("Relay1: UNSET");
//  delay(frequency);
//  
//  //Set relay1 
//  digitalWrite (setRelay1, HIGH);
//  digitalWrite (unsetRelay1,LOW);
//  Serial.println ("Relay1: SET");
//
//    //Set relay2 
//  digitalWrite (setRelay2, HIGH);
//  digitalWrite (unsetRelay2,LOW);
//  Serial.println ("Relay1: SET");
//  
//  delay(frequency);
//}
//
////Area A Lighting - Pins 13 & 12
//void UnsetRelay1() {  
//  digitalWrite (setRelay1,LOW); //13
//  digitalWrite (unsetRelay1,HIGH);//12
//  Serial.println ("Relay1 - Area A: UNSET/ON");  
//}
//
//void SetRelay1() {
//  digitalWrite (setRelay1, HIGH);//13
//  digitalWrite (unsetRelay1,LOW);//12
//  Serial.println ("Relay1 - Area A: SET/OFF");
//}
//
////Area B Lighting - Pins 11 & 10 
//void UnsetRelay2() {  
//  digitalWrite (setRelay2,LOW); //11
//  digitalWrite (unsetRelay2,HIGH);//10
//  Serial.println ("Relay2 - Area B: UNSET/ON");  
//}
//
//void SetRelay2() {
//  digitalWrite (setRelay2, HIGH);//11
//  digitalWrite (unsetRelay2,LOW);//10
//  Serial.println ("Relay2 - Area B: SET/OFF");
//}
//
////Area C Lighting - Pins 9 & 8 
//void UnsetRelay3() {  
//  digitalWrite (setRelay3,LOW); //9
//  digitalWrite (unsetRelay3,HIGH);//8
//  Serial.println ("Relay3 - Area C: UNSET/ON");  
//}
//
//void SetRelay3() {
//  digitalWrite (setRelay3, HIGH);//11
//  digitalWrite (unsetRelay3,LOW);//10
//  Serial.println ("Relay3 - Area C: SET/OFF");
//}
//
////Area D Lighting - Pins 7 & 6 
//void UnsetRelay4() {  
//  digitalWrite (setRelay4,LOW); //7
//  digitalWrite (unsetRelay4,HIGH);//6
//  Serial.println ("Relay4 - Area D: UNSET/ON");  
//}
//
//void SetRelay4() {
//  digitalWrite (setRelay4, HIGH);//7
//  digitalWrite (unsetRelay4,LOW);//6
//  Serial.println ("Relay4 - Area D: SET/OFF");
//}
//
////Area E Lighting - Pins 5 & 4 
//void UnsetRelay5() {  
//  digitalWrite (setRelay5,LOW); //5
//  digitalWrite (unsetRelay5,HIGH);//4
//  Serial.println ("Relay5 - Area E: UNSET/ON");  
//}
//
//void SetRelay5() {
//  digitalWrite (setRelay5, HIGH);//5
//  digitalWrite (unsetRelay5,LOW);//4
//  Serial.println ("Relay5 - Area E: SET/OFF");
//}
