#ifndef ROMAN_SYMBOL_DEFINITIONS_H
#define ROMAN_SYMBOL_DEFINITIONS_H

#define ROW 4
#define COL 9

char *romanSymbols[ROW][COL] = {
  {"IX", "VIII", "VII", "VI", "IV", "V", "III", "II", "I"},
  {"XC", "LXXX", "LXX", "LX", "XL", "L", "XXX", "XX", "X"},
  {"CM", "DCCC", "DCC", "DC", "CD", "D", "CCC", "CC", "C"},
  {" ", " ", " ", " ", " ", " ", "MMM", "MM", "M"}
};

#endif /* ROMAN_SYMBOL_DEFINITIONS_H */
