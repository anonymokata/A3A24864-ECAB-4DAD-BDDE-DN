#include <string.h>
#include "RomanNumeral.h"

typedef enum { false, true } bool;

#define ROW 4
#define COL 5

char *romanSymbols[ROW][COL] = {
  {"", "I", "II", "III", "IV" },
  {"", "X", "XX", "XXX", "XL" },
  {"", "C", "CC", "CCC", "CD" },
  {"", "M", "MM", "MMM", "" }
};


bool ArabicToRoman(struct RomanNumeral *romanNumeral, int arabic) {
  int onesPlace = arabic;

  if(arabic >= 4000) {
    return false;
  }

	int thousandsDigit = arabic/1000;
	int hundredsDigit = (arabic - thousandsDigit*1000)/100;
	int tensDigit = (arabic - hundredsDigit*100 - thousandsDigit*1000)/10;
	int onesDigit = arabic - tensDigit*10 - hundredsDigit*100 - thousandsDigit*1000;

  strcpy(romanNumeral->thousands, romanSymbols[3][thousandsDigit]);
  strcpy(romanNumeral->hundreds, romanSymbols[2][hundredsDigit]);
  strcpy(romanNumeral->tens, romanSymbols[1][tensDigit]);
  strcpy(romanNumeral->ones, romanSymbols[0][onesDigit]);

  return true;
}
