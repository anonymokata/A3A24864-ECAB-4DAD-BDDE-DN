#include <string.h>
#include "RomanNumeral.h"

typedef enum { false, true } bool;

bool SetRomanNumeral(struct RomanNumeral *romanNumeral, char *romanString) {
  bool isRoman = false;

  if(strstr(romanString, "IV") != NULL) {
    strcpy(romanNumeral->ones, "IV");
    isRoman = true;
  }
  else if(strstr(romanString, "III") != NULL) {
    strcpy(romanNumeral->ones, "III");
    isRoman = true;
  }
  else if(strstr(romanString, "II") != NULL) {
    strcpy(romanNumeral->ones, "II");
    isRoman = true;
  }
  else if(strstr(romanString, "I") != NULL) {
    strcpy(romanNumeral->ones, "I");
    isRoman = true;
  } else {
    strcpy(romanNumeral->ones, "");
  }

  strcpy(romanNumeral->tens, "");
  strcpy(romanNumeral->hundreds, "");
  strcpy(romanNumeral->thousands, "");

  return isRoman;
}
