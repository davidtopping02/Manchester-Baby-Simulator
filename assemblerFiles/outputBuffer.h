/**
 * @file outputBuffer.h
 * @author Conor Kelly, Stacy Achieng Onyango
 * @brief file with function & class declarations for the Output Buffer class
 * @version 0.1
 * @date 2021-11-22
 *
 * @copyright Copyright (c) 2021
 */

#ifndef OUTPUT_BUFFER_H
#define OUTPUT_BUFFER_H

using namespace std;
/**
 * ### INCLUDES ###
 */
#include <iostream>
#include <string>
#include <fstream>
/**
 * ### CLASS DEFINITIONS ###
 */

/**
 * @brief Stores a Instruction to be stored in the instruction table
 *
 */

class OutputBuffer
{
private:
  string outputFile;
  string buffer[32];

public:
  OutputBuffer();
  OutputBuffer(string f);

  int setBuffer(int l, string mc);
  string getBuffer(int l) const;
  int setFile(string f);
  string getFile() const;
  int writeBuffer();

  friend ostream &operator<<(ostream &output, const OutputBuffer &ob);
};
#endif