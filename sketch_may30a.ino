int SW1 = 0;
int SW2 = 0;

int inPin1 = 2;
int inPin2 = 3;

int opA = 4;
int opB = 5;
int opC = 6;
int opD = 7;

int pinA = A0;
int pinB = 13;
int pinC = 12;
int pinD = 11;
int pinE = 10;
int pinF = 9;
int pinG = 8;

void zero();
void one();
void two();
void three();
void four();
void five();
void six();
void seven();
void eight();
void nine();

void retNum(int x);

void d1(int x);
void d2(int x);
void d3(int x);
void d4(int x);
void addSec();

int d1val = 0;
int d2val = 0;
int d3val = 0;
int d4val = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinA,OUTPUT);
  pinMode(pinB,OUTPUT);
  pinMode(pinC,OUTPUT);
  pinMode(pinD,OUTPUT);
  pinMode(pinE,OUTPUT);
  pinMode(pinF,OUTPUT);
  pinMode(pinG,OUTPUT);
  pinMode(opA,OUTPUT);
  pinMode(opB,OUTPUT);
  pinMode(opC,OUTPUT);
  pinMode(opD,OUTPUT);
  pinMode(inPin1,INPUT);
  pinMode(inPin2,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  SW1 = digitalRead(inPin1);
  SW2 = digitalRead(inPin2);
  d1(d1val);
  d2(d2val);
  d3(d3val);
  d4(d4val);
  if(SW1 == HIGH){
    delay(1000);
    upL();
  }

  if(SW2 == HIGH){
    delay(1000);
    upR();
  }

}

void upL(){
  d2val++;
  if(d2val == 10){
    d1val++;
    d2val = 0;
  }
  if(d1val == 10){
    d1val = 0;
  }
}

void upR(){
  d4val++;
  if(d4val == 10){
    d3val++;
    d4val = 0;
  }
  if(d3val == 10){
    d3val = 0;
  }
}

void zero(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, LOW);
}

void one(){
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);
}
void two(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);  
}
void three(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH); 
}
void four(){
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);    
}
void five(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH); 
}
void six(){
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH); 
}
void seven(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW); 
}
void eight(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH); 
}
void nine(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH); 
}

void retNum(int x){
  switch (x)
  {
  case 1:
    one();
    break;
  case 2:
    two();
    break;
  case 3:
    three();
    break;
  case 4:
    four();
    break;
  case 5:
    five();
    break;
  case 6:
    six();
    break;
  case 7:
    seven();
    break;
  case 8:
    eight();
    break;
  case 9:
    nine();
    break;
  case 0:
    zero();
    break;
  default:
    break;
  }
}

void d1(int x){
  digitalWrite(opA,LOW);
  digitalWrite(opB,HIGH);
  digitalWrite(opC,HIGH);
  digitalWrite(opD,HIGH);
  retNum(x);
  delay(2);
}
void d2(int x){
  digitalWrite(opA,HIGH);
  digitalWrite(opB,LOW);
  digitalWrite(opC,HIGH);
  digitalWrite(opD,HIGH);
  retNum(x);
  delay(2);
}
void d3(int x){
  digitalWrite(opA,HIGH);
  digitalWrite(opB,HIGH);
  digitalWrite(opC,LOW);
  digitalWrite(opD,HIGH);
  retNum(x);
  delay(2);
}
void d4(int x){
  digitalWrite(opA,HIGH);
  digitalWrite(opB,HIGH);
  digitalWrite(opC,HIGH);
  digitalWrite(opD,LOW);
  retNum(x);
  delay(2);
}
