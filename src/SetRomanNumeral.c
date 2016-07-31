#include <string.h>
#include "RomanNumeral.h"

typedef enum { false, true } bool;

bool SetRomanNumeral(struct RomanNumeral *romanNumeral, char *romanString) {
  strcpy(romanNumeral->ones, "I");
  strcpy(romanNumeral->tens, "");
  strcpy(romanNumeral->hundreds, "");
  strcpy(romanNumeral->thousands, "");

  return true;
}
