/**
 * @file instructionSet.cpp
 * @author Conor Kelly, Stacy Achieng Onyango, Harry Inglis
 * @brief contains the logic for the instruction set
 * @version 0.1
 * @date 2021-11-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "instructionSet.h"

/**
 * @brief Construct a new Instruction Set object
 * 
 */
InstructionSet::InstructionSet()
{
  tablesize = 8;
  currentSize = 0;
  table = new Instruction[8];
}

/**
 * @brief Destroy the Instruction Set object
 * 
 */
InstructionSet::~InstructionSet()
{
  delete[] table;
}

/**
 * @brief Inserts an Instruction into the Instruction Set
 * 
 * @param n The name of the Instruction
 * @param b The binary of the Instruction
 * @return true If the function succeeds in adding the Instruction
 * @return false If the function fails to add the Instruction
 */
bool InstructionSet::insert(string n, string b)
{

  // Make sure that a name and binary value are provided
  if (n == "" || b == "")
  {
    return false;
  }

  try
  {
    // Try to add the Instruction to the Instruction Set
    table[currentSize] = Instruction(n, b);
    currentSize++;
  }

  // if theres an error return false
  catch (const std::exception &e)
  {
    return false;
  }

  return true;
}

/**
 * @brief Returns the position of a name in the Instruction Set. Returns -1 if there is no name or an error occurs
 * 
 * @param n The name of the Instruction to search for
 * @return int The position of the name in the Instruction Set. -1 if an error occurs
 */
int InstructionSet::search(string n)
{
  // Make sure a valid name is passed in
  if (n == "")
  {
    return -1;
  }

  try
  {
    int counter = 0;
    while (counter < currentSize)
    {
      if (table[counter].getName() == n)
      {
        return counter;
      }
      counter++;
    }
  }
  catch (const std::exception &e)
  {
    return -1;
  }

  return -1;
}

/**
 * @brief Returns the binary of the Instruction with the given name
 * 
 * @param n The name of the Instruction to get the binary of
 * @return string The binary of the Instruction
 */

string InstructionSet::lookup(string n)
{
  // Make sure that the name is valid
  if (n == "")
  {
    return "";
  }

  const int result = search(n);
  if (result == -1)
  {
    return "";
  }
  return table[result].getBinary();
}

/**
 * @brief Overloads the output operator to display the Instruction Set
 * 
 * @param output The output stream
 * @param is The Instruction Set
 * @return ostream& The final output
 */
ostream &operator<<(ostream &output, const InstructionSet &is)
{
  for (int i = 0; i < is.tablesize; i++)
  {
    output << i << ":" << is.table[i].getName() << ":" << is.table[i].getBinary() << endl;
  }
  return output;
}