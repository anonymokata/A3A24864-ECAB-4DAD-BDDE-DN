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
  bool isRoman = false;
  bool onesSymbolFound = false;
  bool tensSymbolFound = false;
  bool hundredsSymbolFound = false;
  bool thousandsSymbolFound = false;
  int i;
  char *shiftingRomanPointer = romanString;
  char *foundRomanPointer;

  char onesNumberOfSymbols = 9;
  char onesSymbolSize[] = {2, 4, 3, 2, 2, 1, 3, 2, 1};
  char *onesRomanSymbols[] = {"IX", "VIII", "VII", "VI", "IV", "V", "III", "II", "I"};

  char tensNumberOfSymbols = 2;
  char tensSymbolSize[] = {2, 1};
  char *tensRomanSymbols[] = {"XX", "X"};

  char hundredsNumberOfSymbols = 1;
  char hundredsSymbolSize[] = {1};
  char *hundredsRomanSymbols[] = {"C"};

  char thousandsNumberOfSymbols = 1;
  char thousandsSymbolSize[] = {1};
  char *thousandsRomanSymbols[] = {"M"};

  ClearRomanNumeral(romanNumeral);

  for(i=0; i<=thousandsNumberOfSymbols-1 && thousandsSymbolFound == false; ++i) {
    foundRomanPointer = strstr(shiftingRomanPointer, thousandsRomanSymbols[i]);
    if((foundRomanPointer != NULL) && (shiftingRomanPointer == foundRomanPointer)) {
      thousandsSymbolFound = true;
      strcpy(romanNumeral->thousands, thousandsRomanSymbols[i]);
      shiftingRomanPointer += thousandsSymbolSize[i];
    }
  }

  for(i=0; i<=hundredsNumberOfSymbols-1 && hundredsSymbolFound == false; ++i) {
    foundRomanPointer = strstr(shiftingRomanPointer, hundredsRomanSymbols[i]);
    if((foundRomanPointer != NULL) && (shiftingRomanPointer == foundRomanPointer)) {
      hundredsSymbolFound = true;
      strcpy(romanNumeral->hundreds, hundredsRomanSymbols[i]);
      shiftingRomanPointer += hundredsSymbolSize[i];
    }
  }

  for(i=0; i<=tensNumberOfSymbols-1 && tensSymbolFound == false; ++i) {
    foundRomanPointer = strstr(shiftingRomanPointer, tensRomanSymbols[i]);
    if((foundRomanPointer != NULL) && (shiftingRomanPointer == foundRomanPointer)) {
      tensSymbolFound = true;
      strcpy(romanNumeral->tens, tensRomanSymbols[i]);
      shiftingRomanPointer += tensSymbolSize[i];
    }
  }

  for(i=0; i<=onesNumberOfSymbols-1 && onesSymbolFound == false; ++i) {
    foundRomanPointer = strstr(shiftingRomanPointer, onesRomanSymbols[i]);
    if((foundRomanPointer != NULL) && (shiftingRomanPointer == foundRomanPointer)) {
      onesSymbolFound = true;
      strcpy(romanNumeral->ones, onesRomanSymbols[i]);
      shiftingRomanPointer +=  onesSymbolSize[i];
    }
  }

  if(strlen(shiftingRomanPointer) == 0 ) {
    isRoman = true;
  }
  else {
    ClearRomanNumeral(romanNumeral);
  }

  return isRoman;
}
