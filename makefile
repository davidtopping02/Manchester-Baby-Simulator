CC = g++
CFLAGS = -std=c++17 -Wall -Werror -pedantic -g

# Compiles both the assembler and the simulator
all: main.o memoryLocations.o menu.o
	$(CC) $(CFLAGS) -o main main.o memoryLocations.o menu.o

# Compiles just the simulator
simulator: main.o memoryLocations.o menu.o
	$(CC) $(CFLAGS) -o simulator main.o memoryLocations.o menu.o

# Compiles just the assembler
assembler: assembler.o symbol.o symbolTable.o instruction.o instructionSet.o outputBuffer.o
	$(CC) $(CFLAGS) -o assembler assembler.o symbol.o symbolTable.o instruction.o instructionSet.o outputBuffer.o
#Cleans the directory
clean:
	rm *.o main assembler simulator
# Compiles the Assembler with tests

assembler_test: assembler.o symbol.o symbolTable.o instruction.o instructionSet.o tester.o outputBuffer.o
	$(CC) $(CFLAGS) -o assemblerTest assembler.o symbol.o symbolTable.o instruction.o instructionSet.o tester.o outputBuffer.o

##### assembler files #####

tester.o: assemblerCode/tester.cpp assemblerCode/tester.h
	$(CC) -c assemblerCode/tester.cpp

assembler.o: assemblerCode/assembler.cpp assemblerCode/assembler.h assemblerCode/instructionSet.h assemblerCode/symbolTable.h assemblerCode/outputBuffer.h
	$(CC) -c assemblerCode/assembler.cpp

symbol.o: assemblerCode/symbol.cpp assemblerCode/symbol.h
	$(CC) -c assemblerCode/symbol.cpp

symbolTable.o: assemblerCode/symbolTable.cpp assemblerCode/symbolTable.h symbol.o
	$(CC) -c assemblerCode/symbolTable.cpp

instruction.o: assemblerCode/instruction.cpp assemblerCode/instruction.h
	$(CC) -c assemblerCode/instruction.cpp

instructionSet.o: assemblerCode/instructionSet.cpp assemblerCode/instructionSet.h
	$(CC) -c assemblerCode/instructionSet.cpp

outputBuffer.o: assemblerCode/outputBuffer.cpp assemblerCode/outputBuffer.h
	$(CC) -c assemblerCode/outputBuffer.cpp


##### simulator files #####

main.o: main.cpp main.h memoryLocations.h
	$(CC) -c main.cpp

memoryLocations.o: memoryLocations.cpp memoryLocations.h
	$(CC) -c memoryLocations.cpp 

menu.o: menu.cpp main.h memoryLocations.h
	$(CC) -c menu.cpp

