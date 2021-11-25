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
#include <bitset>
#include <bits/stdc++.h>
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

    // declare registers
    Register CI;
    Register PI;
    Register Accumulator;

    //reading in the machine code
    vector<Register> machineCode;
    readInMachineCode(&machineCode);

    //running the fetch execute cycle
    while (finished != true)
    {
        //Increment the CI REGISTER
        increment_CI(&machineCode, &CI, iteration);

        //2. FETCH - CI points to storeage where instruction is fetched.

        //3. Decode and fetch operands if needed.

        //4. Execute.

        //5. GO back to 1

        iteration++;
    }
}

/**
 * decodes instruction
 *
 * @param bool a, bool b, bool c
 *
 * @return SUCCESS
 * @return ERROR
 */

int decodeInstruction(bool a, bool b, bool c)
{

    // if (a == false && b == false && c == false)
    // {
    //     //set CI CONTENT TO STORE LOCATION
    //     CI = S;
    // }
    // if (a == true && b == false && c == false)
    // {
    //     //add content of Store location to CI
    //     CI = CI + S
    // }

    // if (a == false && b == true && c == false)
    // {
    //     //load Accumulator with negative form of Store content
    //     A = -S
    // }
    // if (a == true && b == true && c == false)
    // {
    //     //copy Accumulator to STore location
    //     S = A
    // }
    // if (a == false && b == false && c == true)
    // {
    //     //subtract content of STore Location from Accumulator
    //     A = A - S
    // }
    // if (a == true && b == false && c == true)
    // {
    //     //as for 4
    //     A = A - S //?
    // }
    // if (a == false && b == true && c == true)
    // {
    //     //increment CI if Accumulator value negative, otherwise do nothing
    //     if (A <)
    //     {
    //         CI = CI + 1
    //     }
    // }
    // if (a == true &&b = true && c == true)
    // {
    //     //Halt Machine
    // }
}

/**
 * @brief decode the operand
 *
 * @return SUCCESS
 * @return ERROR
 */
int decodeOperand()
{
}

/**
 * @brief increments CI register
 * 
 * @param machineCode 
 * @param iteration 
 */
void increment_CI(vector<Register> *machineCode, Register *CI, int iteration)
{
    //iterating through the CI register
    for (int i = 0; i < 32; i++)
    {
        CI->setLocation(i, machineCode->at(iteration).getLocation(i));
    }
};

/**
 * @brief fetch instruction/operand from store
 *
 * @return SUCCESS
 * @return ERROR
 */
int fetch(){

};

/**
 * @brief execute based on instruction and operand
 *
 * @return SUCCESS
 * @return ERROR
 */
int execute(){

};

/**
 * @brief Reads in the machine code text file and stores it in a vector of registers
 * 
 * @param machineCode 
 */
void readInMachineCode(vector<Register> *machineCode)
{
    // Create a text string, which is used to get each line
    string line;

    // Read from the text file
    ifstream MyReadFile("BabyTest1-MC.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, line))
    {
        Register tempReg;

        for (int i = 0; i < 32; i++)
        {

            if (line[i] == '0')
            {
                tempReg.setLocation(i, 0);
            }
            else if (line[i] == '1')
            {
                tempReg.setLocation(i, 1);
            }
        }
        machineCode->push_back(tempReg);
    }

    // Close the file
    MyReadFile.close();
}