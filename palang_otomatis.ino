#include <Servo.h>

#define trig 9
#define echo 8
#define servo 6
#define threshold 15

Servo palang;
int derajat = 0;
unsigned long waktuTerakhirDeteksi = 0;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(servo, OUTPUT);
  palang.attach(servo);
  palang.write(derajat);
}

void loop() {
  int jarak = bacaJarak();

  if(jarak > 0 && jarak < threshold && derajat == 0){
    derajat = 90;
    palang.write(derajat);
    delay(1000);
  }

  if(derajat == 90 && jarak > threshold){
    derajat = 0;
    palang.write(derajat);
    delay(1000);

  }

  delay(1000);
}

    int bacaJarak(){
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    long durasi = pulseIn(echo, HIGH);
    int jarakCm = durasi * 0.034 / 2;
    return jarakCm;
  }
