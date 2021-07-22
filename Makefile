CC=g++
CFLAGS= -g -Wall

OBJECTS = ./SortedList/List.o
TARGETDIR = ./SortedList/

main: $(TARGETDIR)main.cpp $(OBJECTS)
	$(CC) $(CFLAGS) -o main $(TARGETDIR)main.cpp $(OBJECTS)
	mv ./main ./SortedList
List.o: $(TAGERTDIR)List.h
	$(CC) $(CFLAGS) -c $(TARGETDIR)List.h
	
.PHONY: clean
clean:
	rm -rf *.o
	
