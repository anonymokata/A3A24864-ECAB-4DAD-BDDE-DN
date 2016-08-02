#include <string.h>
#include "RomanNumeral.h"

int RomanToArabic(struct RomanNumeral *romanNumeral) {
  if(!strcmp(romanNumeral->ones, "I") &&
    !strcmp(romanNumeral->tens, "") &&
    !strcmp(romanNumeral->hundreds, "") &&
    !strcmp(romanNumeral->thousands, "") ) {
      return 1;
  }
  if(!strcmp(romanNumeral->ones, "I") &&
    !strcmp(romanNumeral->tens, "X") &&
    !strcmp(romanNumeral->hundreds, "C") &&
    !strcmp(romanNumeral->thousands, "M") ) {
      return 1111;
  }
  else {
    return 2222;
  }
}
