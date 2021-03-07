#include <Servo.h>

Servo sonarservo;
int SServoPin = 11;
int pose[]={1,45,90,135,179};
int i;

void forward() { digitalWrite(6,LOW); digitalWrite(7,HIGH); digitalWrite(8,HIGH); digitalWrite(9,LOW);}
void backward() { digitalWrite(6,HIGH); digitalWrite(7,LOW); digitalWrite(8,LOW); digitalWrite(9,HIGH);}
void turnRight() { digitalWrite(6,LOW); digitalWrite(7,LOW); digitalWrite(8,HIGH); digitalWrite(9,LOW);}
void turnLeft() { digitalWrite(6,LOW); digitalWrite(7,HIGH); digitalWrite(8,LOW); digitalWrite(9,LOW);}
void circle() { digitalWrite(6,HIGH); digitalWrite(7,LOW); digitalWrite(8,LOW); digitalWrite(9,HIGH);}
void vstop() { digitalWrite(6,LOW); digitalWrite(7,LOW); digitalWrite(8,LOW); digitalWrite(9,LOW);}

char input;

void setup() {
  // put your setup code here, to run once:
  pinMode(6, OUTPUT); 
  pinMode(7, OUTPUT); 
  pinMode(8, OUTPUT); 
  pinMode(9, OUTPUT);
  sonarservo.attach(SServoPin);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    input = Serial.read();
    switch (input){
      case 'w':
        forward();
        delay(100);
        vstop();
        break;
      case 's':
        backward();
        delay(100);
        vstop();
        break;
      case 'a':
        turnRight();
        delay(100);
        vstop();
        break;
      case 'd':
        turnLeft();
        delay(100);
        vstop();
        break;
      
      default:
        vstop();
        break;
    } 
  }
  for(i = 0; i<=4; i++){
    sonarservo.write(pose[i]);
    delay(1000);
  }
  for(i = 4; i>=0; i--){
    sonarservo.write(pose[i]);
    delay(1000);
  }
  /*
  for(pose = 0; pose<=180; pose++){
    sonarservo.write(pose);
    delay(10);
  }  
  for(pose =180; pose>0; pose--){
    sonarservo.write(pose);
    delay(10);
  }
  */
  vstop();    
}
