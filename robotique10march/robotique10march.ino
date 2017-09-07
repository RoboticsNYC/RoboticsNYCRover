#include<NewPing.h>
#include<Servo.h>
#define RANGE_SENSOR_PIN 0
Servo myservo;
int x = 230;
int dist[180];
int dist2[180];
#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
float infra;
int ultra;
int i;
int juliette = 0;
int martin = 0;
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
  bouger(255, 255); 
  if (martin == 0) {
    for (int i = 0; i < 180; i += 10) {
      dist2[i/10] = sonar.ping_cm();
      dist[i/10] = 6944.31 * pow(analogRead(RANGE_SENSOR_PIN), -1.05);
      myservo.write(i);
      delay(50);
    }
  }
  if (martin == 1) {
    for (int i = 180; i > 0; i -= 10) {
      dist2[i/10] = sonar.ping_cm();
      dist[i/10] = 6944.31 * pow(analogRead(RANGE_SENSOR_PIN), -1.05);
      myservo.write(i);
      delay(50);
    }
  }
  if (martin == 1) {
    martin = 0;
  }
  else {
    martin = 1;
  }
  for(int a = 0;i<18;i++){
    int arg1 = 0;
    if (arg1<dist[i] || arg1<dist[i]){
      arg1 = dist[i];
    }
    
  }
  

}

bool peutavancer() {
  bool a = false;
  ultra = sonar.ping_cm();
  infra = 6944.31 * pow(analogRead(RANGE_SENSOR_PIN), -1.05);
  if ((ultra > 20 || ultra == 0) && infra > 20) {
    a = true;
  }
  return a;
}

void bouger(int x, int y) { //faire un mvt

  Serial.println("bouger");
  if (x == 0 && y == 0) {
    //arret
    Serial.print("arret  ");
    Serial.print(x);
    Serial.print("  ");
    Serial.println(y);
    digitalWrite(4, 0);
    digitalWrite(5, 0);
    analogWrite(6, x);
    digitalWrite(7, 0);
    digitalWrite(8, 0);
    analogWrite(9, y);
  }
  else if (x > 0 && y > 0) {
    //avancer
    Serial.print("avancer  ");
    Serial.print(x);
    Serial.print("  ");
    Serial.println(y);
    digitalWrite(4, 0);
    digitalWrite(5, 1);
    analogWrite(6, x);
    digitalWrite(7, 1);
    digitalWrite(8, 0);
    analogWrite(9, y);
  }
  else if (x < 0 && y < 0) {
    //reculer
    Serial.print("reculer  ");
    Serial.print(x);
    Serial.print("  ");
    Serial.println(y);
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
    Serial.print("droite  ");
    Serial.print(x);
    Serial.print("  ");
    Serial.println(y);
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
    Serial.print("gauche  ");
    Serial.print(x);
    Serial.print("  ");
    Serial.println(y);
    x = -x;
    digitalWrite(4, 1);
    digitalWrite(5, 0);
    analogWrite(6, x);
    digitalWrite(7, 1);
    digitalWrite(8, 0);
    analogWrite(9, y);
  }
}
