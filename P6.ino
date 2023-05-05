//Librerias//
#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>
//Variables//
RTC_DS1307 rtc;
LiquidCrystal_I2C lcd(0x3F, 16, 2);
#define buzzer = 8;
#define relay = 9;

//Funcion del codigo//
void setup() {
  Wire.begin();
  lcd.init();
  lcd.backlight();
  pinMode(buzzer, OUTPUT);
  pinMode(relay, OUTPUT);
}
//Orden y ejecución del programa//
void loop() {
  DateTime now = rtc.now();
  if (now.hour() == 12 && now.minute() == 50) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Advertencia");
    tone(buzzer, 1000);
    delay(1000);
    noTone(buzzer);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Riego en: 3");
    tone(buzzer, 1000);
    delay(1000);
    noTone(buzzer);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Riego en: 2");
    tone(buzzer, 1000);
    delay(1000);
    noTone(buzzer);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Riego en: 1");
    tone(buzzer, 1000);
    delay(1000);
    noTone(buzzer);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Regando...");
    digitalWrite(relay, HIGH);
    delay(20000);
    digitalWrite(relay, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Riego terminado");
    delay(2000);
  }
}
