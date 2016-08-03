test: testRomanNumeral
	./test/TestSetRomanNumeral
	./test/TestRomanToArabic
	./test/TestArabicToRoman
	./test/TestGetRomanNumeralString
	./test/TestAddRomanNumerals

testmem: testRomanNumeral
	valgrind --leak-check=yes ./test/TestSetRomanNumeral
	valgrind --leak-check=yes ./test/TestRomanToArabic
	valgrind --leak-check=yes ./test/TestArabicToRoman
	valgrind --leak-check=yes ./test/TestGetRomanNumeralString
	valgrind --leak-check=yes ./test/TestAddRomanNumerals

testRomanNumeral: .checkmk ./src/SetRomanNumeral.c
	gcc ./test/TestSetRomanNumeral.c ./src/SetRomanNumeral.c \
		-std=c90 -g -O0 $(shell pkg-config --libs --cflags check) \
		-lc -lm -o ./test/TestSetRomanNumeral
	gcc ./test/TestRomanToArabic.c ./src/RomanToArabic.c \
		-std=c90 -g -O0 $(shell pkg-config --libs --cflags check) \
		-lc -lm -o ./test/TestRomanToArabic
	gcc ./test/TestArabicToRoman.c ./src/ArabicToRoman.c \
		-std=c90 -g -O0 $(shell pkg-config --libs --cflags check) \
		-lc -lm -o ./test/TestArabicToRoman
	gcc ./test/TestGetRomanNumeralString.c ./src/GetRomanNumeralString.c \
		-std=c90 -g -O0 $(shell pkg-config --libs --cflags check) \
		-lc -lm -o ./test/TestGetRomanNumeralString
	gcc ./test/TestAddRomanNumerals.c ./src/AddRomanNumerals.c \
		-std=c90 -g -O0 $(shell pkg-config --libs --cflags check) \
		-lc -lm -o ./test/TestAddRomanNumerals


.checkmk: ./test/TestSetRomanNumeral.check ./test/TestRomanToArabic.check ./test/TestArabicToRoman.check
	checkmk ./test/TestSetRomanNumeral.check > ./test/TestSetRomanNumeral.c
	checkmk ./test/TestRomanToArabic.check > ./test/TestRomanToArabic.c
	checkmk ./test/TestArabicToRoman.check > ./test/TestArabicToRoman.c
	checkmk ./test/TestGetRomanNumeralString.check > ./test/TestGetRomanNumeralString.c
	checkmk ./test/TestAddRomanNumerals.check > ./test/TestAddRomanNumerals.c

clean :
	rm -f ./test/TestSetRomanNumeral ./test/TestSetRomanNumeral.c
	rm -f ./test/TestRomanToArabic ./test/TestRomanToArabic.c
	rm -f ./test/TestArabicToRoman ./test/TestArabicToRoman.c
	rm -f ./test/TestGetRomanNumeralString ./test/TestGetRomanNumeralString.c
	rm -f ./test/TestAddRomanNumerals ./test/TestAddRomanNumerals.c
