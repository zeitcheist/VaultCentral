#include "LCDOutput.h"


LCDOutput::LCDOutput(uint8_t rs, uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3, uint8_t numCols, uint8_t numRows) {
  
  lcd = &LiquidCrystal(rs, enable, d0, d1, d2, d3);
  lcd->begin(numCols, numRows);
  
}

void LCDOutput::clear() {
  lcd->clear();
}

void LCDOutput::home() {
  lcd->home();
}

void LCDOutput::print(char *str) {
  lcd->print(str);
}

void LCDOutput::scrollLeft() {
  lcd->scrollDisplayLeft();
}

void LCDOutput::scrollRight() {
  lcd->scrollDisplayRight();
}

void LCDOutput::setCursor(uint8_t col, uint8_t row) {
  lcd->setCursor(col, row);
}
