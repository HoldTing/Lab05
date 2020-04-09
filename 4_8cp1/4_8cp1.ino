#include <Keypad.h>
const byte ROWS = 4; // 4 Rows
const byte COLS = 4; // 4 Columns
// 定義 Keypad 的按鍵
char keys[ROWS][COLS] = {
{'7', '4', '1', '0'}, {'8','5','2', 'A'},
{'9', '6', '3', 'B'}, {'C', 'D', 'E', 'F'}
};
byte rowPins[ROWS] = {13, 12, 11, 10};
byte colPins[COLS] = {9, 8, 7, 6};

Keypad keypad =
Keypad( makeKeymap(keys), rowPins,
colPins, ROWS, COLS );
void setup(){
Serial.begin(9600);
}
void loop(){
char key = keypad.getKey(); // 讀取 Keypad的輸入
if (key != NO_KEY){
Serial.println(key);
}
}
