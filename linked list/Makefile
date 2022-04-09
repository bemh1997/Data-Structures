list.o: list.c
	gcc list.c -c
main.o: main.c
	gcc main.c -c

compile: list.o main.o
	gcc main.o list.o -o linkedlist

run: compile
	./linkedlist
clean:
	rm -f linkedlist main.o list.o
