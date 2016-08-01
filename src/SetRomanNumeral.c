#include <string.h>
#include "RomanNumeral.h"

#define ROW 4
#define COL 9

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

  int symbolSize[ROW][COL] = {
    {2, 4, 3, 2, 2, 1, 3, 2, 1},
    {0, 0, 0, 0, 0, 1, 3, 2, 1},
    {0, 0, 0, 0, 0, 1, 3, 2, 1},
    {0, 0, 0, 0, 0, 0, 3, 2, 1}
  };
  char *romanSymbols[ROW][COL] = {
    {"IX", "VIII", "VII", "VI", "IV", "V", "III", "II", "I"},
    {" ", " ", " ", " ", " ", "L", "XXX", "XX", "X"},
    {" ", " ", " ", " ", " ", "D", "CCC", "CC", "C"},
    {" ", " ", " ", " ", " ", " ", "MMM", "MM", "M"}
  };
  ClearRomanNumeral(romanNumeral);

  for(i=ROW-1; i>=0; --i) {
    symbolFound = false;
    for(j=0; j<=COL-1 && symbolFound == false; ++j) {
      foundRomanPointer = strstr(shiftingRomanPointer, romanSymbols[i][j]);
      if((foundRomanPointer != NULL) && (shiftingRomanPointer == foundRomanPointer)) {
        symbolFound = true;
        switch(i) {
          case 0:
            strcpy(romanNumeral->ones, romanSymbols[i][j]);
            break;
          case 1:
            strcpy(romanNumeral->tens, romanSymbols[i][j]);
            break;
          case 2:
            strcpy(romanNumeral->hundreds, romanSymbols[i][j]);
            break;
          case 3:
            strcpy(romanNumeral->thousands, romanSymbols[i][j]);
            break;
        }
        shiftingRomanPointer += symbolSize[i][j];
      }
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
