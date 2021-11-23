/**
 * @file main.h
 * @author David Topping, Christian Zlatanov, Mathew Gallahcher
 * @brief file with function declarations for main.cpp 
 * @version 0.1
 * @date 2021-11-22
 * 
 * @copyright Copyright (c) 2021 
 */

using namespace std;

//main function that houses the fetch-execute cycle
int main();

//decodes the intruction from the store
int decodeInstruction(bool a, bool b, bool c);

//decodes operand from the store
int decodeOperand();

//increments our CI register
int increment_CI();

//fetches relevant array from store
int fetch();

//executes the intstruction based on operands given
void execute();

//funciton to display a register
int display_everything();