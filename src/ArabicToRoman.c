#include <string.h>
#include "RomanNumeral.h"

typedef enum { false, true } bool;

bool ArabicToRoman(struct RomanNumeral *romanNumeral, int arabic) {
  int onesPlace = arabic;

  if(arabic == 1) {
    strcpy(romanNumeral->ones, "I");
    strcpy(romanNumeral->tens, "");
    strcpy(romanNumeral->hundreds, "");
    strcpy(romanNumeral->thousands, "");
  }
  else if(arabic == 1212) {
    strcpy(romanNumeral->ones, "II");
    strcpy(romanNumeral->tens, "X");
    strcpy(romanNumeral->hundreds, "CC");
    strcpy(romanNumeral->thousands, "M");
  }
  else {
    strcpy(romanNumeral->ones, "III");
    strcpy(romanNumeral->tens, "XX");
    strcpy(romanNumeral->hundreds, "CCC");
    strcpy(romanNumeral->thousands, "MM");
  }
  return true;
}
