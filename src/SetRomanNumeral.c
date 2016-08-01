#include <string.h>
#include "RomanNumeral.h"

typedef enum { false, true } bool;

static void ClearRomanNumeral(struct RomanNumeral *romanNumeral) {
  strcpy(romanNumeral->ones, "");
  strcpy(romanNumeral->tens, "");
  strcpy(romanNumeral->hundreds, "");
  strcpy(romanNumeral->thousands, "");
}

bool SetRomanNumeral(struct RomanNumeral *romanNumeral, char *romanString) {
  bool isRoman = true;
  bool onesSymbolFound = false;
  bool tensSymbolFound = false;
  int i;
  char *shiftingRomanPointer = romanString;
  char *foundRomanPointer;

  char onesNumberOfSymbols = 9;
  char onesSymbolSize[] = {2, 4, 3, 2, 2, 1, 3, 2, 1};
  char *onesRomanSymbols[] = {"IX", "VIII", "VII", "VI", "IV", "V", "III", "II", "I"};

  char tensNumberOfSymbols = 1;
  char tensSymbolSize[] = {1};
  char *tensRomanSymbols[] = {"X"};

  ClearRomanNumeral(romanNumeral);

  for(i=0; i<=tensNumberOfSymbols-1 && tensSymbolFound == false; ++i) {
    foundRomanPointer = strstr(shiftingRomanPointer, tensRomanSymbols[i]);
    if(foundRomanPointer != NULL) {
      tensSymbolFound = true;
      if(shiftingRomanPointer == foundRomanPointer) {
        strcpy(romanNumeral->tens, tensRomanSymbols[i]);
        shiftingRomanPointer = shiftingRomanPointer + tensSymbolSize[i];
      }
      else {
        isRoman = false;
      }
    }
  }

  for(i=0; i<=onesNumberOfSymbols-1 && onesSymbolFound == false; ++i) {
    foundRomanPointer = strstr(shiftingRomanPointer, onesRomanSymbols[i]);
    if(foundRomanPointer != NULL) {
      onesSymbolFound = true;
      if(shiftingRomanPointer == foundRomanPointer) {
        strcpy(romanNumeral->ones, onesRomanSymbols[i]);
      }
      else {
        isRoman = false;
      }
    }
  }
  if(onesSymbolFound == false && tensSymbolFound == false )
    isRoman = false;

  return isRoman;
}
