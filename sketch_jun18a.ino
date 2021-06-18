#include <Keypad.h>

const int ROW_NUM = 4; //four rows
const int COLUMN_NUM = 4; //four columns
int pzPin = 9;
int LEDp = 10;
int RGB1 = A1;
int RGB2 = A2;
int RGB3 = A3;

void RGB_color(int red_light_value, int green_light_value, int blue_light_value);

char keys[ROW_NUM][COLUMN_NUM] = {
  {'D','H','x', 'x'},
  {'C','G','x', 'x'},
  {'B','F','x', 'x'},
  {'A','E','x', 'x'}
};

byte pin_rows[ROW_NUM] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {6, 7, 1, 1}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

void setup(){
  Serial.begin(9600);
  pinMode(RGB1, OUTPUT);
  pinMode(RGB2, OUTPUT);
  pinMode(RGB3, OUTPUT);
  pinMode(LEDp, OUTPUT);
}

void loop(){
  char key = keypad.getKey();

  if (key == 'A'){
    Serial.println(key);
    tone(pzPin, 1000, 500);
  }
  if (key == 'B'){
    Serial.println(key);
    digitalWrite(LEDp, HIGH);
    delay(1000);
  }
  else{
    digitalWrite(LEDp, LOW);
  }
  if (key == 'C'){
    Serial.println(key);
    RGB_color(255,0,0); //RED
  }
  if (key == 'D'){
    Serial.println(key);
    RGB_color(0,255,0); //GREEN
  }
  if (key == 'E'){
    Serial.println(key);
    RGB_color(255,225,125); //RASPBERRY
  }
  if (key == 'F'){
    Serial.println(key);
    RGB_color(0,255,225); //CYAN
  }
  if (key == 'G'){
    Serial.println(key);
    RGB_color(255,0,255); //MAGENTA
  }
  if (key == 'H'){
    Serial.println(key);
    RGB_color(225,255,0); //YELLOW
  }
}

void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(RGB3, red_light_value);
  analogWrite(RGB2, green_light_value);
  analogWrite(RGB1, blue_light_value);
}
