#include <IRremote.h>
int rec = 13;
int redL = 2;
int yellowL = 3;
int greenL = 4;
int sec = 0;

IRrecv irrecv(rec);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redL, OUTPUT);
  pinMode(yellowL, OUTPUT);
  pinMode(greenL, OUTPUT);
  irrecv.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  timeCheck();
  if (irrecv.decode()){
    Serial.println(results.value,HEX);
    irrecv.resume();
    setTraffic();
    Serial.println(sec);
  }
  else{
    delay(1000);
    sec++;    
  }
} 

void timeCheck(){
  if (sec < 2){
    digitalWrite(redL,HIGH);
    digitalWrite(yellowL,LOW);
    digitalWrite(greenL,LOW);
  }
  else if(sec == 2){
    digitalWrite(redL,LOW);
    digitalWrite(yellowL,HIGH);
    digitalWrite(greenL,LOW);
  }
  else if(sec == 7){
    digitalWrite(redL,LOW);
    digitalWrite(yellowL,LOW);
    digitalWrite(greenL,HIGH);
  }
  else if(sec == 15){
    sec = 0;
  }
}

void setTraffic(){
  sec = 0;
}
