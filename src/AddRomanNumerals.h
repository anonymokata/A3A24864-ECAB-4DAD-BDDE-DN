#ifndef ADD_ROMAN_NUMERALS_H
#define ADD_ROMAN_NUMERALS_H

#include "RomanNumeral.h"
#include "RomanNumeralUtilities.h"

typedef int (*RomanToArabicConverterFunction)(struct RomanNumeral *);
typedef bool (*ArabicToRomanConverterFunction)(struct RomanNumeral *, int);

bool AddRomanNumerals(struct RomanNumeral *romanSummand1, struct RomanNumeral *romanSummand2,
  struct RomanNumeral *romanSum,
  RomanToArabicConverterFunction romanToArabicConverterFunction,
  ArabicToRomanConverterFunction arabicToRomanConverterFunction);

#endif /* ADD_ROMAN_NUMERALS_H */
