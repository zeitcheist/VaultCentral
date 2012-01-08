#include "Communicator.h"

#include <Streaming.h>
#include <Base64.h>
#include <CmdMessenger.h>






Communicator::Communicator(char field_separator, char command_separator, boolean debug) {  
  // init here
  cmdMessenger = &CmdMessenger(Serial, field_separator, command_separator);
  
  // Listen on serial connection for messages from the pc
  Serial.begin(57600);  // Arduino Duemilanove, FTDI Serial
  // Serial.begin(115200); // Arduino Uno, Mega, with AT8u2 USB
  
  if (debug) {
    cmdMessenger->print_LF_CR();   // Make output more readable whilst debugging in Arduino Serial Monitor
  } else {
    cmdMessenger->discard_LF_CR(); // Useful if your terminal appends CR/LF, and you wish to remove them
  }

  
}

void Communicator::send(char *message) {
  Serial.print(message);
}

void Communicator::send(byte cmd, char *message) {
  cmdMessenger->sendCmd(cmd, message);
}

char *Communicator::receive() {
  return "dummy message";
}

void Communicator::check() {
  cmdMessenger->feedinSerialData();
}

void Communicator::sendReady() {
  // In response to ping. We just send a throw-away Acknowledgement to say "im alive"
  cmdMessenger->sendCmd(kACK, "Arduino ready");
}

void Communicator::attachCmdHandlers(messengerCallbackFunction* callbacks)
{
  int i = 0;
  int offset = kSEND_CMDS_END;
  while(callbacks[i])
  {
    cmdMessenger->attach(offset+i, callbacks[i]);
    i++;
  }
}

void Communicator::copyString(char *string, uint8_t size) {
  cmdMessenger->copyString(string, size);
}

uint8_t Communicator::available() {
  return cmdMessenger->available();
}




