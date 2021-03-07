char input;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(2000);

  Serial.println("Type something");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    input = Serial.read();
    Serial.print("You typed: ");
    Serial.println(input);
  }
  Serial.println("hello!");
  delay(500);
}
