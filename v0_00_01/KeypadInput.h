#ifndef KEYPAD_INPUT_H
#define KEYPAD_INPUT_H

// Arduino versioning.
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"	// for digitalRead, digitalWrite, etc
#else
#include "WProgram.h"
#endif

#include <Keypad.h>

class KeypadInput {
public:
  KeypadInput(char *userKeymap, byte *row, byte *col, byte numRows, byte numCols);
  
  char getKey();
  char waitForKey();

private:
  void initialize();
	
  Keypad *keypad;
  
};

#endif
