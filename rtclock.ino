int da1 = 3;
int da2 = 4;
int da3 = 5;
int da4 = 6;
int da5 = 7;
int da6 = 8;

int pinA = 11;
int pinB = 12;
int pinC = 13;
int pinD = A0;
int pinE = A1;
int pinF = A2;
int pinG = 2;

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
void d5(int x);
void d6(int x);
void addSec();

int d1val = 0;
int d2val = 5;
int d3val = 7;
int d4val = 3;
int d5val = 3;
int d6val = 0;

int ms = 0;
int t = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinA,OUTPUT);
  pinMode(pinB,OUTPUT);
  pinMode(pinC,OUTPUT);
  pinMode(pinD,OUTPUT);
  pinMode(pinE,OUTPUT);
  pinMode(pinF,OUTPUT);
  pinMode(pinG,OUTPUT);
  pinMode(da1,OUTPUT);
  pinMode(da2,OUTPUT);
  pinMode(da3,OUTPUT);
  pinMode(da4,OUTPUT);
  pinMode(da5,OUTPUT);
  pinMode(da6,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  d1(d1val);
  d2(d2val);
  d3(d3val);
  d4(d4val);
  d5(d5val);
  d6(d6val);
  addSec();
}

void incTime(){
  d1val++;
  if(d1val >= 10){
    d2val++;
    d1val = 0;
  }
  if(d2val >= 6){
    d3val++;
    d2val = 0;
  }
  if(d3val >= 10){
    d4val++;
    d3val = 0;
  }
  if(d4val >= 6){
    d5val++;
    d4val = 0;
  }
  if(d6val < 2)
  {
    if(d5val >= 10){
      d6val++;
      d5val = 0;
    }
  }
  else
  {
    if(d5val >= 4){
      d6val = 0;
      d5val = 0;
    }   
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
  digitalWrite(da1,LOW);
  digitalWrite(da2,HIGH);
  digitalWrite(da3,HIGH);
  digitalWrite(da4,HIGH);
  digitalWrite(da5,HIGH);
  digitalWrite(da6,HIGH);
  retNum(x);
  delay(2);
  
}
void d2(int x){
  digitalWrite(da1,HIGH);
  digitalWrite(da2,LOW);
  digitalWrite(da3,HIGH);
  digitalWrite(da4,HIGH);
  digitalWrite(da5,HIGH);
  digitalWrite(da6,HIGH);
  retNum(x);
  delay(2);
  ms+=2;
}
void d3(int x){
  digitalWrite(da1,HIGH);
  digitalWrite(da2,HIGH);
  digitalWrite(da3,LOW);
  digitalWrite(da4,HIGH);
  digitalWrite(da5,HIGH);
  digitalWrite(da6,HIGH);
  retNum(x);
  delay(2);
  ms+=2;
}
void d4(int x){
  digitalWrite(da1,HIGH);
  digitalWrite(da2,HIGH);
  digitalWrite(da3,HIGH);
  digitalWrite(da4,LOW);
  digitalWrite(da5,HIGH);
  digitalWrite(da6,HIGH);
  retNum(x);
  delay(2);
  ms+=2;
}
void d5(int x){
  digitalWrite(da1,HIGH);
  digitalWrite(da2,HIGH);
  digitalWrite(da3,HIGH);
  digitalWrite(da4,HIGH);
  digitalWrite(da5,LOW);
  digitalWrite(da6,HIGH);
  retNum(x);
  delay(2);
  ms+=2;
}
void d6(int x){
  digitalWrite(da1,HIGH);
  digitalWrite(da2,HIGH);
  digitalWrite(da3,HIGH);
  digitalWrite(da4,HIGH);
  digitalWrite(da5,HIGH);
  digitalWrite(da6,LOW);
  retNum(x);
  delay(2);
  ms+=2;
}

void addSec(){
  if(ms >= 810){
    t++;
    ms = 0;
    incTime();
    Serial.println(t);
  }
}
