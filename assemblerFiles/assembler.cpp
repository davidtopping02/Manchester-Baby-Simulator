/**
 * @file assembler.cpp
 * @author Conor Kelly, Stacy Achieng Onyango, Harry Inglis
 * @brief Logic of the Assembler Class
 * @version 0.1
 * @date 2021-11-22
 *
 * @copyright Copyright (c) 2021
 */

#include "assembler.h"

/**
 * @brief Construct a new Assembler Object
 *
 */
Assembler::Assembler()
{
  memoryLocation = 0;
  inputFile = "assembly.txt";
}

/**
 * @brief Construct a new Assembler Object
 *
 * @param is An instruction set object to initialise the Assembler with
 * @param st A symbol table object to initialise the Assembler with
 * @param ob An output buffer object to initialise the Assembler with
 * @param f A filepath to initialise the Assembler with
 */
Assembler::Assembler(InstructionSet is, SymbolTable st, OutputBuffer ob, string f)
{
  instructionSet = is;
  symbolTable = st;
  outputBuffer = ob;
  memoryLocation = 0;
  inputFile = f;
}
/**
 * @brief Destroy the Assembler object
 *
 */
Assembler::~Assembler()
{
}
/**
 * @brief Gets the memory location of the assembler
 *
 * @return int The memory location
 */
int Assembler::getMemoryLocation() const
{

  return memoryLocation;
}

/**
 * @brief Set the memory location
 *
 * @param m The value for the new memory location
 * @return int The status of the function -1 represents an error.
 */
int Assembler::setMemoryLocation(int m)
{

  if (m < 0 || m > 31)
  {
    return -1;
  }

  memoryLocation = m;

  return 0;
}

/**
 * @brief Returns the input file of the assembler
 *
 * @return string The path of the input file
 */
string Assembler::getInputFile() const
{

  return inputFile;
}

/**
 * @brief Sets the input file for the assembler
 *
 * @param f The path to the input file for the assembler
 * @return int The status of the function, -1 represents an error.
 */
int Assembler::setInputFile(string f)
{
  if (f == "")
  {
    return -1;
  }
  inputFile = f;
  return 0;
}

/**
 * @brief Converts an integer into a big-endian binary number
 *
 * @param n The integer to be converted
 * @return string The big-endian binary representation, "ERROR" means an error occured
 */
string Assembler::intToBinary(int n) const
{
  // Make sure that n can be converted to an integer
  if (n < 0)
  {
    return "ERROR";
  }

  // Handle 0 edge-case
  if (n == 0)
  {
    return "0";
  }
  string result = "";
  while (n > 0)
  {
    result += to_string(n % 2);
    n = n / 2;
  }

  return result;
}
/**
 * @brief Categorises words depending on their meaning in the assembler
 *
 * @param word The word to be categorised
 * @return int The category: -1 = comment, 0 = label, 1 = instruction or VAR, 2 = operand
 */
int Assembler::categoriseWord(string word) const
{
  // if the current word is a comment skip to the next line
  if (word.find(";") != string::npos)
  {
    return -1;
  }

  // If the final character is a : then it is a label
  if (word.find(":") == word.length() - 1)
  {
    return 0;
  }

  // If the word is in the instruction set or is the word 'VAR'
  if (instructionSet.search(word) != -1 || word == "VAR")
  {
    return 1;
  }

  return 2;
}

/**
 * @brief Starts the assembler process
 *
 * @return int The status of the assembler, -1 represents and error
 */
