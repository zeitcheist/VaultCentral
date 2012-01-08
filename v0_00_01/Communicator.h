

#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H

// Arduino versioning.
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"	// for digitalRead, digitalWrite, etc
#else
#include "WProgram.h"
#endif

#include <Streaming.h>
#include <Base64.h>
#include <CmdMessenger.h>

// ------------------ C M D  L I S T I N G ( T X / R X ) ---------------------

// Commands we send from the Arduino to be received on the PC
enum
{
  kCOMM_ERROR    = 000, // Lets Arduino report serial port comm error back to the PC (only works for some comm errors)
  kACK           = 001, // Arduino acknowledges cmd was received
  kARDUINO_READY = 002, // After opening the comm port, send this cmd 02 from PC to check arduino is ready
  kERR           = 003, // Arduino reports badly formatted cmd, or cmd not recognised

  // Now we can define many more 'send' commands, coming from the arduino -> the PC
  kMSG           = 004,
  // For the above commands, we just call cmdMessenger.sendCmd() anywhere we want in our Arduino program.

  kSEND_CMDS_END, // Mustnt delete this line
};

class Communicator {
public:
  Communicator(char field_separator, char command_separator, boolean debug=false);
  CmdMessenger* cmdMessenger;
  
  void send(char *message);
  void send(byte cmd, char* message);
  char *receive();
  void check();
  
  void sendReady();
  void copyString(char *string, uint8_t size);
  uint8_t available();
  
  void attachCmdHandlers(messengerCallbackFunction* callbacks);
  
private:
  
  
};

#endif
