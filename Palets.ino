/*************************************************** 
  This is an example sketch for our optical Fingerprint sensor

  Designed specifically to work with the Adafruit BMP085 Breakout 
  ----> http://www.adafruit.com/products/751

  These displays use TTL Serial to communicate, 2 pins are required to 
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/


#include <Adafruit_Fingerprint.h>

// On Leonardo/Micro or others with hardware serial, use those! #0 is green wire, #1 is white
// uncomment this line:
// #define mySerial Serial1

// For UNO and others without hardware serial, we must use software serial...
// pin #2 is IN from sensor (GREEN wire)
// pin #3 is OUT from arduino  (WHITE wire)
// comment these two lines if using hardware serial
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3);

const int led13 = 5;      // Светодиод №1.
const int led7 = 13;      // Светодиод №2.
const int led8 = 6;
const int z = 4;      // Buzzer
const int input = 10;// Светодиод 6.
const int trig = 12;
const int trig1 = 11;
unsigned long timing1;
unsigned long timing;
bool resolutionFlag = false;
bool resolutionFlag1 = false;

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

void setup()  
{
  resolutionFlag = false; 
  resolutionFlag1 = false; 
  Serial.begin(9600);
 // while (!Serial);  // For Yun/Leo/Micro/Zero/...
  delay(100);
  Serial.println("\n\nAdafruit finger detect test");
    pinMode(z, OUTPUT);   
    pinMode(led13, OUTPUT);         
    pinMode(led7, OUTPUT);   
    pinMode(led8, OUTPUT);  
    pinMode(input, INPUT);   
    pinMode(trig, INPUT_PULLUP);  
    pinMode(trig1, INPUT); 
    digitalWrite(led8, HIGH);
  // set the data rate for the sensor serial port
  finger.begin(57600);
  
 /* if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }
*/
  finger.getTemplateCount();
  Serial.print("Sensor contains "); Serial.print(finger.templateCount); Serial.println(" templates");
  Serial.println("Waiting for valid finger...");
}

void loop()                     // run over and over again
{
  getFingerprintIDez();
Swich();
blinking();

}

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;
  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
Unlock();
  if (resolutionFlag = true){
    Swich();
  }
 // return finger.fingerID; 
}
void Swich(){
 // delay(5000);
  label:
  int i = digitalRead(input);
   if((i == 0)&&(resolutionFlag == true)){
   for (int a=0;a<300;a++){
      if (millis() - timing > 2000){
  digitalWrite(led8, HIGH);
  delay(50);
  digitalWrite(led8, LOW); 
  timing = millis();
  }
   delay(a);
    int i = digitalRead(input);
   if((i == 1)&&(resolutionFlag == true)){
    digitalWrite(led8, LOW); 
    goto label;
   }
   // offmus();      
   }
   digitalWrite(led8, HIGH); 
  offmus(); 
 }
 if((i == 1)&&(resolutionFlag == false)){
  if (millis() - timing > 2000){
    digitalWrite(led8, HIGH); 
    tone(z, 600);
     digitalWrite(led7, HIGH);
    delay(80);
    noTone(z);
        digitalWrite(led7, LOW);
    delay(80);
         tone(z, 600);
         digitalWrite(led7, HIGH);
    delay(80);
        noTone(z);
            digitalWrite(led7, LOW);
    delay(80);
         tone(z, 600);
         digitalWrite(led7, HIGH);
    delay(80);
        noTone(z);
            digitalWrite(led7, LOW);
    delay(80);
         tone(z, 300);
         digitalWrite(led7, HIGH);
    delay(500);
    noTone(z);
        digitalWrite(led7, LOW); 
        timing = millis();
 }
 }
}
void off(){
        digitalWrite(led13, LOW);   
    digitalWrite(led8, LOW); 

}

void offmus(){
 
     tone(z, 1200);
     digitalWrite(led7, HIGH);
    delay(30);
    noTone(z);
        digitalWrite(led7, LOW);
    delay(30);
         tone(z, 1100);
         digitalWrite(led7, HIGH);
    delay(30);
        noTone(z);
            digitalWrite(led7, LOW);
    delay(30);
         tone(z, 1000);
         digitalWrite(led7, HIGH);
    delay(30);
        noTone(z);
            digitalWrite(led7, LOW);
    delay(30);
         tone(z, 900);
         digitalWrite(led7, HIGH);
    delay(30);
    noTone(z);
        digitalWrite(led7, LOW); 
        delay(500);
             tone(z, 800);
     digitalWrite(led7, HIGH);
    delay(30);
    noTone(z);
        digitalWrite(led7, LOW);
    delay(30);
         tone(z, 700);
         digitalWrite(led7, HIGH);
    delay(30);
        noTone(z);
            digitalWrite(led7, LOW);
    delay(30);
         tone(z, 600);
         digitalWrite(led7, HIGH);
    delay(30);
        noTone(z);
            digitalWrite(led7, LOW);
    delay(30);
         tone(z, 500);
         digitalWrite(led7, HIGH);
    delay(30);
    noTone(z);
        digitalWrite(led7, LOW); 
            delay(500);
         tone(z, 300);
         digitalWrite(led7, HIGH);
    delay(500);
    noTone(z);
        digitalWrite(led7, LOW); 
        digitalWrite(led8, LOW);     
      digitalWrite(led13, LOW);   
      resolutionFlag1 = false; 
      resolutionFlag = false; 
      
}

void blinking(){
     int i = digitalRead(input);
     int t = digitalRead(trig);
     int c = digitalRead(trig1);
  if((i==0)&&(resolutionFlag1 == false)){
  if (millis() - timing1 > 40000){
  digitalWrite(led8, HIGH);
  delay(200);
  digitalWrite(led8, LOW); 
  timing1 = millis();
  }                                                                 
  }
  if (((t==0)&&(resolutionFlag1 == false))||((c==1)&&(resolutionFlag1 == false))){
   // resolutionFlag1 = true; 
  digitalWrite(led8, HIGH);
  }
    
}
void Unlock(){
  resolutionFlag == true;
  resolutionFlag1 == true;
       digitalWrite(led13, HIGH); 
       digitalWrite(led8, LOW);                                                                                                                                                                                                                                                                                                                   
   /* tone(p, 400);
     digitalWrite(led7, HIGH);
    delay(60);
    noTone(p);
        digitalWrite(led7, LOW);
    delay(60);
    */
         tone(z, 600);
         digitalWrite(led7, HIGH);
    delay(60);
        noTone(z);
            digitalWrite(led7, LOW);
    delay(60);
         tone(z, 800);
         digitalWrite(led7, HIGH);
    delay(60);
        noTone(z);
            digitalWrite(led7, LOW);
    delay(60);
         tone(z, 1000);
         digitalWrite(led7, HIGH);
    delay(60);
    noTone(z);
        digitalWrite(led7, LOW); 
            delay(60);
         tone(z, 1200);
         digitalWrite(led7, HIGH);
    delay(60);
    noTone(z);
        digitalWrite(led7, LOW); //don't ned to run this at full speed.
      
    //   Swich();
}

