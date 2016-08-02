#include <string.h>
#include "RomanNumeral.h"
#include "RomanSymbolDefinitions.h"

static int romanSymbolLength[] = {0, 1, 2, 3, 2, 1, 2, 3, 4, 2};
static int symbolSearchOrder[COL] = {0, 9, 8, 7, 6, 4, 5, 3, 2, 1};

typedef enum { false, true } bool;

static void ClearRomanNumeral(struct RomanNumeral *romanNumeral) {
  strcpy(romanNumeral->ones, "");
  strcpy(romanNumeral->tens, "");
  strcpy(romanNumeral->hundreds, "");
  strcpy(romanNumeral->thousands, "");
}

bool SetRomanNumeral(struct RomanNumeral *romanNumeral, char *romanString) {
  bool isRoman = false;
  bool symbolFound = false;
  int i, j;
  char *shiftingRomanPointer = romanString;
  char *foundRomanPointer;

  ClearRomanNumeral(romanNumeral);

  for(i=ROW-1; i>=0; --i) {
    symbolFound = false;
    for(j=1; j<=COL-1 && symbolFound == false; ++j) {
      foundRomanPointer = strstr(shiftingRomanPointer, romanSymbols[i][symbolSearchOrder[j]]);
      if((foundRomanPointer != NULL) && (shiftingRomanPointer == foundRomanPointer)) {
        symbolFound = true;

        switch(i) {
          case 0:
            strcpy(romanNumeral->ones, romanSymbols[i][symbolSearchOrder[j]]);
            break;
          case 1:
            strcpy(romanNumeral->tens, romanSymbols[i][symbolSearchOrder[j]]);
            break;
          case 2:
            strcpy(romanNumeral->hundreds, romanSymbols[i][symbolSearchOrder[j]]);
            break;
          case 3:
            strcpy(romanNumeral->thousands, romanSymbols[i][symbolSearchOrder[j]]);
            break;
        }
        shiftingRomanPointer += romanSymbolLength[symbolSearchOrder[j]];
      }
    }
  }

  if(strlen(shiftingRomanPointer) == 0) {
    isRoman = true;
  }
  else {
    ClearRomanNumeral(romanNumeral);
  }

  return isRoman;
}
