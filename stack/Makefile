stack.o: stack.c
	gcc stack.c -c
main.o: main.c
	gcc main.c -c
compile: stack.o main.o
	gcc stack.o main.o -o stack
run: compile
	./stack
clean:
	rm -f stack stack.o main.o
	