# Roman Numeral Calculator Kata in C for Ubuntu Linux

This kata is based on the Roman Numeral Calculator Kata at http://bit.ly/1VfHqlj

## Usage

The Roman Numeral Calculator uses a new data type, called RomanNumeral, to perform validation and calculations.  Roman numeral character strings are converted to be valid RomanNumeral.  RomanNumeral data types are then used in the addition and subtraction routines as well as roman-to-arabic and arabic-to-roman conversion.  Pointers to these conversion functions are used so that the addition and subtraction routines can be unit tested with mocks.  Unit tests as well as integration tests are performed to ensure the proper operation of the code.  The following is a description of the available RomanNumeral-based routines.

###Addition

bool AddRomanNumerals(struct RomanNumeral *romanSummand1, struct RomanNumeral *romanSummand2,
	struct RomanNumeral *romanSum,
	RomanToArabicConverterFunction romanToArabicConverterFunction,
	ArabicToRomanConverterFunction arabicToRomanConverterFunction)

####Input Arguments:
- <b>romanSummand1</b>: First summand.
- <b>summand2Roman</b>: Second summand.
- <b>romanSum</b>: Computed sum in roman numeral format.
- <b>romanToArabicConverterFunction</b>: Roman to arabic conversion function.
- <b>arabicToRomanConverterFunction</b>: Arabic to roman conversion function.

####Returned Value:
- <b>isValidRomanNumeral</b>:  Returns false if result is invalid.

###Subtraction

bool SubtractRomanNumerals(struct RomanNumeral *minuendRoman, struct RomanNumeral *subtrahendRoman,
	struct RomanNumeral *romanDifference,
	RomanToArabicConverterFunction romanToArabicConverterFunction,
	ArabicToRomanConverterFunction arabicToRomanConverterFunction)

####Input Arguments:
- <b>minuendRoman</b>:  Minuend.
- <b>subtrahendRoman</b>:  Subtrahend expected less than the minuend.
- <b>romanDifference</b>: Computed difference.
- <b>romanToArabicConverterFunction</b>: Roman to arabic conversion function.
- <b>arabicToRomanConverterFunction</b>: Arabic to roman conversion function.

####Returned Value:
- <b>isValidRomanNumeral</b>:  Returns false if result is invalid.

###Roman to Arabic Conversion

int RomanToArabic(struct RomanNumeral *romanNumeral)

####Input Arguments:
- <b>romanNumeral</b>:  Roman Numeral.

####Returned Value:
- <b>result</b>:  Arabic result.

###Arabic to Roman Conversion

bool ArabicToRoman(struct RomanNumeral *romanNumeral, int arabic)

####Input Arguments:
- <b>romanNumeral</b>:  Roman Numeral for return value.
- <b>arabic</b>:  Roman Numeral.

####Returned Value:
- <b>isValidRomanNumeral</b>:  Returns false if result is invalid.

###Set Roman Numeral from Roman Numeral Character String

bool SetRomanNumeral(struct RomanNumeral *romanNumeral, char *romanNumeralString)

####Input Arguments:
- <b>romanNumeral</b>:  Roman Numeral for return value.
- <b>romanNumeralString</b>:  Roman Numeral in character string form.

####Returned Value:
- <b>isValidRomanNumeral</b>:  Returns false if result is invalid.

###Get Roman Numeral Character String from RomanNumeral

bool GetRomanNumeralString(struct RomanNumeral *romanNumeral, char *romanNumeralString,
  int romanNumeralStringBufferSize)

####Input Arguments:
- <b>romanNumeral</b>:  Roman Numeral for return value.
- <b>romanNumeralString</b>:  Roman Numeral in character string form.

####Returned Value:
- <b>isValidRomanNumeral</b>:  Returns false if result is invalid.

###More Usage Notes:
- Valid roman numerals supplied or generated must be greater than or equal to I (1) and less than or equal to MMMCMXCIX (3999).

## Requirements to Run
- pkg-config if running outside the Docker.
- Ubuntu Linux 14.04
- The C programming language
- GNU GCC compiler tool chain
- GNU Make
- Check unit testing framework ( https://libcheck.github.io/check/ )
- git

## Requirements to Run Using Docker
- Git
- Docker

## Docker Environment Setup
1. Run shell script to create Docker image as defined in Dockerfile:

		$ ./Dockerbuild.sh

2. Issue the following Docker command to view the available Docker images.

		$ docker images

3. Identify the Docker image with tag "c-kata-14.04-check" from the list to ensure that it was create.
4. Issue the following Docker command to run the image as a Docker container.

		$ docker run -i -t -v <i>'full path to the project on local machine'</i>:/kata/RomanNumeralCalcUbuntuCKata c-kata-14.04-check /bin/bash

5. A bash command shell results from the command.
6. Issue the following command to go to the mounted project folder:

		$ cd /kata/RomanNumeralCalcUbuntuCKata

## Steps to Run
1. To build the application and perform unit tests use command:

		$ make test

2. To build the application, perform unit tests and use valgrind to assess memory usage command:

		$ make testmem
