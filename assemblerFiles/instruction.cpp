/**
 * @file instruction.cpp
 * @author Conor Kelly, Stacy Achieng Onyango, Harry Inglis
 * @brief contains the logic for the instructions in the instruction table
 * @version 0.1
 * @date 2021-11-22
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "instruction.h"

/**
 * @brief Construct a new Instruction object
 *
 */
Instruction::Instruction()
{
  name = "";
  binary = "";
}

/**
 * @brief Construct a new Instruction object
 *
 * @param n The name of the Instruction
 * @param b The binary of the Instruction
 *
 */
Instruction::Instruction(string n, string b)
{
  name = n;
  binary = b;
}

/**
 * @brief Gets the name of the instruction
 *
 * @return string The name of the instruction
 */

string Instruction::getName()
{
  return name;
}

/**
 * @brief Gets the binary of the Instruction
 *
 * @return string The binary of the Instruction
 */

string Instruction::getBinary()
{
  return binary;
}

/**
 * @brief Sets the binary of the Instruction
 *
 * @param b The new binary of the Instruction
 */

void Instruction::setBinary(string b)
{
  binary = b;
}

/**
 * @brief Overloads the output operator to show the Instruction's name and binary
 *
 * @param output The output stream
 * @param s The instruction object to be output
 * @return ostream& The formatted output
 */

ostream &operator<<(ostream &output, const Instruction &i)
{
  output << i.name << ":" << i.binary << endl;

  return output;
}