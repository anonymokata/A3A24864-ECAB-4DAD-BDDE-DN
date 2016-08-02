#include <string.h>
#include "RomanNumeral.h"

#define ROW 4
#define COL 4

char *romanSymbols[ROW][COL] = {
  {"", "I", "II", "III" },
  {"", "X", "XX", "XXX" },
  {"", "C", "CC", "CCC" },
  {"", "M", "MM", "MMM" }
};


int RomanToArabic(struct RomanNumeral *romanNumeral) {
  int i;
  int arabic = 0;

  for(i = 0; i < COL; ++i) {
    if(!strcmp(romanNumeral->ones, romanSymbols[0][i]))
      arabic += i;
  }
  for(i = 0; i < COL; ++i) {
    if(!strcmp(romanNumeral->tens, romanSymbols[1][i]))
      arabic += i*10;
  }
  for(i = 0; i < COL; ++i) {
    if(!strcmp(romanNumeral->hundreds, romanSymbols[2][i]))
      arabic += i*100;
  }
  for(i = 0; i < COL; ++i) {
    if(!strcmp(romanNumeral->thousands, romanSymbols[3][i]))
      arabic += i*1000;
  }

  return arabic;
}
