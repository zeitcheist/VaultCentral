#ifndef INITIALIZER_H
#define INITIALIZER_H

// Arduino versioning.
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"	// for digitalRead, digitalWrite, etc
#else
#include "WProgram.h"
#endif

#include <inttypes.h>

class Initializer {
public:
  Initializer();
  
  KeypadInput* initKeypad();
  LCDOutput* initLCD();

};

Initializer::Initializer() {
  
}

KeypadInput* Initializer::initKeypad() {
  char keys[4][4] = {
      {'1','2','3','A'},
      {'4','5','6','B'},
      {'7','8','9','C'},
      {'*','0','#','D'}
  };
  
  byte rowPins[4] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
  byte colPins[4] = {9, 8, 7, 6}; //connect to the column pinouts of the keypad
  
  KeypadInput *keypadInput = &KeypadInput( makeKeymap(keys), rowPins, colPins, 4, 4 );
  
  return keypadInput;
}

LCDOutput* Initializer::initLCD() {
  uint8_t pinRS = 12;
  uint8_t pinEN = 11;
  uint8_t pinD0 = 16;
  uint8_t pinD1 = 15;
  uint8_t pinD2 = 14;
  uint8_t pinD3 = 13;
    
  uint8_t numCols = 16;
  uint8_t numRows = 2;
  
  LCDOutput *lcdOutput = &LCDOutput(pinRS, pinEN, pinD0, pinD1, pinD2, pinD3, numCols, numRows);
  
  return lcdOutput;
}

#endif
