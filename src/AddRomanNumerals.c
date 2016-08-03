#include "RomanNumeral.h"
#include "RomanNumeralUtilities.h"

typedef int (*RomanToArabicConverterFunction)(struct RomanNumeral *);
typedef bool (*ArabicToRomanConverterFunction)(struct RomanNumeral *, int);

bool AddRomanNumerals(struct RomanNumeral *romanSummand1, struct RomanNumeral *romanSummand2,
  struct RomanNumeral *romanSum,
  RomanToArabicConverterFunction romanToArabicConverterFunction,
  ArabicToRomanConverterFunction arabicToRomanConverterFunction) {

  int arabicSummand1 = (*romanToArabicConverterFunction)(romanSummand1);
  int arabicSummand2 = (*romanToArabicConverterFunction)(romanSummand2);

  int arabicSum = arabicSummand1 + arabicSummand2;

  bool isValidRomanNumeral = (*arabicToRomanConverterFunction)(romanSum, arabicSum);

  return isValidRomanNumeral;
}
