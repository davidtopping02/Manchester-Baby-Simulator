/**
 * @file symbolTable.cpp
 * @author Conor Kelly, Stacy Achieng Onyango, Harry Inglis
 * @brief contains the logic for the symbol table
 * @version 0.1
 * @date 2021-11-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "symbolTable.h"
#include "symbol.h"

/**
 * @brief Construct a new Symbol Table object
 * 
 */
SymbolTable::SymbolTable()
{
  tablesize = 10;
  currentSize = 0;
  table = new Symbol[10];
}
/**
 * @brief Construct a new Symbol Table object
 * 
 * @param size The size of the Symbol Table
 */
SymbolTable::SymbolTable(int size)
{
  tablesize = size;
  currentSize = 0;
  table = new Symbol[size];
}

/**
 * @brief Destroy the Symbol Table object
 * 
 */
SymbolTable::~SymbolTable()
{
  delete[] table;
}

/**
 * @brief Rehashes the table and updates the stored symbol table
 * 
 * @return true If the table rehashed successfully
 * @return false If the table failed to rehash
 */
bool SymbolTable::reHash()
{

  Symbol *tmp = new Symbol[2 * tablesize];
  tablesize *= 2;
  for (int i = 0; i < tablesize / 2; i++)
  {

    try
    {
      // Get the preferred location for this label
      string currentLabel = table[i].getLabel();
      // If there is nothing in this position skip this position
      if (currentLabel == "")
      {
        continue;
      }
      int targetPos = hashFunction(table[i].getLabel());

      // Loop up to the entire table size
      for (int j = 0; j < tablesize; j++)
      {
        // If there is a valid space (empty slot or deleted slot) insert a new Symbol at that location
        if (tmp[(targetPos + j) % tablesize].getLabel() == "D" || tmp[(targetPos + j) % tablesize].getLabel() == "")
        {
          tmp[(targetPos + j) % tablesize] = Symbol(table[i].getLabel(), table[i].getAddress());
          break;
        }
      }
    }

    catch (const std::exception &e)
    {
      return false;
    }
  }
  delete[] table;
  table = tmp;
  return true;
}

/**
 * @brief Hashes the label and returns the position in the Symbol Table. If there is no space in the Symbol Table or an error occurs, it returns -1
 * 
 * @param l 
 * @return int The position in the Symbol Table or a -1 if an error occurs
 */
int SymbolTable::hashFunction(string l)
{

  // Check if a label is passed in
  if (l.length() == 0)
  {
    return -1;
  }

  // Initialise the numbers to be used for the hash function
  const int p = 31;
  const int T = tablesize;

  // Inititalise a variable to be used to store the total of the hash function
  unsigned long int total = 0;

  // Store the length of the label passed into the function
  const int N = l.length();

  for (int i = 0; i <= N; i++)
  {
    /* 
        Add to the total with the function of:
        Character @ (Length - i) * p ^ (i)
        */
    total += int(l[N - i]) * pow(p, i);
  }

  if (total <= 0)
  {
    return -1;
  }

  // When all of the characters have been added together divide it by T and the result of the hash function is that remainder
  return total % T;
}

/**
 * @brief Inserts a Symbol to the Symbol table
 * 
 * @param l The label of the Symbol
 * @param a The address of the Symbol
 * @return true If the function succeeds in adding the Symbol
 * @return false If the function fails to add the Symbol
 */
bool SymbolTable::insert(string l, string a)
{

  if (l == "")
  {
    return false;
  }

  // If the symbol table is too occupied rehash the table

  if (currentSize / tablesize > 0.5)
  {
    bool reHashStatus = reHash();
    if (!reHashStatus)
    {
      return false;
    }
  }
  try
  {
    // Get the preferred location for this label
    int targetPos = hashFunction(l);
    // Loop up to the entire table size
    for (int i = 0; i < tablesize; i++)
    {
      // If there is already a node with this label return false
      if (table[(targetPos + i) % tablesize].getLabel() == l)
      {
        return false;
      }
      // If there is a valid space (empty slot or deleted slot) insert a new Symbol at that location
      if (table[(targetPos + i) % tablesize].getLabel() == "D" || table[(targetPos + i) % tablesize].getLabel() == "")
      {
        table[(targetPos + i) % tablesize] = Symbol(l, a);
        currentSize++;
        return true;
      }
    }
  }

  catch (const std::exception &e)
  {
    return false;
  }

  return true;
}

/**
 * @brief Returns the position of a label in the SymbolTable. Returns -1 if there is no label or an error occurs
 * 
 * @param l The label of the Symbol to search for
 * @return int The position of the label in the SymbolTable. -1 if an error occurs
 */
int SymbolTable::search(string l)
{
  // Make sure a valid label is passed in
  if (l == "")
  {
    return -1;
  }

  try
  {
    // Get the preferred location for this label
    int targetPos = hashFunction(l);
    // Loop up to the entire table size
    for (int i = 0; i < tablesize; i++)
    {
      // If the current slot is the key return true
      if (table[(targetPos + i) % tablesize].getLabel() == l)
      {
        return (targetPos + i) % tablesize;
      }

      // If you reach an empty slot the key is not in the table
      if (table[(targetPos + i) % tablesize].getLabel() == "")
      {
        return -1;
      }
    }
  }
  catch (const std::exception &e)
  {
    return false;
  }

  return -1;
}

/**
 * @brief Updates the address of the label. Returns false if label does not exist or another error occurs
 * 
 * @param l The label of the Symbol to update
 * @param a The new address for the Symbol
 * @return true If the function succeeds in updating the address of the Symbol
 * @return false If the function fails to update the address of the Symbol
 */
bool SymbolTable::update(string l, string a)
{
  // Make sure the label and address are valid
  if (l == "" || a == "")
  {
    return false;
  }

  const int result = search(l);
  if (result == -1)
  {
    return false;
  }
  table[result].setAddress(a);
  return true;
}

/**
 * @brief Returns the address of the Symbol with the given label
 * 
 * @param l The label of the Symbol to get the address of
 * @return string The address of the Symbol
 */

string SymbolTable::lookup(string l)
{
  // Make sure that the label is valid
  if (l == "")
  {
    return "";
  }

  const int result = search(l);
  if (result == -1)
  {
    return "";
  }
  return table[result].getAddress();
}

/**
 * @brief Overloads the output operator to display the Symbol Table for debugging
 * 
 * @param output The output stream
 * @param st The symbol table
 * @return ostream& The final output
 */
ostream &operator<<(ostream &output, const SymbolTable &st)
{
  for (int i = 0; i < st.tablesize; i++)
  {
    output << i << ":" << st.table[i].getLabel() << ":" << st.table[i].getAddress() << endl;
  }
  return output;
}