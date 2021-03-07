#include <Servo.h>

  Servo xservo;
  Servo yservo;
  int XServoPin = 9;
  int YServoPin = 8;

  int xposPin = A0;
  int yposPin = A1;
  int Xpos = 0;
  int Ypos = 0;
  int buttonPin = 7;
  int buttonPress = 0;
  

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin,HIGH);

  xservo.attach(XServoPin);
  yservo.attach(YServoPin);

}

void loop() {
  // put your main code here, to run repeatedly:
  Xpos = analogRead(xposPin);
  Xpos = map(Xpos, 0, 1023, 0, 180);
  Ypos = analogRead(yposPin);
  Ypos = map(Ypos, 0, 1023, 0, 180);
  xservo.write(Xpos);
  yservo.write(Ypos);
  delay(50);
}
