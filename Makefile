test: testRomanNumeral
	./test/TestSetRomanNumeral
	./test/TestRomanToArabic
	./test/TestArabicToRoman
	./test/TestGetRomanNumeralString
	./test/TestAddRomanNumerals
	./test/TestSubtractRomanNumerals
	./test/TestIntegrationAddRomanNumerals
	./test/TestIntegrationSubtractRomanNumerals
	./test/TestIntegrationOfAddAndSubtractRomanNumerals

testmem: testRomanNumeral
	valgrind --leak-check=yes ./test/TestSetRomanNumeral
	valgrind --leak-check=yes ./test/TestRomanToArabic
	valgrind --leak-check=yes ./test/TestArabicToRoman
	valgrind --leak-check=yes ./test/TestGetRomanNumeralString
	valgrind --leak-check=yes ./test/TestAddRomanNumerals
	valgrind --leak-check=yes ./test/TestSubtractRomanNumerals
	valgrind --leak-check=yes ./test/TestIntegrationAddRomanNumerals
	valgrind --leak-check=yes ./test/TestIntegrationSubtractRomanNumerals
	valgrind --leak-check=yes ./test/TestIntegrationOfAddAndSubtractRomanNumerals

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
	gcc ./test/TestSubtractRomanNumerals.c ./src/SubtractRomanNumerals.c \
		-std=c90 -g -O0 $(shell pkg-config --libs --cflags check) \
		-lc -lm -o ./test/TestSubtractRomanNumerals
	gcc ./test/TestIntegrationAddRomanNumerals.c \
		./src/AddRomanNumerals.c \
		./src/SetRomanNumeral.c \
		./src/GetRomanNumeralString.c \
		./src/ArabicToRoman.c \
		./src/RomanToArabic.c \
		-std=c90 -g -O0 $(shell pkg-config --libs --cflags check) \
		-lc -lm -o ./test/TestIntegrationAddRomanNumerals
	gcc ./test/TestIntegrationSubtractRomanNumerals.c \
		./src/SubtractRomanNumerals.c \
		./src/SetRomanNumeral.c \
		./src/GetRomanNumeralString.c \
		./src/ArabicToRoman.c \
		./src/RomanToArabic.c \
		-std=c90 -g -O0 $(shell pkg-config --libs --cflags check) \
		-lc -lm -o ./test/TestIntegrationSubtractRomanNumerals
	gcc ./test/TestIntegrationOfAddAndSubtractRomanNumerals.c \
		./src/AddRomanNumerals.c \
		./src/SubtractRomanNumerals.c \
		./src/SetRomanNumeral.c \
		./src/GetRomanNumeralString.c \
		./src/ArabicToRoman.c \
		./src/RomanToArabic.c \
		-std=c90 -g -O0 $(shell pkg-config --libs --cflags check) \
		-lc -lm -o ./test/TestIntegrationOfAddAndSubtractRomanNumerals

.checkmk: ./test/TestSetRomanNumeral.check ./test/TestRomanToArabic.check ./test/TestArabicToRoman.check
	checkmk ./test/TestSetRomanNumeral.check > ./test/TestSetRomanNumeral.c
	checkmk ./test/TestRomanToArabic.check > ./test/TestRomanToArabic.c
	checkmk ./test/TestArabicToRoman.check > ./test/TestArabicToRoman.c
	checkmk ./test/TestGetRomanNumeralString.check > ./test/TestGetRomanNumeralString.c
	checkmk ./test/TestAddRomanNumerals.check > ./test/TestAddRomanNumerals.c
	checkmk ./test/TestSubtractRomanNumerals.check > ./test/TestSubtractRomanNumerals.c
	checkmk ./test/TestIntegrationAddRomanNumerals.check > ./test/TestIntegrationAddRomanNumerals.c
	checkmk ./test/TestIntegrationSubtractRomanNumerals.check > ./test/TestIntegrationSubtractRomanNumerals.c
	checkmk ./test/TestIntegrationOfAddAndSubtractRomanNumerals.check > ./test/TestIntegrationOfAddAndSubtractRomanNumerals.c

clean :
	rm -f ./test/TestSetRomanNumeral ./test/TestSetRomanNumeral.c
	rm -f ./test/TestRomanToArabic ./test/TestRomanToArabic.c
	rm -f ./test/TestArabicToRoman ./test/TestArabicToRoman.c
	rm -f ./test/TestGetRomanNumeralString ./test/TestGetRomanNumeralString.c
	rm -f ./test/TestAddRomanNumerals ./test/TestAddRomanNumerals.c
	rm -f ./test/TestSubtractRomanNumerals ./test/TestSubtractRomanNumerals.c
	rm -f ./test/TestIntegrationAddRomanNumerals ./test/TestIntegrationAddRomanNumerals.c
	rm -f ./test/TestIntegrationSubtractRomanNumerals ./test/TestIntegrationSubtractRomanNumerals.c
	rm -f ./test/TestIntegrationOfAddAndSubtractRomanNumerals ./test/TestIntegrationOfAddAndSubtractRomanNumerals.c
