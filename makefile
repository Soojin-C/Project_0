all: linkedList.o
	gcc driver.c

linkedList.o: linkedList.h linkedList.c
	gcc -c linkedList.c

run:
	./a.out
	make clear

clear:
	rm linkedList.o
	rm a.out
