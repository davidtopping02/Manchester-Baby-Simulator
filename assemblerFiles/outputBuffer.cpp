/**
 * @file outputBuffer.cpp
 * @author Conor Kelly, Stacy Achieng Onyango, Harry Inglis
 * @brief Logic of the Output Buffer Class
 * @version 0.1
 * @date 2021-11-22
 *
 * @copyright Copyright (c) 2021
 */

#include "outputBuffer.h"
/**
 * @brief Construct a new Code Buffer object
 *
 */
OutputBuffer::OutputBuffer()
{
  outputFile = "machineCode.txt";
}
/**
 * @brief Construct a new Code Buffer object
 *
 * @param f The name of the output file
 */
OutputBuffer::OutputBuffer(string f)
{
  outputFile = f;
}
/**
 * @brief Set the buffer at line l to the machine code mc
 *
 * @param l The line to change in the buffer
 * @param mc The machine code to set the line to
 * @return int Status of the function, returns -1 if there is an error
 */
int OutputBuffer::setBuffer(int l, string mc)
{

  // Validates that l is a valid line & that mc is valid machine code
  if (l < 0 || l > 31 || mc == "" || mc.length() > 32)
  {
    return -1;
  }

  buffer[l] = mc;

  return 0;
}
/**
 * @brief Gets the machine code at line l in the code buffer
 *
 * @param l The line to get the machine code of
 * @return string The machine code at line l or 'ERROR' if there is an error
 */
string OutputBuffer::getBuffer(int l) const
{
  // Validates that l is a valid line
  if (l < 0 || l > 32)
  {
    return "ERROR";
  }

  return buffer[l];
}
/**
 * @brief Sets the output file of the code buffer
 *
 * @param f The path to the desired output file
 * @return int A status code relating to the function, -1 represents an error
 */
int OutputBuffer::setFile(string f)
{
  // Validate that f is a string that could lead to a file
  if (f == "")
  {
    return -1;
  }

  outputFile = f;
  return 0;
}
/**
 * @brief Gets the output file for the code buffer
 *
 * @return string The current output file for the code buffer
 */
string OutputBuffer::getFile() const
{

  return outputFile;
}

/**
 * @brief Writes the output buffer to the output file
 *
 * @return int Status of the function, -1 means an error
 */
int OutputBuffer::writeBuffer()
{
  ofstream writer(outputFile);
  if (!writer)
  {
    return -1;
  }

  for (int i = 0; i < 32; i++)
  {
    writer << buffer[i] << endl;
  }
  writer.close();

  return 0;
}

ostream &operator<<(ostream &output, const OutputBuffer &cb)
{
  output << "File: " << cb.getFile() << endl;
  for (int i = 0; i < 32; i++)
  {
    output << i << ":" << cb.getBuffer(i) << endl;
  }

  return output;
}