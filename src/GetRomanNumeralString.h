#ifndef GET_ROMAN_NUMERAL_STRING_H
#define GET_ROMAN_NUMERAL_STRING_H

#include "RomanNumeral.h"
#include "RomanNumeralUtilities.h"

#define MIN_ROMAN_NUMERAL_STRING_BUFFER_SIZE 21

bool GetRomanNumeralString(struct RomanNumeral *romanNumeral, char *romanNumeralString,
  int romanNumeralStringBufferSize);

#endif /* GET_ROMAN_NUMERAL_STRING_H */
