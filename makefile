CC = g++
CFLAGS = -std=c++17 -Wall -Werror -pedantic -g

# Compiles both the assembler and the simulator
all: menu.o manchesterBaby.o memoryLocations.o menu.o assembler.o symbol.o symbolTable.o instruction.o instructionSet.o outputBuffer.o bufferLine.o utility.o
	$(CC) $(CFLAGS) -o main menu.o manchesterBaby.o memoryLocations.o menu.o assembler.o symbol.o symbolTable.o instruction.o instructionSet.o outputBuffer.o bufferLine.o utility.o

# Compiles just the simulator
simulator: manchesterBaby.o memoryLocations.o menu.o
	$(CC) $(CFLAGS) -o simulator manchesterBaby.o memoryLocations.o menu.o

# Compiles just the assembler
assembler: assembler.o symbol.o symbolTable.o instruction.o instructionSet.o outputBuffer.o bufferLine.o utility.o
	$(CC) $(CFLAGS) -o assembler assembler.o symbol.o symbolTable.o instruction.o instructionSet.o outputBuffer.o bufferLine.o utility.o

#Cleans the directory
clean:
	rm *.o main assembler simulator assemblerTest
	
# Compiles the Assembler with tests

assembler_test: assembler.o symbol.o symbolTable.o instruction.o instructionSet.o tester.o outputBuffer.o bufferLine.o utility.o
	$(CC) $(CFLAGS) -o assemblerTest assembler.o symbol.o symbolTable.o instruction.o instructionSet.o tester.o outputBuffer.o bufferLine.o utility.o

##### assembler files #####

tester.o: assemblerFiles/tester.cpp assemblerFiles/tester.h
	$(CC) -g -c assemblerFiles/tester.cpp

assembler.o: assemblerFiles/assembler.cpp assemblerFiles/assembler.h assemblerFiles/instructionSet.h assemblerFiles/symbolTable.h assemblerFiles/outputBuffer.h
	$(CC) -g -c assemblerFiles/assembler.cpp

symbol.o: assemblerFiles/symbol.cpp assemblerFiles/symbol.h
	$(CC) -g -c assemblerFiles/symbol.cpp

symbolTable.o: assemblerFiles/symbolTable.cpp assemblerFiles/symbolTable.h symbol.o
	$(CC) -g -c assemblerFiles/symbolTable.cpp

instruction.o: assemblerFiles/instruction.cpp assemblerFiles/instruction.h
	$(CC) -g -c assemblerFiles/instruction.cpp

instructionSet.o: assemblerFiles/instructionSet.cpp assemblerFiles/instructionSet.h
	$(CC) -g -c assemblerFiles/instructionSet.cpp

outputBuffer.o: assemblerFiles/outputBuffer.cpp assemblerFiles/outputBuffer.h
	$(CC) -g -c assemblerFiles/outputBuffer.cpp

bufferLine.o: assemblerFiles/bufferLine.cpp assemblerFiles/bufferLine.h
	$(CC) -g -c assemblerFiles/bufferLine.cpp

utility.o: assemblerFiles/utility.cpp assemblerFiles/utility.cpp
	$(CC) -g -c assemblerFiles/utility.cpp

##### simulator files #####

manchesterBaby.o: manchesterBabyFiles/manchesterBaby.cpp manchesterBabyFiles/manchesterBaby.h manchesterBabyFiles/memoryLocations.h
	$(CC) -g -c manchesterBabyFiles/manchesterBaby.cpp

memoryLocations.o: manchesterBabyFiles/memoryLocations.cpp manchesterBabyFiles/memoryLocations.h
	$(CC) -g -c manchesterBabyFiles/memoryLocations.cpp 

menu.o: menu.cpp manchesterBabyFiles/manchesterBaby.h manchesterBabyFiles/memoryLocations.h
	$(CC) -g -c menu.cpp

