#include <string.h>
#include "RomanNumeral.h"

void GetRomanNumeralString(struct RomanNumeral *romanNumeral, char *romanString) {
  strcpy(romanString, romanNumeral->thousands);
  strcat(romanString, romanNumeral->hundreds);
  strcat(romanString, romanNumeral->tens);
  strcat(romanString, romanNumeral->ones);
}
