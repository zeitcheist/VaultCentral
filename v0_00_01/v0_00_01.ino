#include <LiquidCrystal.h>
#include <Keypad.h>

#include "KeypadInput.h"
#include "LCDOutput.h"
#include "Initializer.h"

KeypadInput *keypadInput;
LCDOutput *lcdOutput;

void setup() {
  Initializer initializer;
  
  keypadInput = initializer.initKeypad();
  lcdOutput = initializer.initLCD();
}

void loop() {
  keypadInput->getKey();
  keypadInput->waitForKey();
  
  lcdOutput->clear();
  lcdOutput->home();
  lcdOutput->print("Hello!");
}
