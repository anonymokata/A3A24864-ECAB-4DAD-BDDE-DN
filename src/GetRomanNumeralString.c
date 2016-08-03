#include <string.h>
#include "RomanNumeral.h"

typedef enum { false, true } bool;

bool GetRomanNumeralString(struct RomanNumeral *romanNumeral, char *romanNumeralString,
  int romanNumeralStringBufferSize) {

  strcpy(romanNumeralString, romanNumeral->thousands);
  strcat(romanNumeralString, romanNumeral->hundreds);
  strcat(romanNumeralString, romanNumeral->tens);
  strcat(romanNumeralString, romanNumeral->ones);

  return true;
}
