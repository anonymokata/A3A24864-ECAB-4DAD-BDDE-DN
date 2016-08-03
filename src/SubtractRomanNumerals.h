#ifndef SUBTRACT_ROMAN_NUMERALS_H
#define SUBTRACT_ROMAN_NUMERALS_H

#include "RomanNumeral.h"
#include "RomanNumeralUtilities.h"

typedef int (*RomanToArabicConverterFunction)(struct RomanNumeral *);
typedef bool (*ArabicToRomanConverterFunction)(struct RomanNumeral *, int);

bool SubtractRomanNumerals(struct RomanNumeral *minuendRoman, struct RomanNumeral *subtrahendRoman,
  struct RomanNumeral *romanDifference,
  RomanToArabicConverterFunction romanToArabicConverterFunction,
  ArabicToRomanConverterFunction arabicToRomanConverterFunction);

#endif /* SUBTRACT_ROMAN_NUMERALS_H */
