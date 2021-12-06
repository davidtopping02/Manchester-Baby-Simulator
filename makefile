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
	rm *.o main assembler simulator assemblerTest
	
# Compiles the Assembler with tests

assembler_test: assembler.o symbol.o symbolTable.o instruction.o instructionSet.o tester.o outputBuffer.o
	$(CC) $(CFLAGS) -o assemblerTest assembler.o symbol.o symbolTable.o instruction.o instructionSet.o tester.o outputBuffer.o

##### assembler files #####

tester.o: assemblerFiles/tester.cpp assemblerFiles/tester.h
	$(CC) -c assemblerFiles/tester.cpp

assembler.o: assemblerFiles/assembler.cpp assemblerFiles/assembler.h assemblerFiles/instructionSet.h assemblerFiles/symbolTable.h assemblerFiles/outputBuffer.h
	$(CC) -c assemblerFiles/assembler.cpp

symbol.o: assemblerFiles/symbol.cpp assemblerFiles/symbol.h
	$(CC) -c assemblerFiles/symbol.cpp

symbolTable.o: assemblerFiles/symbolTable.cpp assemblerFiles/symbolTable.h symbol.o
	$(CC) -c assemblerFiles/symbolTable.cpp

instruction.o: assemblerFiles/instruction.cpp assemblerFiles/instruction.h
	$(CC) -c assemblerFiles/instruction.cpp

instructionSet.o: assemblerFiles/instructionSet.cpp assemblerFiles/instructionSet.h
	$(CC) -c assemblerFiles/instructionSet.cpp

outputBuffer.o: assemblerFiles/outputBuffer.cpp assemblerFiles/outputBuffer.h
	$(CC) -c assemblerFiles/outputBuffer.cpp


##### simulator files #####

main.o: main.cpp main.h memoryLocations.h
	$(CC) -c main.cpp

memoryLocations.o: memoryLocations.cpp memoryLocations.h
	$(CC) -c memoryLocations.cpp 

menu.o: menu.cpp main.h memoryLocations.h
	$(CC) -c menu.cpp

