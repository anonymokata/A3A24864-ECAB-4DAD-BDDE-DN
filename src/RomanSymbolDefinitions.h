#ifndef ROMAN_SYMBOL_DEFINITIONS_H
#define ROMAN_SYMBOL_DEFINITIONS_H

#define ROW 4
#define COL 10

static char *romanSymbols[ROW][COL] = {
  {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
  {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },
  {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" },
  {"", "M", "MM", "MMM", " ", " ", " ", " ", " ", " " }
};

#endif /* ROMAN_SYMBOL_DEFINITIONS_H */
