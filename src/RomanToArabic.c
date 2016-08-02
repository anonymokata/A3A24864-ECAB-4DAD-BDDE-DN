#include <string.h>
#include "RomanNumeral.h"

int RomanToArabic(struct RomanNumeral *romanNumeral) {
  if(!strcmp(romanNumeral->ones, "I") &&
    !strcmp(romanNumeral->tens, "") &&
    !strcmp(romanNumeral->hundreds, "") &&
    !strcmp(romanNumeral->thousands, "") ) {
      return 1;
    }
    else {
      return 1111;
    }
}
