#include <BlynkSimpleStream.h>
int sensorPin = A0;    
int ledPin = 9;     
int sensorValue = 1;
 
 char auth[] = "SZN_5JK5GVRNDfFOVo4T0UmPRm_X76Ar";
 
 void setup()
 {
   pinMode(ledPin, OUTPUT);  
   Serial.begin(9600);
   Blynk.begin(auth, Serial);
   pinMode(11, OUTPUT);
   pinMode(12, OUTPUT);
   pinMode(13, OUTPUT);
 }
 BLYNK_WRITE(V1) //Button Widget is writing to pin V1
{
  int pinData = param.asInt(); 
  if(pinData==1){
    digitalWrite(11, HIGH);
  }else{
    digitalWrite(11, LOW);
  }
}
 void loop()
 {
  sensorValue = analogRead(sensorPin);
  // turn the ledPin on
  if (sensorValue<=450)
  {
    digitalWrite(ledPin, HIGH);
  // stop the program for <sensorValue> milliseconds:
  }
  else
  {
    digitalWrite(ledPin, LOW);
  // stop the program for for <sensorValue> milliseconds:
  }
   Blynk.run();
}
