test: testRomanNumeral
	./test/TestRomanNumeral

testmem: testRomanNumeral
	valgrind --leak-check=yes ./test/TestRomanNumeral

testRomanNumeral: .checkmk ./src/SetRomanNumeral.c
	gcc ./test/TestSetRomanNumeral.c ./src/SetRomanNumeral.c \
		-std=c90 -g -O0 $(shell pkg-config --libs --cflags check) \
		-lc -lm -o ./test/TestRomanNumeral

.checkmk: ./test/TestSetRomanNumeral.check
	checkmk ./test/TestSetRomanNumeral.check > ./test/TestSetRomanNumeral.c

clean :
	rm -f ./test/TestRomanNumeral ./test/TestSetRomanNumeral.c
