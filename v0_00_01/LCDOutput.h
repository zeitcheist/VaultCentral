#ifndef LCD_OUTPUT_H
#define LCD_OUTPUT_H

// Arduino versioning.
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"	// for digitalRead, digitalWrite, etc
#else
#include "WProgram.h"
#endif

#include <inttypes.h>
#include <LiquidCrystal.h>

class LCDOutput {
public:
  LCDOutput(uint8_t rs, uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3, uint8_t numCols, uint8_t numRows);
  
  void clear();
  void home();
  
  void print(char *str);
  
  void scrollLeft();
  void scrollRight();
  
  void setCursor(uint8_t, uint8_t); 

private:
	
  LiquidCrystal *lcd;
  
};

#endif
