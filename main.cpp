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
using namespace std;

#define SIZE = 32;
/**
 * @brief main method
 * 
 * @return SUCCESS
 * @return ERROR
 */

// int main()
// {

//     Register CI;
//     Register PI;
//     Register Accumulator;

//     //1. Increment your CI REGISTER
//     int increment_CI();
//     //2. FETCH - CI points to storeage where instruction is fetched.
//     int fetch();
//     //3. Decode and fetch operands if needed.
//     int decodeInstruction();
//     int decode Operand();
//     //4. Execute.
//     void execute();
//     void display_everything();
//     //5. GO back to 1
// }

// /**
//  * decodes instruction
//  *
//  * @param bool a, bool b, bool c
//  *
//  * @return SUCCESS
//  * @return ERROR
//  */

// int decodeInstruction(bool a, bool b, bool c)
// {

//     if (a == false && b == false && c == false)
//     {
//         //set CI CONTENT TO STORE LOCATION
//         CI = S;
//     }
//     if (a == true && b == false && c == false)
//     {
//         //add content of Store location to CI
//         CI = CI + S
//     }

//     if (a == false && b == true && c == false)
//     {
//         //load Accumulator with negative form of Store content
//         A = -S
//     }
//     if (a == true && b == true && c == false)
//     {
//         //copy Accumulator to STore location
//         S = A
//     }
//     if (a == false && b == false && c == true)
//     {
//         //subtract content of STore Location from Accumulator
//         A = A - S
//     }
//     if (a == true && b == false && c == true)
//     {
//         //as for 4
//         A = A - S //?
//     }
//     if (a == false && b == true && c == true)
//     {
//         //increment CI if Accumulator value negative, otherwise do nothing
//         if (A <)
//         {
//             CI = CI + 1
//         }
//     }
//     if (a == true &&b = true && c == true)
//     {
//         //Halt Machine
//     }
// }

// /**
//  * @brief decode the operand
//  *
//  * @return SUCCESS
//  * @return ERROR
//  */

// int decodeOperand()
// {
// }

// /**
//  * @brief increment CI counter
//  *
//  * @return SUCCESS
//  * @return ERROR
//  */

// int increment_CI(){};

// /**
//  * @brief fetch instruction/operand from store
//  *
//  * @return SUCCESS
//  * @return ERROR
//  */
// int fetch(){};

// /**
//  * @brief execute based on instruction and operand
//  *
//  * @return SUCCESS
//  * @return ERROR
//  */
// int execute(){};

// /**
//  * @brief display a register
//  *
//  * @return SUCCESS
//  * @return ERROR
//  */
// int display_everything()
// {
//     //loop through the register and print every value
//     for (int i = 0; i < SIZE; i++)
//     {

//         //loop through array and print
//     }
// };