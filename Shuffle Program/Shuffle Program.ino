/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

// include the library code:
#include <LiquidCrystal.h>


// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 2, en = 3, d4 = 6, d5 = 7, d6 = 8, d7 = 9;
const int buttonPin = 4;  // the number of the pushbutton pin
int buttonState = 0;  // variable for reading the pushbutton status
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte customChar1[8] = {
    B01100,
  B01100,
  B00101,
  B11111,
  B10100,
  B00100,
  B01010,
  B10001
};
byte customChar2[8] = {
      B00110,
  B00110,
  B10100,
  B11111,
  B00101,
  B00100,
  B01010,
  B10001
};



uint8_t data[] = {0, 1, 2, 3};

void swapEntries(byte a, byte b)
{
  byte temp = data[a];
  data[a] = data[b];
  data[b] = temp;
}

void printData()
{
  
    for(int i = 0; i < 4; i++)
    {
      lcd.setCursor(i, 1);
      lcd.println(data[i]);
    }
}


void printChar1(int b)
{
      lcd.createChar(0, customChar1);
      lcd.setCursor(b, 1);
      lcd.write((byte)0);
}

void printChar2(int a)
{
      
      lcd.createChar(0, customChar2);
      lcd.setCursor(a, 1);
      lcd.write((byte)0);
}

void displayfigures1()
{
      
    lcd.setCursor(1, 1);
    printChar2(1);
    lcd.setCursor(4, 1);
    printChar2(4);
    lcd.setCursor(12, 1);
    printChar1(11);
    lcd.setCursor(15, 1);
    printChar1(14);
}

void displayfigures2()
{ 
    lcd.setCursor(1, 1);
    printChar1(1);
    lcd.setCursor(4, 1);
    printChar1(4);
    lcd.setCursor(12, 1);
    printChar2(11);
    lcd.setCursor(15, 1);
    printChar2(14);
}

void setup() {
    // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  
  lcd.begin(16, 2);
    lcd.home();
    lcd.print("TOUCH BUTTON"); 

//for (int i = 0; i < 10; i++) swapEntries(random(0, 4), random(0, 4)); // perform 10 swaps
//lcd.home();
//lcd.print("YELLOW     BLACK");
//
//  for (int i = 0; i < 10; i++) swapEntries(random(0, 4), random(0, 4)); // perform 10 swaps
//
//lcd.setCursor(0, 1);
//lcd.print(data[0]);
//lcd.setCursor(3, 1);
//lcd.print(data[1]);
//lcd.setCursor(12, 1);
//lcd.print(data[2]);
//lcd.setCursor(15, 1);
//lcd.print(data[3]);


}

void loop() {
//  for (int i = 0; i < 10; i++) swapEntries(random(0, 4), random(0, 4)); // perform 10 swaps
 
buttonState = digitalRead(buttonPin);
if (buttonState == HIGH) {
    for (int i; buttonState == HIGH; i++)  {
    swapEntries(random(0, 4), random(0, 4)); // perform 10 swaps
    buttonState = digitalRead(buttonPin);
    }
    lcd.home();
    lcd.print("YELLOW     BLACK");
    
    lcd.setCursor(0, 1);
    lcd.print(data[0]);
    lcd.setCursor(3, 1);
    lcd.print(data[1]);
    lcd.setCursor(12, 1);
    lcd.print(data[2]);
    lcd.setCursor(15, 1);
    lcd.print(data[3]);

    for (int i = 0; i < 30; i++) {
    delay(300);
    displayfigures2();
    delay(300);
    displayfigures1();
    }
    delay(20000);
    lcd.clear();
    lcd.home();
    lcd.print("TOUCH BUTTON"); 
  
    }
    else
    {

    }


  //printChar(customChar2);
  
 // printChar1


  
}


