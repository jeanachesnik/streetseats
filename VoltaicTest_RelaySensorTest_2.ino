
#define CH1 8
#define CH3 7
#define LEDgreen 4
#define LEDyellow 12
const int ldrPin = A0;


void setup(){
  Serial.begin (9600);
   //Setup all the Arduino Pins
   pinMode(CH1, OUTPUT);
   pinMode(CH3, OUTPUT);
   pinMode(LEDgreen, OUTPUT);
   pinMode(LEDyellow, OUTPUT);
   pinMode(ldrPin,INPUT);
   
   //Provide power to both LEDs
   digitalWrite(LEDgreen, HIGH);
   digitalWrite(LEDyellow, HIGH);
   
   //Turn OFF any power to the Relay channels
   digitalWrite(CH1,LOW);
   digitalWrite(CH3,LOW);
   delay(2000); //Wait 2 seconds before starting sequence
 }
 
 void loop(){

  int ldrStatus = analogRead(ldrPin);

  if (ldrStatus <=300){
   digitalWrite(CH1, HIGH);  //Green LED on, Yellow LED off
   //delay(1000);
   Serial.println ("Voltaic Led on");
    
   }

   else

   {

   digitalWrite(CH1, LOW);   //Yellow LED on, Green LED off
   //delay(1000);
   Serial.println ("Arduino is sleeping");
   //digitalWrite(CH3, HIGH);  //Relay 3 switches to NO
   //delay(1000);
   //digitalWrite(CH3,LOW);    //Relay 3 switches to NC
   //delay(1000);
 }
 }
