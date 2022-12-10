int ROT=5;
int GELB=6;
int GRUN=7;
int Taster=4;
int tasterstatus=0;
int FUSG=3;
int FUSR=2;
int SPEAKER=8;
int pipe=5;


void setup() {
  pinMode(ROT,OUTPUT);
  pinMode(GELB,OUTPUT);
  pinMode(GRUN,OUTPUT);
  pinMode(Taster,INPUT);
  pinMode(SPEAKER,OUTPUT);
}

void loop() {
  digitalWrite(GRUN,HIGH);
  digitalWrite(FUSR,HIGH);

  tasterstatus=digitalRead(Taster);
  if (tasterstatus == HIGH) {
    delay(2000);
    digitalWrite(GRUN,LOW);
    digitalWrite(GELB,HIGH);
    delay(1000);
    digitalWrite(GELB,LOW);
    digitalWrite(ROT,HIGH);
    delay(1000);
    digitalWrite(FUSG,HIGH);
    digitalWrite(FUSR,LOW);
    
    while (pipe > 0){
      tone(SPEAKER,20,100);
      delay(500);
      pipe = pipe - 1;
    }
    pipe = pipe + 5;

    digitalWrite(FUSG,LOW);
    digitalWrite(FUSR,HIGH);
    delay(1000);
    digitalWrite(GELB,HIGH);
    delay(1000);
    digitalWrite(ROT,LOW);
    digitalWrite(GELB,LOW);
  }

}
