#include "arduino.h"
#include "Bouger.h"
#include <Servo.h>


Bouger::Bouger()
{

}

void Bouger::begin(){
myservo0.attach(3);
  myservo1.attach(4);
  myservo2.attach(5);
  myservo3.attach(6);
  myservo4.attach(7);
  myservo5.attach(8);
   myservo0.write(90);
   myservo1.write(90);
   myservo2.write(90);
   myservo3.write(90);
   myservo4.write(90);
  myservo5.write(75);
}
void Bouger::avan(int x,int y){
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

void Bouger::allerposer() { // put the robotic arm in a special position
  boug(5, 160);
  delay(2000);
  boug(0, 90);
  boug(1, 90);
  boug(2, 0);
  boug(3, 90);
  boug(4, 180);
  delay(2000);
  boug(5, 75);
  while (1);
}
void Bouger::app(int lopa) // move the arm in a spacific way
{

  _lopa = lopa;
  _angle1 = 155 - _lopa;
  _angle2 = 2 * _lopa;
  _angle3 = 65 - _lopa;
  boug(1, _angle1);
  boug(2, _angle2);
  boug(3, _angle3);
  delay(350);

}

void Bouger::boug(int f, int g) // slowly move any servo
{
  _f = f; // the servo number
  _g = g; // the direction the servo should go to
  //serial.print(_ar[g]);
  if (_f == 0) {
    if (_ar[0] > _g) {
	  //serial.println("	1");
      for (int _lo = _ar[0]; _lo >= _g; _lo--) {
		//serial.println(_lo);
        myservo0.write(_lo);
        delay(_gb);
      }
    }
    if (_ar[0] < _g) {
	  //serial.println("	2");
      for (int _lo = _ar[0]; _lo <= _g; _lo++) {
		//serial.println(_lo);
        myservo0.write(_lo);
        delay(_gb);
      }
    }
    _ar[0] = _g;
  }
  if (_f == 1) {
    if (_ar[1] > _g) {
      for (int _lo = _ar[1]; _lo >=_g; _lo--) {
        myservo1.write(_lo);
        delay(_gb);
      }

    }
    if (_ar[1] < _g) {
      for (int _lo = _ar[1]; _lo <= _g; _lo++) {
        myservo1.write(_lo);
        delay(_gb);
      }

    }
    _ar[1] = _g;
  }
  if (_f == 2) {
    if (_ar[2] > _g) {
      for (int _lo = _ar[2]; _lo >= _g; _lo--) {
        myservo2.write(_lo);
        delay(_gb);
      }
    }
    if (_ar[2] < _g) {
      for (int _lo = _ar[2]; _lo <= _g; _lo++) {
        myservo2.write(_lo);
        delay(_gb);
      }
    }
    _ar[2] = _g;
  }
  if (_f == 3) {
    if (_ar[3] > _g) {
      for (int _lo = _ar[3]; _lo >=_g; _lo--) {
        myservo3.write(_lo);
        delay(_gb);
      }
    }
    if (_ar[3] < _g) {
      for (int _lo = _ar[3]; _lo <= _g; _lo++) {
        myservo3.write(_lo);
        delay(_gb);
      }
    }
    _ar[3] = _g;
  }
  if (_f == 4) {
    if (_ar[4] > _g) {
      for (int _lo = _ar[4]; _lo >= _g; _lo--) {
        myservo4.write(_lo);
        delay(_gb);
      }

    }
    if (_ar[4] < _g) {
      for (int _lo = _ar[4]; _lo <= _g; _lo++) {
        myservo4.write(_lo);
        delay(_gb);
      }

    }
    _ar[4] = _g;
  }
  if (_f == 5) {
    if (_ar[5] > _g) {
      for (int _lo = _ar[5]; _lo >= _g; _lo--) {
        myservo5.write(_lo);
        delay(_gb);
      }
    }
    if (_ar[5] < _g) {
      for (int _lo = _ar[5]; _lo <= _g; _lo++) {
        myservo5.write(_lo);
        delay(_gb);
      }
    }
    _ar[5] = _g;
  }

}
