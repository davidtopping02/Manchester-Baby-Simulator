/**
 * @file assembler.h
 * @author Conor Kelly, Stacy Achieng Onyango
 * @brief file with function & class declarations for the Assembler class
 * @version 0.1
 * @date 2021-11-22
 *
 * @copyright Copyright (c) 2021
 */

#ifndef ASSEMBLER_H
#define ASSEMBLER_H
/**
 * ### INCLUDES ###
 */

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <string.h>

#include "instructionSet.h"
#include "symbolTable.h"
#include "outputBuffer.h"

/**
 * ### CLASS DEFINITIONS ###
 */

/**
 * @brief The main assembler class that assembles a given program
 *
 */

class Assembler
{
private:
  InstructionSet instructionSet;
  SymbolTable symbolTable;
  OutputBuffer outputBuffer;
  int memoryLocation;
  string inputFile;

public:
  Assembler();
  Assembler(InstructionSet is, SymbolTable st, OutputBuffer ob, string f);
  ~Assembler();

  int getMemoryLocation();
  int setMemoryLocation(int m);
  int setInputFile(string f);
  int start();
  string intToBinary(int n);
  int categoriseWord(string word);
};
#endif