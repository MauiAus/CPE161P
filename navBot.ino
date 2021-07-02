#include <AFMotor.h>

int in1 = A0;
int in2 = A1;
int in3 = A2;
int in4 = A3;
AF_DCMotor motor1(3);
AF_DCMotor motor2(4);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(in1,INPUT);
  pinMode(in2,INPUT);
  pinMode(in3,INPUT);
  pinMode(in4,INPUT);
  motor1.setSpeed(200);
  motor2.setSpeed(200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(analogRead(A0) == 0){
    Serial.println("1");
    moveUp();
  }
  else if(analogRead(A1) == 0){
    Serial.println("2");
    moveBack();
  }
  else if(analogRead(A2) == 0){
    Serial.println("3");
    moveL();
  }
  else if(analogRead(A3) == 0){
    Serial.println("4");
    moveR();
  }
  else{
  }
  delay(100);
}

void moveUp(){
  motor1.run(FORWARD);
  delay(500);
  motor1.run(RELEASE);
  delay(500);
  motor2.run(FORWARD);
  delay(500);
  motor2.run(RELEASE);
  delay(500);
  motor1.run(FORWARD);
  delay(500);
  motor1.run(RELEASE);
  delay(500);
  motor2.run(FORWARD);
  delay(500);
  motor2.run(RELEASE);
}

void moveBack(){
  motor1.run(BACKWARD);
  delay(500);
  motor1.run(RELEASE);
  delay(500);
  motor2.run(BACKWARD);
  delay(500);
  motor2.run(RELEASE);
  delay(500);
  motor1.run(BACKWARD);
  delay(500);
  motor1.run(RELEASE);
  delay(500);
  motor2.run(BACKWARD);
  delay(500);
  motor2.run(RELEASE);
}

void moveR(){
  motor1.run(FORWARD);
  delay(1000);
  motor1.run(RELEASE);
}

void moveL(){
  motor2.run(FORWARD);
  delay(1000);
  motor2.run(RELEASE);
}
