#include<Bouger.h>
Bouger mybou;
void setup() {
  // put your setup code here, to run once:
  pinMode(A5,INPUT);
  pinMode(A4,INPUT);
  Serial.begin(9600);
}

void loop() {
//   while (digitalRead(A5)==0){
//      bouger(150,150);
//      Serial.println("yo");
//   }
//   bouger(-255,-255);
//   delay(200);
//   while (digitalRead(A4)== 0){
//      bouger(-150,-150);
//    }
//  Serial.print(digitalRead(A4));
//  Serial.print("     =      ");
//  Serial.println(digitalRead(A5));
  bouger(150,150);
  delay(1000);
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

