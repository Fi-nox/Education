#include<Servo.h>
#define LEFT A0
#define RIGHT A1 
#define trigpin A2
#define echopin A3
// #define RCGASIN 5
// #define RCLENKUNGIN 6

// int RCsignalgas = 0;
// int RCsignallenkung = 0;

Servo gas;
Servo lenkung;
Servo head;

int pos = 0;
long time;

void setup(){ // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< VOID SETUP

Serial.begin(9600);
gas.attach(9);
lenkung.attach(10);
head.attach(11);

for(pos = 90; pos <= 180; pos += 1){
head.write(pos);
delay(15);
}
 
for(pos = 180; pos >= 0; pos-= 1) {
head.write(pos);
delay(15);
}

for(pos = 0; pos<=90; pos += 1) {
head.write(pos);
delay(15);
}

pinMode(RIGHT, INPUT);
pinMode(LEFT, INPUT);
pinMode(trigpin, OUTPUT);
pinMode(echopin, INPUT);
// pinMode(RCGASIN, INPUT);
// pinMode(RCLENKUNGIN, INPUT);

}

void loop(){ // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< VOID LOOP
unsigned int distance = read_cm();
unsigned int distanceRight = 0;
unsigned int distanceLeft = 0;


delay(50);

int Right_Value = digitalRead(RIGHT);
int Left_Value  = digitalRead(LEFT);

// ------------------------------------------------------------------------------------ SERIAL MONITOR AUSGABE
 
Serial.print("R= ");
Serial.print(Right_Value);
Serial.print(" L= ");
Serial.print(Left_Value);
Serial.print(" D= ");
Serial.println(distance);
// Serial.print("Lenkung= ");
// Serial.println(RCsignallenkung);
// Serial.print("Gas= ");
// Serial.println(RCsignalgas);

// ------------------------------------------------------------------------------------ RC Steuerung TODO

// int RCsignalgas = digitalRead(RCGASIN);
// int RCsignallenkung = digitalRead(RCLENKUNGIN);
// Serial.print("Lenkung= ");
// Serial.println(RCsignallenkung);
// Serial.print("Gas= ");
// Serial.println(RCsignalgas);
// gas.write(RCsignalgas);
// lenkung.write(RCsignallenkung);

// ------------------------------------------------------------------------------------ Objekterkennung

  if(distance <= 50){
      stop();
      delay(300);
      backword();
      delay(900);
      stop();
      delay(300);
      distanceRight = lookRight(); 
      delay(300);
      distanceLeft = lookLeft(); 
      delay(300);
      if (distanceRight >= distanceLeft){
        turnLeft();
        delay(1000);
      }
      else if (distanceRight <= distanceLeft){
        turnRight();
        delay(1000);
      }
  }
  else {
  forword();
  }
distance = read_cm();
}

long read_cm(){ // distanz messen
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  time = pulseIn (echopin, HIGH);
  return time / 29 / 2;
}

int lookRight(){
  head.write(30);
  delay(500);
  int distance = read_cm();
  delay(100);
  head.write(115);
  return distance;
}

int lookLeft(){
  head.write(160);
  delay(500);
  int distance = read_cm();
  delay(100);
  head.write(90);
  return distance;
}




//------------------------------------------------------------------------------------ BEWEGUNG

void forword(){ // gerade vorwärts
lenkung.write(90);
gas.write(120);


}

void backword(){ // gerade zurück
lenkung.write(90);
gas.write(70);
}

void turnLeft(){ // rechts drehen
lenkung.write(35);
gas.write(110);

}

void turnRight(){ // links drehen
lenkung.write(145);
gas.write(110);

}

void stop(){ // anhalten
gas.write(LOW);
lenkung.write(90);
 
}





