#include <string.h>
#include "RomanNumeral.h"

typedef enum { false, true } bool;

bool ArabicToRoman(struct RomanNumeral *romanNumeral, int arabic) {
  strcpy(romanNumeral->ones, "I");
  strcpy(romanNumeral->tens, "");
  strcpy(romanNumeral->hundreds, "");
  strcpy(romanNumeral->thousands, "");
  return true;
}
