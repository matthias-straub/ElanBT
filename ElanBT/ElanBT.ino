// ElanBT Lotus M100 ElanScan Bluetooth Interface 
// (w) in 2022 for Elan owners by Matthias Straub
// provided as is - use at your own risk
// This simply translates serial data between Lotus Elan ALDL (8192 baud, 5v) connected to tx/rx and an HC-05 Bluetooth module (9600 baud default) at pins 10/11 (needs voltage devider for 3.3v)
// v1.0 14.10.2022

#include <SoftwareSerial.h>

SoftwareSerial Bluetooth(10, 11);

void setup () {

    Serial.begin (8192);
    Bluetooth.begin (9600);
}
    
void loop () {
  
 while (Bluetooth.available()) {
  while (Bluetooth.available()) {
       Serial.write(Bluetooth.read());
  }
  delay(2);
 }
 Serial.flush();
 
 while (Serial.available()) {
  while (Serial.available()) {
       Bluetooth.write(Serial.read());
  }
  delay(2);
 }
 Bluetooth.flush();

}
