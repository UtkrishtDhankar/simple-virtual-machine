CC=g++
CFLAGS=-std=c++14 -Wall -c
LFLAGS=-std=c++14 -Wall 

OBJS=Computer.o Instruction.o Load.o Store.o Utils.o main.o

EXEC=vm

debug: CFLAGS+= -g
debug: all

all: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(EXEC)

main.o: main.cpp Computer.hpp Instruction.hpp
	$(CC) $(CFLAGS) main.cpp -o main.o

Computer.o: Computer.cpp Computer.hpp Instruction.hpp Utils.hpp
	$(CC) $(CFLAGS) Computer.cpp -o Computer.o

Instruction.o: Instruction.cpp Instruction.hpp Utils.hpp
	$(CC) $(CFLAGS) Instruction.cpp -o Instruction.o

Load.o: Load.cpp Load.hpp Instruction.hpp Utils.hpp
	$(CC) $(CFLAGS) Load.cpp -o Load.o

Store.o: Store.cpp Store.hpp Instruction.hpp Utils.hpp
	$(CC) $(CFLAGS) Store.cpp -o Store.o

Utils.o: Utils.cpp Utils.hpp
	$(CC) $(CFLAGS) Utils.cpp -o Utils.o

clean:
	rm -f $(EXEC)
	rm -f $(OBJS)
