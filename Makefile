test: testRomanNumeral
	./test/TestSetRomanNumeral
	./test/TestRomanToArabic

testmem: testRomanNumeral
	valgrind --leak-check=yes ./test/TestRomanNumeral
	valgrind --leak-check=yes ./test/TestRomanToArabic

testRomanNumeral: .checkmk ./src/SetRomanNumeral.c
	gcc ./test/TestSetRomanNumeral.c ./src/SetRomanNumeral.c \
		-std=c90 -g -O0 $(shell pkg-config --libs --cflags check) \
		-lc -lm -o ./test/TestSetRomanNumeral
	gcc ./test/TestRomanToArabic.c ./src/RomanToArabic.c \
		-std=c90 -g -O0 $(shell pkg-config --libs --cflags check) \
		-lc -lm -o ./test/TestRomanToArabic


.checkmk: ./test/TestSetRomanNumeral.check ./test/TestRomanToArabic.check
	checkmk ./test/TestSetRomanNumeral.check > ./test/TestSetRomanNumeral.c
	checkmk ./test/TestRomanToArabic.check > ./test/TestRomanToArabic.c

clean :
	rm -f ./test/TestSetRomanNumeral ./test/TestSetRomanNumeral.c
	rm -f ./test/TestRomanToArabic ./test/TestRomanToArabic.c
