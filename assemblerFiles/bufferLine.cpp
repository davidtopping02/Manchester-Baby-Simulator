/**
 * @file bufferLine.cpp
 * @author Conor Kelly, Stacy Achieng Onyango, Harry Inglis
 * @brief Logic of the BufferLine Class
 * @version 0.1
 * @date 2021-11-22
 *
 * @copyright Copyright (c) 2021
 */

#include "bufferLine.h"

/**
 * @brief Construct a new Buffer Line object
 *
 */
BufferLine::BufferLine()
{
  operand = "";
  instruction = "";
}

/**
 * @brief Construct a new Buffer Line object
 *
 * @param op The operand of the buffer line
 * @param ins The instruction of the buffer line
 */
BufferLine::BufferLine(string op, string ins)
{
  operand = op;
  instruction = ins;
}

/**
 * @brief Returns the Buffer Line's instruction
 *
 * @return string The instruction of the Buffer Line
 */
string BufferLine::getInstruction() const
{

  return instruction;
}

/**
 * @brief Returns the Buffer Line's operand
 *
 * @return string The operand of the Buffer Line
 */
string BufferLine::getOperand() const
{
  return operand;
}