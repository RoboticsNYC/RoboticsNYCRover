#ifndef Bouger_h
#define Bouger_h
#include <Servo.h>
#include "Arduino.h"

class Bouger
{
  public:
    Bouger();
	void begin();
    void boug(int f, int g);
    void avan(int k,int l);
    void app(int lopa);
    void allerposer();
  private:
    int _f;
    int _g;
    int _lopa;
    int _k;
    int _l;
 
    Servo myservo0;
    Servo myservo1;
    Servo myservo2;
    Servo myservo3;
    Servo myservo4;
    Servo myservo5;
    int _ar[6] = {90, 90, 90, 90, 90, 90};
    int _retenir1[6] = {90, 90, 90, 90, 90, 90};
    int _retenir2[6] = {90, 90, 90, 90, 90, 90};
    int _retenir3[6] = {90, 90, 90, 90, 90, 90};
    int _retenir4[6] = {90, 90, 90, 90, 90, 90};
    int _retenir5[6] = {90, 90, 90, 90, 90, 90};
    int _retenir6[6] = {90, 90, 90, 90, 90, 90};
    int _angle1, _angle2, _angle3;
    int _gb = 0;
    int _pin[6] = {3, 4, 5, 6, 7, 8};
};

#endif
