main: main.c List.o
	gcc -Wall -g -o main main.c List.o
List.o: List.c List.h
	gcc -Wall -c List.c List.h
.PHONY: clean
clean:
	rm -rf *.o
