#include <string.h>
#include "RomanNumeral.h"

typedef enum { false, true } bool;

bool SetRomanNumeral(struct RomanNumeral *romanNumeral, char *romanString) {
  if(strstr(romanString, "II") != NULL) {
    strcpy(romanNumeral->ones, "II");
  }
  else {
    strcpy(romanNumeral->ones, "I");
  }

  strcpy(romanNumeral->tens, "");
  strcpy(romanNumeral->hundreds, "");
  strcpy(romanNumeral->thousands, "");

  return true;
}
