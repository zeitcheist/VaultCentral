#include <LiquidCrystal.h>
#include <Keypad.h>
#include <Streaming.h>
#include <Base64.h>
#include <CmdMessenger.h>

#include "KeypadInput.h"
#include "LCDOutput.h"
#include "Communicator.h"
#include "Initializer.h"

KeypadInput *keypadInput;
LCDOutput *lcdOutput;
Communicator *communicator;

// Commands we send from the PC and want to recieve on the Arduino.
// We must define a callback function in our Arduino program for each entry in the list below vv.
// They start at the address kSEND_CMDS_END defined ^^ above as 004
messengerCallbackFunction messengerCallbacks[] = 
{
  handle1,  // 005
  handle2,  // 006
  NULL
};

void setup() {
  Initializer initializer;
  
  keypadInput = initializer.initKeypad();
  lcdOutput = initializer.initLCD();
  communicator = initializer.initComm();
  
  communicator->attachCmdHandlers(messengerCallbacks);
  
  // tell we're ready
  arduinoReady();
  
}

void loop() {
  // check incoming message
  communicator->check();
  
  
  keypadInput->getKey();
  keypadInput->waitForKey();
  
  lcdOutput->clear();
  lcdOutput->home();
  lcdOutput->print("Hello!");
}

// ------------------ C A L L B A C K  M E T H O D S -------------------------

void handle1()
{
  // Message data is any ASCII bytes (0-255 value). But can't contain the field
  // separator, command separator chars you decide (eg ',' and ';')
  communicator->send(kACK, "bens cmd recieved");
  while ( communicator->available() )
  {
    char buf[350] = { '\0' };
    communicator->copyString(buf, 350);
    if (buf[0])
      communicator->send(kACK, buf);
  }
}

void handle2()
{
}

// ------------------ D E F A U L T  C A L L B A C K S -----------------------

void arduinoReady()
{
  communicator->sendReady();
}

// ------------------ E N D  C A L L B A C K  M E T H O D S ------------------
