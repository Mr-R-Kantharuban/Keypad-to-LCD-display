#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {4, 5, 6, 7}; //R1,R2,R3,R4
//connect to the column pinouts of the keypad
byte colPins[COLS] = {8, 9, 10, 11};//C1,C2,C3,C4

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
}
  
void loop(){
  char key = keypad.getKey();  
  if (key){
  lcd.print(key);
  }
}
