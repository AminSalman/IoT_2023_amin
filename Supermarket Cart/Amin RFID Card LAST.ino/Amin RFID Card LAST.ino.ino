#include <SPI.h>
#include <RFID.h>
#include <Servo.h>
#define SS_PIN 10
#define RST_PIN 9
#define GreenLED 2
#define REDLED 4
#define Buzzer 3
Servo myservo;
RFID rfid(SS_PIN, RST_PIN);

String rfidCard;

void setup() {
  myservo.attach(7);
  Serial.begin(9600);
  Serial.println("Starting the RFID Reader...");
  SPI.begin();
  rfid.init();
  pinMode(3  , OUTPUT);
}   

void loop() {
  Serial.println("...");
  if (rfid.isCard()) {
    if (rfid.isCard()) {
      rfidCard = String(rfid.serNum[0]) + " " + String(rfid.serNum[1]) + " " + String(rfid.serNum[2]) + " " + String(rfid.serNum[3]);
      Serial.println(rfidCard);
      if (rfidCard == "194 127 155 27") {
        myservo.write(180); 
        digitalWrite(GreenLED, 255);
        digitalWrite(Buzzer, 255);
        delay(150);
        digitalWrite(Buzzer, 0);
        delay(300);
        digitalWrite(GreenLED, 0);

      } else {
        myservo.write(0); 
        digitalWrite(REDLED, 255);
        digitalWrite(Buzzer, 255);
        delay(1000);
        digitalWrite(Buzzer, 0);
        digitalWrite(REDLED, 0);

      }
    }
    rfid.halt();
  }
}