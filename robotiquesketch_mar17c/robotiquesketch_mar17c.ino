//maddison est chiante
#include<NewPing.h>
#include<Servo.h>
#define RANGE_SENSOR_PIN 0
Servo myservo;
int x = 230;
#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
float infra;
int ultra;
int martin[180];
int matthieu[180];
int angle1 = 0;
int angle2 = 0;
void setup() {

  myservo.attach(3);
  myservo.write(90);
  // put your setup code here, to run once:
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);

}

void loop() {
bouger(255,255);
//
//  for (int a = 0; a < 18; a++) {
//    myservo.write(10 * a);
//    delay(50);
//    ultra = sonar.ping_cm();
//    infra = 6944.31 * pow(analogRead(RANGE_SENSOR_PIN), -1.05);
//    martin[a] = ultra;
//    matthieu[a] = infra;
//    bouger(255, 255);
//  }
//
//  int wallie1 = 1000;
//  int wallie2 = 1000;
//
//  for (int a = 0; a < 18; a++) {
//    //    Serial.println("wallie1");
//    //    Serial.println(wallie1);
//    //    Serial.println(wallie2);
//    //    Serial.println("martin");
//    //    Serial.println(martin[a]);
//    //    Serial.println("matthieu");
//    //    Serial.println(matthieu[a]);
//    if (martin[a] < wallie1) {
//      wallie1 = martin[a];
//      angle2 = a;
//      Serial.println("wallie1");
//      Serial.println(wallie1);
//      Serial.println("angle");
//      Serial.println(angle1);
//    }
//
//    if (matthieu[a] < wallie2) {
//      wallie2 = matthieu[a];
//      angle1 = a;
//      Serial.println("wallie2");
//      Serial.println(wallie2);
//      Serial.println("angle");
//      Serial.println(angle2);
//    }
//  }
//
//  if (wallie1 < 20 || wallie2 < 20) {
//    if (wallie1 <= wallie2) {
//      bouger(-255, -255);
//      delay(500);
//      if (angle1 < 90) {
//        bouger(255, -255);
//        Serial.println("droite");
//      }
//      else {
//        bouger(-255, 255);
//        Serial.println("gauche");
//      }
//    }
//    else {
//      bouger(-255, -255);
//      delay(500);
//      if (angle2 < 90) {
//        bouger(255, -255);
//        Serial.println("droite");
//      }
//      else {
//        bouger(-255, 255);
//        Serial.println("gauche");
//      }
//    }
//  }
//
//  myservo.write(10);
//  delay(500);
}

void bouger(int x, int y) { //faire un mvt


  if (x == 0 && y == 0) {
    //arret

    digitalWrite(4, 0);
    digitalWrite(5, 0);
    analogWrite(6, x);
    digitalWrite(7, 0);
    digitalWrite(8, 0);
    analogWrite(9, y);
  }
  else if (x > 0 && y > 0) {
    //avancer
    Serial.println("avancer");
    digitalWrite(4, 0);
    digitalWrite(5, 1);
    analogWrite(6, x);
    digitalWrite(7, 1);
    digitalWrite(8, 0);
    analogWrite(9, y);
  }
  else if (x < 0 && y < 0) {
    //reculer

    x = -x;
    y = -y;
    digitalWrite(4, 1);
    digitalWrite(5, 0);
    analogWrite(6, x);
    digitalWrite(7, 0);
    digitalWrite(8, 1);
    analogWrite(9, y);
  }
  else if (x > 0 && y <= 0) {
    //droite

    y = -y;
    digitalWrite(4, 0);
    digitalWrite(5, 1);
    analogWrite(6, x);
    digitalWrite(7, 0 );
    digitalWrite(8, 1);
    analogWrite(9, y);
  }
  else {
    //gauche

    x = -x;
    digitalWrite(4, 1);
    digitalWrite(5, 0);
    analogWrite(6, x);
    digitalWrite(7, 1);
    digitalWrite(8, 0);
    analogWrite(9, y);
  }
}
