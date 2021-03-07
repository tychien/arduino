#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();
  lcd.init();
  lcd.begin(16,2);

  for(int i =0; i<3; i++){
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
  }
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello Tim");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("CTY studio");
  delay(3000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("type sth");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    delay(100);
    lcd.clear();
    while(Serial.available() > 0){
        lcd.write(Serial.read());
    }
    
  }
}
