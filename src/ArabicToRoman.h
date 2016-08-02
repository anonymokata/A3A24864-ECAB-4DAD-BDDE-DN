#ifndef ARABIC_TO_ROMAN_H
#define ARABIC_TO_ROMAN_H

#include "RomanNumeral.h"

typedef enum { false, true } bool;

bool ArabicToRoman(struct RomanNumeral *romanNumeral, int arabic);

#endif /* ARABIC_TO_ROMAN_H */
