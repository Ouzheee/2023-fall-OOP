all:Lab07

CC = g++
target = Lab07

$(target):main.o lab7.o
	$(CC) main.o lab7.o -g -o $(target)
main.o: main.cpp func.h
	$(CC) -c main.cpp
lab7.o: lab7.cpp func.h
	$(CC) -c lab7.cpp
clean:
	rm -rf *.o $(target)