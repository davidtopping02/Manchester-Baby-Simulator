/**
 * @file bufferLine.h
 * @author Conor Kelly, Stacy Achieng Onyango
 * @brief file with function & class declarations for the BufferLine
 * @version 0.1
 * @date 2021-11-22
 *
 * @copyright Copyright (c) 2021
 */

#ifndef BUFFER_LINE_H
#define BUFFER_LINE_H

using namespace std;
/**
 * ### INCLUDES ###
 */
#include <iostream>
#include <string>

/**
 * ### CLASS DEFINITIONS ###
 */

/**
 * @brief Stores a Instruction to be stored in the instruction table
 *
 */

class BufferLine
{
private:
  string operand;
  string instruction;

public:
  BufferLine();
  BufferLine(string op, string ins);
  string getOperand() const;
  string getInstruction() const;

  int setOperand();
  int setInstruction();
};

#endif