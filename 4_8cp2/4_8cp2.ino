#include <Keypad.h>
#include <SevSeg.h>
SevSeg sevseg;
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
{'7', '4', '1', '0'}, {'8','5','2', 'A'},
{'9', '6', '3', 'B'}, {'C', 'D', 'E', 'F'}
};
byte rowPins[ROWS] = {13, 12, 11, 10};
byte colPins[COLS] = {9, 8, 7, 6};
Keypad keypad =Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS );

void setup(){
byte numDigits = 1;
byte digitPins[] = {17};
byte segmentPins[] = {2,3,4,5,14,15,16,1};
sevseg.begin(COMMON_CATHODE,numDigits,digitPins,segmentPins);
Serial.begin(9600);
}
void loop(){
char key = keypad.getKey(); // 讀取 Keypad的輸入
if (key != NO_KEY){
  Serial.println(key);
  sevseg.setNumber(key-'0',0);
}
sevseg.refreshDisplay();
}