int Assembler::start()
{

  // Insert all the machine code commands
  instructionSet.insert("JMP", "000");
  instructionSet.insert("JRP", "100");
  instructionSet.insert("LDN", "010");
  instructionSet.insert("STO", "110");
  instructionSet.insert("SUB", "001");
  instructionSet.insert("SUB", "101");
  instructionSet.insert("CMP", "011");
  instructionSet.insert("STP", "111");

  // Create an file stream and validate it
  ifstream reader(inputFile);
  if (!reader)
  {
    return -1;
  }

  // Create a variable to store the current line in the file
  string line;
  int counter = 0;
  while (getline(reader, line))
  {
    // String for the machine code to be pushed to the output buffer
    string machineCode = "";

    // Create a place to store all of the words on this line
    vector<string> words = {};

    // convert the line from a string to char[] for using in strtok()
    char charLine[line.length()];

    // Copy the contents of line to charLine
    strcpy(charLine, line.c_str());

    // Create a substring until the first delimiter
    char *token = strtok(charLine, " ");
    // Loop while there are still substrings to be made
    while (token != NULL)
    {
      // Add this substring to the list of words
      words.push_back(token);
      // Look for the next token
      token = strtok(NULL, " ");
    }

    // Variables for storing information about the current line
    string label = "";
    string instruction = "";
    string operand = "";

    // Tracks if there has been activity in the program on this line in the file
    bool activity = false;

    for (int i = 0; i < words.size(); i++)
    {
      string currentWord = words.at(i);
      int category = categoriseWord(currentWord);

      // If it is a comment move on to the next line
      if (category == -1)
      {
        break;
      }

      // If it is a label
      if (category == 0)
      {
        label = currentWord.substr(0, currentWord.length() - 1);
        continue;
      }

      // If it is an instruction
      if (category == 1)
      {
        instruction = currentWord;
        continue;
      }

      // Otherwise it is an operand
      operand = currentWord;
    }

    // If there is  label add it to the symbol table
    // ! Allows user to input same label twice
    if (label != "")
    {
      string memoryLocationBinary = intToBinary(memoryLocation);
      // Pad the operand to 5 bits
      for (int i = memoryLocationBinary.length(); i < 5; i++)
      {
        memoryLocationBinary += "0";
      }
      symbolTable.insert(label, memoryLocationBinary);
      activity = true;
    }

    // If there is an instruction decode the instruction and add it to the outputBuffer
    if (instruction != "")
    {
      // Make the machine code variable 32 bits
      for (int i = 0; i < 32; i++)
      {
        machineCode += "0";
      }
      activity = true;

      if (instruction == "VAR")
      {
        // Convert the number to binary
        machineCode = intToBinary(stoi(operand));
        // Pad the binary number to 32 bits
        for (int i = machineCode.length(); i < 32; i++)
        {
          machineCode += "0";
        }
      }

      if (instruction == "JMP")
      {

        if (operand != "")
        {
          int symbolLocation = symbolTable.search(operand);

          // If the operand is not in the symbol table
          if (symbolLocation == -1)
          {
            string instructionBinary = instructionSet.lookup("JMP");

            // Update the machine code to show that command
            machineCode[13] = instructionBinary[0];
            machineCode[14] = instructionBinary[1];
            machineCode[15] = instructionBinary[2];
          }
          else
          {
            string instructionBinary = instructionSet.lookup("JMP");
            string operandBinary = symbolTable.lookup(operand);

            // Update the machine code to point to the operand
            machineCode[0] = operandBinary[0];
            machineCode[1] = operandBinary[1];
            machineCode[2] = operandBinary[2];
            machineCode[3] = operandBinary[3];
            machineCode[4] = operandBinary[4];

            // Update the machine code to show that command
            machineCode[13] = instructionBinary[0];
            machineCode[14] = instructionBinary[1];
            machineCode[15] = instructionBinary[2];
          }
        }
        else
        {
          //! Deal with error of no operand
        }
      }

      if (instruction == "JRP")
      {

        if (operand != "")
        {
          int symbolLocation = symbolTable.search(operand);

          // If the operand is not in the symbol table
          if (symbolLocation == -1)
          {
            string instructionBinary = instructionSet.lookup("JRP");

            // Update the machine code to show that command
            machineCode[13] = instructionBinary[0];
            machineCode[14] = instructionBinary[1];
            machineCode[15] = instructionBinary[2];
          }
          else
          {
            string instructionBinary = instructionSet.lookup("JRP");
            string operandBinary = symbolTable.lookup(operand);

            // Update the machine code to point to the operand
            machineCode[0] = operandBinary[0];
            machineCode[1] = operandBinary[1];
            machineCode[2] = operandBinary[2];
            machineCode[3] = operandBinary[3];
            machineCode[4] = operandBinary[4];

            // Update the machine code to show that command
            machineCode[13] = instructionBinary[0];
            machineCode[14] = instructionBinary[1];
            machineCode[15] = instructionBinary[2];
          }
        }
        else
        {
          //! Deal with error of no operand
        }
      }

      if (instruction == "LDN")
      {

        if (operand != "")
        {
          int symbolLocation = symbolTable.search(operand);

          // If the operand is not in the symbol table
          if (symbolLocation == -1)
          {
            string instructionBinary = instructionSet.lookup("LDN");

            // Update the machine code to show that command
            machineCode[13] = instructionBinary[0];
            machineCode[14] = instructionBinary[1];
            machineCode[15] = instructionBinary[2];
          }
          else
          {
            string instructionBinary = instructionSet.lookup("LDN");
            string operandBinary = symbolTable.lookup(operand);

            // Update the machine code to point to the operand
            machineCode[0] = operandBinary[0];
            machineCode[1] = operandBinary[1];
            machineCode[2] = operandBinary[2];
            machineCode[3] = operandBinary[3];
            machineCode[4] = operandBinary[4];

            // Update the machine code to show that command
            machineCode[13] = instructionBinary[0];
            machineCode[14] = instructionBinary[1];
            machineCode[15] = instructionBinary[2];
          }
        }
        else
        {
          //! Deal with error of no operand
        }
      }

      if (instruction == "STO")
      {

        if (operand != "")
        {
          int symbolLocation = symbolTable.search(operand);

          // If the operand is not in the symbol table
          if (symbolLocation == -1)
          {
            string instructionBinary = instructionSet.lookup("STO");

            // Update the machine code to show that command
            machineCode[13] = instructionBinary[0];
            machineCode[14] = instructionBinary[1];
            machineCode[15] = instructionBinary[2];
          }
          else
          {
            string instructionBinary = instructionSet.lookup("STO");
            string operandBinary = symbolTable.lookup(operand);

            // Update the machine code to point to the operand
            machineCode[0] = operandBinary[0];
            machineCode[1] = operandBinary[1];
            machineCode[2] = operandBinary[2];
            machineCode[3] = operandBinary[3];
            machineCode[4] = operandBinary[4];

            // Update the machine code to show that command
            machineCode[13] = instructionBinary[0];
            machineCode[14] = instructionBinary[1];
            machineCode[15] = instructionBinary[2];
          }
        }
        else
        {
          //! Deal with error of no operand
        }
      }

      if (instruction == "SUB")
      {

        if (operand != "")
        {
          int symbolLocation = symbolTable.search(operand);

          // If the operand is not in the symbol table
          if (symbolLocation == -1)
          {
            string instructionBinary = instructionSet.lookup("SUB");

            // Update the machine code to show that command
            machineCode[13] = instructionBinary[0];
            machineCode[14] = instructionBinary[1];
            machineCode[15] = instructionBinary[2];
          }
          else
          {
            string instructionBinary = instructionSet.lookup("SUB");
            string operandBinary = symbolTable.lookup(operand);

            // Update the machine code to point to the operand
            machineCode[0] = operandBinary[0];
            machineCode[1] = operandBinary[1];
            machineCode[2] = operandBinary[2];
            machineCode[3] = operandBinary[3];
            machineCode[4] = operandBinary[4];

            // Update the machine code to show that command
            machineCode[13] = instructionBinary[0];
            machineCode[14] = instructionBinary[1];
            machineCode[15] = instructionBinary[2];
          }
        }
        else
        {
          //! Deal with error of no operand
        }
      }

      if (instruction == "CMP")
      {

        string instructionBinary = instructionSet.lookup("CMP");

        // Update the machine code to show that command
        machineCode[13] = instructionBinary[0];
        machineCode[14] = instructionBinary[1];
        machineCode[15] = instructionBinary[2];
      }

      if (instruction == "STP")
      {

        string instructionBinary = instructionSet.lookup("STP");

        // Update the machine code to show that command
        machineCode[13] = instructionBinary[0];
        machineCode[14] = instructionBinary[1];
        machineCode[15] = instructionBinary[2];
      }
    }

    if (activity)
    {
      // Set the output buffer
      outputBuffer.setBuffer(memoryLocation, machineCode);
      memoryLocation++;
    }
  }

  // Reset the memory location back to the start
  memoryLocation = 0;

  // Create an new file stream and validate it
  ifstream reader2(inputFile);
  if (!reader2)
  {
    return -1;
  }
  while (getline(reader2, line))
  {
    // String for the machine code to be pushed to the output buffer
    string machineCode = "";

    // Create a place to store all of the words on this line
    vector<string> words = {};

    // convert the line from a string to char[] for using in strtok()
    char charLine[line.length()];

    // Copy the contents of line to charLine
    strcpy(charLine, line.c_str());

    // Create a substring until the first delimiter
    char *token = strtok(charLine, " ");
    // Loop while there are still substrings to be made
    while (token != NULL)
    {
      // Add this substring to the list of words
      words.push_back(token);
      // Look for the next token
      token = strtok(NULL, " ");
    }

    // Variables for storing information about the current line
    string label = "";
    string instruction = "";
    string operand = "";

    // Tracks if there has been activity in the program on this line in the file
    bool activity = false;

    for (int i = 0; i < words.size(); i++)
    {
      string currentWord = words.at(i);
      int category = categoriseWord(currentWord);

      // If it is a comment move on to the next line
      if (category == -1)
      {
        break;
      }

      // If it is a label move to the next word
      if (category == 0)
      {
        activity = true;
        continue;
      }

      // If it is an instruction move to the next word
      if (category == 1)
      {
        instruction = currentWord;
        activity = true;
        continue;
      }

      // Otherwise it is an operand
      operand = currentWord;
    }

    if (operand != "" && instruction != "VAR")
    {

      // ! Doesn't account for symbol not existing

      string operandBinary = symbolTable.lookup(operand);

      machineCode = outputBuffer.getBuffer(memoryLocation);

      // Update the machine code to point to the operand
      machineCode[0] = operandBinary[0];
      machineCode[1] = operandBinary[1];
      machineCode[2] = operandBinary[2];
      machineCode[3] = operandBinary[3];
      machineCode[4] = operandBinary[4];
      activity = true;
    }

    if (activity)
    {
      // Set the output buffer
      outputBuffer.setBuffer(memoryLocation, machineCode);
      memoryLocation++;
    }
  }

  outputBuffer.writeBuffer();
  return 0;
}