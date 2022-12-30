CC=gcc
CC2=gcc
CFLAGS=-c
LDFLAGS= #-Wall -Wextra -Werror
OS := $(shell uname -s)

ifeq ($(OS), Darwin)
	CC2 += -D OS_MAC
else
	CC2 += -D OS_LINUX
endif

default: all

all: clean s21_string.a test  

test: s21_string.a test.c
ifeq ($(OS), Darwin)
	$(CC) $(LDFLAGS) -o test test.c s21_string.a -lcheck
	./test
else
	gcc test.c s21_string.a -o test -lcheck -lsubunit -lrt -lpthread -lm
	./test
endif

s21_string.a: s21_string.o
	ar rcs s21_string.a s21_string.o
	ranlib $@
	cp $@ lib$@
	
s21_string.o: s21_string.c
	$(CC2) $(LDFLAGS) -c -o s21_string.o s21_string.c

clean:
	rm -rf test *.a *.o *.out fizz *.gc* *.info report

rebuild: clean all

gcov_report: 
ifeq ($(OS), Darwin)
	$(CC2) --coverage $(LDFLAGS) test.c s21_string.c -o test -lcheck
else
	$(CC2) --coverage $(LDFLAGS) test.c s21_string.c -o test -lcheck -lsubunit -lrt -lpthread -lm
endif
	./test
	lcov -t "test" -o test.info -c -d ./
	genhtml -o report test.info



