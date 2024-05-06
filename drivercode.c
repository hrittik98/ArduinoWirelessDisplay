#include <LiquidCrystal.h> 
#include <SoftwareSerial.h>
LiquidCrystal lcd(4, 5, 6, 7, 8, 9);
SoftwareSerial mySerial(2, 3);
String val = "No Data"; String oldval;
String newval = "No Data"; int i = 0;
const int ledBuzzerPin = 11;
//(RX, TX);
// LED connected to pin 11
void setup() {
lcd.begin(16,2); mySerial.begin(9600); Serial.begin(9600);
lcd.setCursor(0, 0); lcd.print("WIRELESS MESSAGE"); lcd.setCursor(0, 1);
lcd.print(" DISPLAY "); delay(3000);
lcd.clear();
lcd.print("BY: CSM21050"); lcd.setCursor(0, 1);
lcd.print("CSM21007,CSM21044"); delay(3000);
pinMode(ledBuzzerPin, OUTPUT); }
void loop() {
if (mySerial.available()) {
val = mySerial.readString(); val.trim(); Serial.println(val);
if (val != oldval) { newval = val;
Source Code
11
digitalWrite(ledBuzzerPin, HIGH);
delay(800); // Adjust the duration of the blink as needed digitalWrite(ledBuzzerPin, LOW);
} }
lcd.clear(); lcd.setCursor(i, 0); lcd.print(newval); i++;
if (i >= newval.length() + 16) { i = 0;
}
delay(500); // Adjust the delay between scrolling steps as needed
oldval = val; }
