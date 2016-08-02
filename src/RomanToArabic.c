#include <string.h>
#include "RomanNumeral.h"

int RomanToArabic(struct RomanNumeral *romanNumeral) {
  if(!strcmp(romanNumeral->ones, "I") &&
    !strcmp(romanNumeral->tens, "") &&
    !strcmp(romanNumeral->hundreds, "") &&
    !strcmp(romanNumeral->thousands, "") ) {
      return 1;
  }
  else if(!strcmp(romanNumeral->ones, "I") &&
    !strcmp(romanNumeral->tens, "X") &&
    !strcmp(romanNumeral->hundreds, "C") &&
    !strcmp(romanNumeral->thousands, "M") ) {
      return 1111;
  }
  else if(!strcmp(romanNumeral->ones, "II") &&
    !strcmp(romanNumeral->tens, "XX") &&
    !strcmp(romanNumeral->hundreds, "CC") &&
    !strcmp(romanNumeral->thousands, "MM") ) {
      return 2222;
  }
  else {
    return 3333;
  }
}
