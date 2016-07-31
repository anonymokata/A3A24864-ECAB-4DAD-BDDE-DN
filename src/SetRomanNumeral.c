#include <string.h>
#include "RomanNumeral.h"

typedef enum { false, true } bool;

static void ClearRomanNumeral(struct RomanNumeral *romanNumeral) {
  strcpy(romanNumeral->ones, "");
  strcpy(romanNumeral->tens, "");
  strcpy(romanNumeral->hundreds, "");
  strcpy(romanNumeral->thousands, "");
}

bool SetRomanNumeral(struct RomanNumeral *romanNumeral, char *romanString) {
  bool isRoman = false;
  bool symbolFound = false;
  int i;

  char numberOfSymbols = 7;
  char *romanSymbols[] = {"VII", "VI", "IV", "V", "III", "II", "I"};

  ClearRomanNumeral(romanNumeral);

  for(i=0; i<=numberOfSymbols-1 && symbolFound == false; ++i) {
    if(strstr(romanString, romanSymbols[i]) != NULL) {
      strcpy(romanNumeral->ones, romanSymbols[i]);
      isRoman = true;
      symbolFound = true;
    }
  }

  return isRoman;
}
