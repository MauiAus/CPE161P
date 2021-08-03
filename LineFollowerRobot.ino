#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

int control = A0;
int IRL = A1;
int IRR = A2;
int IRM = A3;

bool midFlag = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(IRL, INPUT);
  pinMode(IRR, INPUT);
  pinMode(control, INPUT);
  motor1.setSpeed(110);
  motor2.setSpeed(110);
}

void loop() {
  Serial.println(analogRead(control));
  if(analogRead(control) >= 300 && analogRead(control) < 500){
    IRL = A1;
    IRR = A2;
  }
  else if(analogRead(control) >=500 && analogRead(control) < 600){
    midFlag = false;
    IRL = A2;
    IRR = A3;
  }
  else if(analogRead(control) >=600 && analogRead(control) < 800){
    midFlag = true;
    Serial.println(digitalRead(IRL));
    Serial.println(digitalRead(IRM));
    Serial.println(digitalRead(IRR));
    delay(10);
    if(digitalRead(IRM) == 1){
      moveL();
    }
    else{
      moveF();
    }
  }
  else if(analogRead(control) >=800 && analogRead(control) < 900){
    midFlag = false;
    IRL = A3;
    IRR = A4;
  }
  else if(analogRead(control) >= 900){
    IRL = A4;
    IRR = A5;
  }
  if(analogRead(control) >= 300 && !midFlag){
    if(digitalRead(IRL) == 0 && digitalRead(IRR) == 0){
      moveF();
    }
    else if(digitalRead(IRL) == 0 && digitalRead(IRR) == 1){
      moveR();
    }
    else if(digitalRead(IRL) == 1 && digitalRead(IRR) == 0){
      moveL();
    }
  }
}

void moveF(){
  Serial.println("RunsF");
  motor1.setSpeed(110);
  motor2.setSpeed(110);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  delay(50);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

void moveR(){
  Serial.println("RunsR");
  motor1.setSpeed(150);
  motor1.run(FORWARD);
  delay(50);
  motor1.run(RELEASE);
}

void moveL(){
  Serial.println("RunsL");
  motor2.setSpeed(150);
  motor2.run(FORWARD);
  delay(50);
  motor2.run(RELEASE);
}
