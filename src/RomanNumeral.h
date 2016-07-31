#ifndef ROMAN_NUMERAL_H
#define ROMAN_NUMERAL_H

#define ROMAN_PLACE_STRING_LENGTH 3

struct RomanNumeral {
  char ones[ROMAN_PLACE_STRING_LENGTH];
  char tens[ROMAN_PLACE_STRING_LENGTH];
  char hundreds[ROMAN_PLACE_STRING_LENGTH];
  char thousands[ROMAN_PLACE_STRING_LENGTH];
};

#endif /* ROMAN_NUMERAL_H */
