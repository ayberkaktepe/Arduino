/*
 * Sıcaklık sensörü olarak lm35 kullanılmıştır. Kalibrasyon metodu olarak suyun donma ve kaynama noktalarında 
 * ölçümler yapılarak eğim hesaplanmış ve 0-100 derece arasındaki ölçümler yüksek doğrulukta olarak bulunmuştur.
 * Sensör ölçümlerindeki tutarsızlıkları gidermek için 20 adet ölçümü ortalaması alınmış ve yuvarlama yapılmıştır.
 * Dakikada yaklaşık 1 ölçüm alınmış ve ölçümler atmel 611 eepromuna kaydedilmiştir.
 */



#include <Wire.h>
byte adres;
#include <LiquidCrystal.h>

int lm35Pin = A1;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  lcd.begin(16, 2);
  analogReference(INTERNAL);
  lcd.print("Sicaklik Olcumu:");
}

void loop()
{
while(adres<256){


      float sicaklikVolt0 = analogRead(lm35Pin);
  delay(75);
  float sicaklikVolt1 = analogRead(lm35Pin);
  delay(75);
  float sicaklikVolt2 = analogRead(lm35Pin);
  delay(75);
  float sicaklikVolt3 = analogRead(lm35Pin);
  delay(75);
  float sicaklikVolt4 = analogRead(lm35Pin);
  delay(75);
  float sicaklikVolt5 = analogRead(lm35Pin);
  delay(75);
  float sicaklikVolt6 = analogRead(lm35Pin);
  delay(75);
  float sicaklikVolt7 = analogRead(lm35Pin);
  delay(75);
  float sicaklikVolt8 = analogRead(lm35Pin);
  delay(75);
  float sicaklikVolt9 = analogRead(lm35Pin);
  delay(75);
  float sicaklikVolt10 = analogRead(lm35Pin);
  delay(75);
  float sicaklikVolt11 = analogRead(lm35Pin);
  delay(75);
  float sicaklikVolt12 = analogRead(lm35Pin);
  delay(75);
  float sicaklikVolt13 = analogRead(lm35Pin);
  delay(75);
  float sicaklikVolt14 = analogRead(lm35Pin);
  delay(75);
  float sicaklikVolt15 = analogRead(lm35Pin);
  delay(75);
  float sicaklikVolt16 = analogRead(lm35Pin);
  delay(75);
  float sicaklikVolt17 = analogRead(lm35Pin);
  delay(75);
  float sicaklikVolt18 = analogRead(lm35Pin);
  delay(75);
  float sicaklikVolt19 = analogRead(lm35Pin);
  
  float sicaklikVolt = (sicaklikVolt0+sicaklikVolt1+sicaklikVolt2+sicaklikVolt3+sicaklikVolt4+sicaklikVolt5+sicaklikVolt6+sicaklikVolt7+sicaklikVolt8+sicaklikVolt9+sicaklikVolt10+sicaklikVolt11+sicaklikVolt12+sicaklikVolt13+sicaklikVolt14+sicaklikVolt15+sicaklikVolt16+sicaklikVolt17+sicaklikVolt18+sicaklikVolt19)/20;
  
  float sicaklikC = (((sicaklikVolt-38)/7.22)-3.5);
  int y = round(sicaklikC);
  lcd.setCursor(0, 1);
  lcd.print(y);
  lcd.setCursor(3, 1);
  lcd.print(((char)223));
  lcd.setCursor(4, 1);
  lcd.print("C");


  //Yazma
  Wire.beginTransmission(B1010000);//B1010000
  Wire.write(adres);
  Wire.write(y);
  Wire.endTransmission();
  adres++;
  delay(58500);//dakikada 1 ölçüm almak için.
  
}
adres=0;
  }
