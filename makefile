all: linkedList.o library.o
	gcc driver.c

linkedList.o: linkedList.h linkedList.c
	gcc -c linkedList.c

library.o: library.h library.c
	gcc -c library.c

run:
	./a.out
	make clear

clear:
	rm linkedList.o
	rm library.o
	rm a.out
