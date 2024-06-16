#include <LiquidCrystal_I2C.h>

#define redPin 9
#define greenPin 10
#define bluePin 11
#define BTN_R 5
#define BTN_G 6 
#define BTN_B 7 
#define POT A3
const int P_MIN = 0;
const int P_MAX = 1023;
int BTN_R_S;
int BTN_G_S;
int BTN_B_S;
int counter1 = 0;
int counter2 = 0;
int counter3 = 0;
int POT_V = 0;
 int R;
 int G;
 int B;
int range;
int range_prev;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void LED (int RV, int GV, int BV)
{
  analogWrite(redPin, RV);
  analogWrite(greenPin, GV);
  analogWrite(bluePin, BV);
}

void button (int BTN, int BTN_S, int& counter, int& color_value, int x, int y)
{
  if( digitalRead(BTN) == LOW)
  {
    delay(200);
    counter++;

  } 
  switch (counter)
  {
    case 0 :
   	
    break;

    case 1 : 
  	color_value = range;
    lcd.setCursor(x,y);
    lcd.print(">");
    
    break;

    case 2 : 
    lcd.clear();
    counter = 0;
    break;
  }
}

void setup() 
{
  lcd.init();
  lcd.backlight();
 Serial.begin(9600);
pinMode(POT, INPUT);
pinMode(redPin, OUTPUT);
pinMode(greenPin, OUTPUT);
pinMode(bluePin, OUTPUT);
pinMode(BTN_R, INPUT_PULLUP);
pinMode(BTN_G, INPUT_PULLUP);
pinMode(BTN_B, INPUT_PULLUP);
}

void loop() 
{
  range = map(POT_V, P_MIN, P_MAX, 0, 255);
  POT_V = analogRead(POT);
  Serial.println(R);
button(BTN_R, BTN_R_S, counter1, R, 0,0);
button(BTN_G, BTN_G_S, counter2, G, 0,1);
button(BTN_B, BTN_B_S, counter3, B, 7,0);
  LED(R,G,B);
 
  lcd.setCursor(1,0);
  lcd.print("R");
  lcd.setCursor(3,0);
  lcd.print(R);
  lcd.setCursor(1,1);
  lcd.print("G");
  lcd.setCursor(3,1);
  lcd.print(G);
  lcd.setCursor(8,0);
  lcd.print("B");
  lcd.setCursor(10,0);
  lcd.print(B);
  if(range != range_prev)
  {
    lcd.clear();
   
  }
  range_prev = range;
}
