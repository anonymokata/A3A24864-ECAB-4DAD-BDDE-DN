#include <string.h>
#include "RomanNumeral.h"
#include "RomanNumeralUtilities.h"

#define MIN_ROMAN_NUMERAL_STRING_BUFFER_SIZE 21

bool GetRomanNumeralString(struct RomanNumeral *romanNumeral, char *romanNumeralString,
  int romanNumeralStringBufferSize) {

  if(romanNumeralStringBufferSize < MIN_ROMAN_NUMERAL_STRING_BUFFER_SIZE) {
    return false;
  }
  strcpy(romanNumeralString, romanNumeral->thousands);
  strcat(romanNumeralString, romanNumeral->hundreds);
  strcat(romanNumeralString, romanNumeral->tens);
  strcat(romanNumeralString, romanNumeral->ones);

  return true;
}
