#include <string.h>
#include "RomanNumeral.h"
#include "RomanSymbolDefinitions.h"
#include "RomanNumeralUtilities.h"

bool ArabicToRoman(struct RomanNumeral *romanNumeral, int arabic) {
  int onesPlace = arabic;

  if(arabic >= 4000 || arabic <= 0) {
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
