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
  buffer = new BufferLine[32];
  currentSize = 0;
}
/**
 * @brief Construct a new Code Buffer object
 *
 * @param f The name of the output file
 */
OutputBuffer::OutputBuffer(string f)
{
  outputFile = f;
  buffer = new BufferLine[32];
  currentSize = 0;
}

/**
 * @brief Set the buffer at line l to the command and operand (optional)
 *
 * @param l The line to change in the buffer
 * @param ins The instruction to set the buffer line to in binary
 * @return int Status of the function
 */
int OutputBuffer::setBufferLine(int l, string ins)
{

  // TODO: ADD VALIDATION FOR UPDATED FORMAT

  updateBufferSize(l);
  buffer[l].setInstructionBinary(ins);

  return 0;
}

/**
 * @brief Set the buffer at line l to the command and operand (optional)
 *
 * @param l The line to change in the buffer
 * @param ins The instruction to set the buffer line to in binary
 * @param op The operand to set the buffer line to in binary (optional)
 * @return int Status of the function
 */

int OutputBuffer::setBufferLine(int l, string ins, string op)
{
  // TODO: ADD VALIDATION FOR UPDATED FORMAT

  updateBufferSize(l);

  buffer[l].setInstructionBinary(ins);
  buffer[l].setOperand(op);

  return 0;
}

/**
 * @brief Sets the buffer line l operand to the string provided
 *
 * @param l The line to change in the buffer
 * @param op The operand to set the buffer line to in binary
 * @return int Status of the function
 */
int OutputBuffer::setBufferLineOperand(int l, string op)
{
  // TODO: ADD VALIDATION FOR UPDATED FORMAT

  updateBufferSize(l);
  buffer[l].setOperand(op);

  return 0;
}

int OutputBuffer::setBufferLineValue(int l, int val)
{
  // TODO: ADD VALIDATION FOR UPDATED FORMAT

  updateBufferSize(l);
  buffer[l].setInstructionValue(val);
}

int OutputBuffer::setBufferLineName(int l, string name)
{
  // TODO: ADD VALIDATION

  updateBufferSize(l);
  buffer[l].setInstructionName(name);
}
/**
 * @brief Gets the Buffer Line at line l
 *
 * @param l The line to get the machine code of
 * @return BufferLine The line of the Buffer at l
 */
BufferLine OutputBuffer::getBufferLine(int l) const
{
  // TODO: REIMPLEMENT VALIDATION
  // // Validates that l is a valid line
  // if (l < 0 || l > 32)
  // {
  //   return "ERROR";
  // }

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

  for (int i = 0; i < currentSize + 1; i++)
  {
    writer << buffer[i].asMachineCode() << endl;
  }
  writer.close();

  return 0;
}

/**
 * @brief Tests to see if the buffer needs to be expanded
 *
 * @param l The current line number of the buffer to be updated
 * @return int Status of the function
 */
int OutputBuffer::updateBufferSize(int l)
{

  // TODO: IMPLEMENT VERIFICATION AND ERRORS
  // If the line is larger than the current buffer set the currentbuffer to that line
  if (l > currentSize)
  {
    cout << "UPDATING BUFFER SIZE FROM: " << currentSize << " TO: " << l << endl;
    currentSize = l;
  }

  return 0;
}

ostream &
operator<<(ostream &output, const OutputBuffer &ob)
{

  for (int i = 0; i < 32; i++)
  {
    BufferLine currentLine = ob.getBufferLine(i);
    string machineCode = currentLine.asMachineCode();
    output << i << ":" << machineCode << endl;
  }
  return output;
}
