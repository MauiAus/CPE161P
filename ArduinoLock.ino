#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 2, 16);

const int ROW_NUM = 4;
const int COLUMN_NUM = 4;
int pzPin = 11;

Servo toggle;

char keys[ROW_NUM][COLUMN_NUM] = {
  {'A','B','D', 'C'},
  {'E','F','1', '0'},
  {'2','3','5', '4'},
  {'6','7','9', '8'}
};

char d1 = '*';
char d2 = '*';
char d3 = '*';
char d4 = '*';
char d5 = '*';
char d6 = '*';

char c1 = 'C';
char c2 = 'D';
char c3 = 'E';
char c4 = '1';
char c5 = '6';
char c6 = '1';

int ctr = 0;

int lockT = 0;

bool check = false;
bool lflag = false;

byte pin_rows[ROW_NUM] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {6, 7, 8, 9}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  toggle.attach(10);
  toggle.write(180);
  lcd.begin();
  lcd.setCursor (0,0);
  lcd.print ("ARDUINO LOCK");
  lcd.setCursor (0,1);
  lcd.print ("MARK PAGARIGAN");
  delay (2000);
  lcd.setCursor(0,1);
  lcd.print ("              ");
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = keypad.getKey();
  Serial.print(key);
  printLCD();
  openV(check);
  if(key != 0){
    switch(ctr){
      case(0):
        d1 = key;
        ctr++;
      break;
      case(1):
        d2 = key;
        ctr++;
      break;
      case(2):
        d3 = key;
        ctr++;
      break;
      case(3):
        d4 = key;
        ctr++;
      break;
      case(4):
        d5 = key;
        ctr++;
      break;
      case(5):
        d6 = key;
        ctr = 0;
        delay(200);
        checkPass();
      break;
    }
  }
  
}

void openV(bool x){
  if(x){
    lcd.noCursor();
    toggle.write(90);
    delay(lockT * 1000);
    delay(3000);
    toggle.write(180);
    resetPass();
    check = false;
  }
}

void lockTime(){
  while(!lflag){
    char key = keypad.getKey();
    lcd.setCursor(0,0);
    lcd.print("Extend unlock?: ");
    if(key != 0){
      lcd.setCursor(0,1);
      switch(key){
        case('1'):
          lcd.print(key);
          lcd.print(" second");
          lockT = 1;
        break;
        case('2'):
          lcd.print(key);
          lcd.print(" seconds");
          lockT = 2;
        break;
        case('3'):
          lcd.print(key);
          lcd.print(" seconds");
          lockT = 3;
        break;
        case('4'): 
          lcd.print(key);
          lcd.print(" seconds");
          lockT = 4;
        break;
        case('5'):
          lcd.print(key);
          lcd.print(" seconds");
          lockT = 5;
        break;
        case('6'):
          lcd.print(key);
          lcd.print(" seconds");
          lockT = 6;
        break;
        case('7'):
          lcd.print(key);
          lcd.print(" seconds");
          lockT = 7;
        break;
        case('8'):
          lcd.print(key);
          lcd.print(" seconds");
          lockT = 8;
        break;
        case('9'):
          lcd.print(key);
          lcd.print(" seconds");
          lockT = 9;
        break;
        default:
          lcd.print("No");
          lockT = 0;
        break;
      }
      delay(1000);
      lcd.setCursor(0,1);
      lcd.print("             ");
      lflag = true;
    }
  }
  lflag = false;
}

void checkPass(){
  printCode();
  if (d1 == c1 && d2 == c2 && d3 == c3 && d4 == c4 && d5 == c5 && d6 == c6)
  {
    Serial.print("Correct");
    printCheck(true);
    lockTime();
    check = true;
    delay(1000);
  }
  else
  {
    Serial.print("Invalid");
    tone(pzPin, 1000, 500);
    printCheck(false);
    resetPass();
  }
}

void resetPass(){
  d1 = '*';
  d2 = '*';
  d3 = '*';
  d4 = '*';
  d5 = '*';
  d6 = '*';
}

void printLCD(){
  lcd.setCursor(0,0);
  lcd.print("Enter Passcode: ");
  lcd.setCursor(0,1);
  lcd.print(d1);
  lcd.print(d2);
  lcd.print(d3);
  lcd.print(d4);
  lcd.print(d5);
  lcd.print(d6);
}

void printCheck(bool x){
  if(x){
    lcd.setCursor(0,1);
    lcd.print("ACCESS GRANTED");
  }
  else{
    lcd.setCursor(0,1);
    lcd.print("ACCESS DENIED");
  }
  delay(1000);
  resetPass();
  lcd.setCursor(0,1);
  lcd.print("               ");
}

void printCode(){
  Serial.print(d1);
  Serial.print(d2);
  Serial.print(d3);
  Serial.print(d4);
  Serial.print(d5);
  Serial.print(d6);
  Serial.print("\n");
}
