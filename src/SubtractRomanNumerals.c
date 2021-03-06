#include "RomanNumeral.h"
#include "RomanNumeralUtilities.h"

typedef int (*RomanToArabicConverterFunction)(struct RomanNumeral *);
typedef bool (*ArabicToRomanConverterFunction)(struct RomanNumeral *, int);

bool SubtractRomanNumerals(struct RomanNumeral *minuendRoman, struct RomanNumeral *subtrahendRoman,
  struct RomanNumeral *romanDifference,
  RomanToArabicConverterFunction romanToArabicConverterFunction,
  ArabicToRomanConverterFunction arabicToRomanConverterFunction) {

  int arabicMinuend = (*romanToArabicConverterFunction)(minuendRoman);
  int arabicSubtrahend = (*romanToArabicConverterFunction)(subtrahendRoman);

  int arabicDifference = arabicMinuend - arabicSubtrahend;

  bool isValidRomanNumeral = (*arabicToRomanConverterFunction)(romanDifference, arabicDifference);

  return isValidRomanNumeral;
}
