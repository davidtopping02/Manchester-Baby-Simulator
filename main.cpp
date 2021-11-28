/**
 * @file main.cpp
 * @author David Topping, Christian Zlatanov, Mathew Gallahcher
 * @brief file with main function and other relevant functions 
 * @version 0.1
 * @date 2021-11-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <cstdint>
#include "main.h"
#include "memoryLocations.h"
using namespace std;

#define SIZE = 32;
/**
 * @brief main method
 * 
 * @return SUCCESS
 * @return ERROR
 */

int main()
{
    //initialise local variables
    bool finished = false;
    int iteration = 0;

    //opcode and operand
    int operand;
    string opcode;

    // declare memory locations
    Store theStore;
    Register CI;
    Register PI;
    Register Accumulator;

    //reading in the machine code
    readInMachineCode(&theStore);

    //temporary tester integers
    int test1 = 0;
    int test2 = 0;
    //running the fetch execute cycle
    while (finished != true)
    {
        //Increment the CI REGISTER
        increment_CI(&CI);

        //2. Fetch - CI points to store where instruction is fetched.
        fetch(&CI, &PI, &theStore);

        //3. Decode and fetch operands if needed.
        decode(&PI, &opcode, &operand);

        //4. Execute.

        //halting if the opcode is STP
        if (opcode == "STP")
        {
            finished = true;
        }

        iteration++;
    }
}

/**
 * @brief Increments the CI register by one 
 * 
 * @param CI 
 */
void increment_CI(Register *CI)
{
    //creating bitset from CI register
    bitset<32> ciBitset;

    //copying the CI register into the bitset
    for (int i = 0; i < 32; i++)
    {
        if (CI->getLocation(i) == 1)
        {
            ciBitset[i] = 1;
        }
        else
        {
            ciBitset[i] = 0;
        }
    }

    //helper function to increment the bitest
    ciBitset = increment(ciBitset);

    //copying the bitset into the CI register
    string ciStr = ciBitset.to_string();
    for (int i = 0; i < 32; i++)
    {
        if (ciStr[31 - i] == '1')
        {
            CI->setLocation(i, 1);
        }
        else
        {
            CI->setLocation(i, 0);
        }
    }
};

/**
 * @brief this method increments a bitset by one, credit is given for inspiration to this function
 * 
 * @author https://stackoverflow.com/questions/16761472/how-can-i-increment-stdbitset
 * @tparam N 
 * @param in 
 * @return std::bitset<N> 
 */
template <size_t N>
std::bitset<N> increment(std::bitset<N> in)
{
    //  add 1 to each value, and if it was 1 already, carry the 1 to the next.
    for (size_t i = 0; i < N; ++i)
    {
        if (in[i] == 0)
        { // There will be no carry
            in[i] = 1;
            break;
        }
        in[i] = 0; // This entry was 1; set to zero and carry the 1
    }
    return in;
}

/**
 * @brief fetch PI from store depending on CI
 *
 * @return SUCCESS
 * @return ERROR
 */
void fetch(Register *CI, Register *PI, Store *theStore)
{

    //convert the CI to an int
    int storeLocation = 0;

    for (int i = 0; i < 32; i++)
    {
        if (CI->getLocation(i) == 1)
        {
            storeLocation += pow(2, i);
        }
    }

    //get the array register from the store location based on the CI
    bool tempPi[32];

    for (int i = 0; i < 32; i++)
    {
        tempPi[i] = theStore->getRegisterLocation((storeLocation - 1), i);
    }

    // put the instruction from the store into the PI
    for (int i = 0; i < 32; i++)
    {
        PI->setLocation(i, tempPi[i]);
    }
};

/**
 * @brief wrapper function to decode the operand and the opcode
 * 
 * @param CI 
 */
void decode(Register *CI, string *opcode, int *operand)
{
    //storing the opcode and operand in the pointers'variable
    *operand = decodeOperand(CI);
    *opcode = decodeOpcode(CI);

    //PRINTING FOR TESTING
    cout << "\nOperand: " << *operand << endl;
    cout << "Opcode: " << *opcode << endl;
}

/**
 * @brief decode the operand
 *
 * @param register
 * @return operand
 */
int decodeOperand(Register *PI)
{
    int operand = 0;

    for (int j = 0; j < 13; j++)
    {
        //computes MyNum by iterating through the register
        operand += PI->getLocation(j) * pow(2, j);
    }

    return operand;
}

/**
 * @brief decode the instruction
 *
 * @param register
 * @return instruction value
 */
string decodeOpcode(Register *PI)
{
    //getting the opcode from the 13th,14th,15th position of the present instruction register
    bool a = PI->getLocation(13);
    bool b = PI->getLocation(14);
    bool c = PI->getLocation(15);

    //compares bool code and returns
    if (a == 0 && b == 0 && c == 0)
    {
        return "JMP";
    }
    if (a == 1 && b == 0 && c == 0)
    {
        return "JRP";
    }

    if (a == 0 && b == 1 && c == 0)
    {
        return "LDN";
    }

    if (a == 1 && b == 1 && c == 0)
    {
        return "STO";
    }

    if (a == 0 && b == 0 && c == 1)
    {
        return "SUB";
    }

    if (a == 1 && b == 0 && c == 1)
    {
        return "SUB";
    }
    if (a == 0 && b == 1 && c == 1)
    {
        return "CMP";
    }
    if (a == 1 && b == 1 && c == 1)
    {
        return "STP";
    }

    //error code if failure
    return "ERR";
}

int execute(){

};

/**
 * @brief Reads in the machine code text file and stores it in a vector of registers
 * 
 * @param machineCode 
 */
void readInMachineCode(Store *theStore)
{
    // Create a text string, which is used to get each line
    string line;
    int storeReg = 0;

    // Read from the text file
    ifstream MyReadFile("BabyTest1-MC.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, line))
    {
        for (int i = 0; i < 32; i++)
        {

            if (line[i] == '0')
            {
                theStore->setRegiserLocation(storeReg, i, 0);
            }
            else if (line[i] == '1')
            {
                theStore->setRegiserLocation(storeReg, i, 1);
            }
        }
        storeReg++;
    }

    // Close the file
    MyReadFile.close();
}
