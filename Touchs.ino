#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define TTP223_1 A0 //Suma 8 para la izquierda o derecha
#define TTP223_2 A1 //Resta 9 para la derecha o izquierda
#define TTP223_3 A2
#define TTP223_4 A3

LiquidCrystal_I2C lcd(0x3F, 16, 2);

int dato_1;
int dato_2;
int dato_3;
int dato_4;

void setup() {

  Serial.begin(9600);

  pinMode(TTP223_1, INPUT);
  pinMode(TTP223_2, INPUT);
  pinMode(TTP223_3, INPUT);
  pinMode(TTP223_4, INPUT);

  lcd.init();
  lcd.backlight();

}

void loop() {

  if(digitalRead(TTP223_1) == HIGH){

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("1");
  }
    if(digitalRead(TTP223_2) == HIGH){

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(" 2");
  }
    if(digitalRead(TTP223_3) == HIGH){

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(" 3");
  }
    if(digitalRead(TTP223_4) == HIGH){

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("4");
  }
}
