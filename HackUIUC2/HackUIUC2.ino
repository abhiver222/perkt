#include <Servo.h>
Servo myservo;
int buzzer = 11;
int pos;
int led = 12;
int x;
int y=1;
int counter;
void setup(){
  myservo.attach(9);
  Serial.begin(9600);
  //Serial.println("Ready");
  pinMode(led,OUTPUT);
}

void loop(){
   
  x = Serial.available();
  if( x == y){
    y = y+1;
    counter = y - x; 
    tone(buzzer,1000); 
   for(pos = 60; pos < 120 ; pos += 1)  // goes from 0 degrees to 180 degrees 
  {    // in steps of 1 degree 
    digitalWrite(led,HIGH) ; 
    delay(15);
    digitalWrite(led,LOW);
    delay(15);
    digitalWrite(led,HIGH);    
    myservo.write(pos);     // tell servo to go to position in variable 'pos' 
    digitalWrite(led,LOW);
    delay(15);
    digitalWrite(led,HIGH);
    delay(15);     // waits 15ms for the servo to reach the position 
    digitalWrite(led,LOW);
} 
  for(pos = 120; pos>60; pos-=1)     // goes from 180 degrees to 0 degrees 
  { digitalWrite(led,HIGH);
    delay(15);
    digitalWrite(led,LOW);  
    delay(15);
    digitalWrite(led,HIGH);
    myservo.write(pos);    // tell servo to go to position in variable 'pos' 
    digitalWrite(led,LOW);
    delay(15);
    digitalWrite(led,HIGH);
    delay(15);    // waits 15ms for the servo to reach the position 
   digitalWrite(led,LOW);
  } 
  noTone(11);
   myservo.write(90);
   
  }
  else
  {
   // Serial.println("DONT SHOOT");
  }
  delay(1000);
 // Serial.println(counter);
  
 
  
}
