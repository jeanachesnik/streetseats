
int WakePin = 2;
int sleepStatus = 0;
int count = 0;


void wakeUpNow(){
  //add code here later to include wake up functions
}

void setup() {
  // put your setup code here, to run once:
  pinMode (WakePin,INPUT);
  Serial.begin (9600);

  attachInterrupt(0,wakeUpNow, LOW);

}

void sleepNow() {
  (SLEEP_MODE_PWR_DOWN);
  
 // sleep_enable ();

  attachInterrupt(0,wakeUpNow,LOW);
  //sleep_mode();
  //sleep_disable();
  detachInterrupt (0);

  
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.print ("Awake for");
  Serial.print (count);
  Serial.print (sec);
  count ++;
  delay (1000);

  if (Serial.available()){
    int val = Serial.read();
    if (val =='S') {
      Serial.println ("Serial:Entering Sleep mode");
      delay (100); //need to keep a delay in order to 
      //properly place it into sleep mode
      count = 0;
      sleepNow (); 
    }

    if (val == 'A') {
      Serial.println ("Hola Caracola");
      
    }
  }

  if (count >=10) {
    Serial.println ("Timer:Entering Sleep mode");
    delay (100); //another delay needed for proper sleep

    count 0;

    sleepNow(); sleep function here 
    
  }

}
