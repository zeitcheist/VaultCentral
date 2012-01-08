#include "KeypadInput.h"

#include <Keypad.h>

KeypadInput::KeypadInput(char *userKeymap, byte *rowPins, byte *colPins, byte numRows, byte numCols) {
  
  keypad = &Keypad( userKeymap, rowPins, colPins, numRows, numCols );
  
  initialize();
  
}

void KeypadInput::initialize() {
  // init here
}

char KeypadInput::getKey() {
  return 'a';
}

char KeypadInput::waitForKey() {
  return 'a';
}
