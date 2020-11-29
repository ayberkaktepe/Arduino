/*
 * EEPROM OKUYUCU
 */
#include <Wire.h>
int veri_adres;
byte veri;
const int8_t EEPROM_adres=80; /*varsayilan 80
*/

void setup() {
  // put your code here, to run once:
Wire.begin();
Serial.begin(9600);
}

void loop() {
  while(veri_adres<256){//byte olduğundan dolayı zaten 255 den büyük değer alamaz
    // put your main code here, to run repeatedly:
Wire.beginTransmission(EEPROM_adres);
Wire.write(veri_adres);
Wire.endTransmission();
Wire.requestFrom(EEPROM_adres, 1);
while(!Wire.available()){}
veri=Wire.read();
Wire.endTransmission();

Serial.println("ADRES:");
Serial.println(veri_adres);
Serial.println("Veri:");
Serial.println(veri);
Serial.println("***********************");
veri_adres++;
if(veri_adres==256){
   delay(10000000);
}
 

  }

}
