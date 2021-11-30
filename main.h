/**
 * @file main.h
 * @author David Topping, Christian Zlatanov, Mathew Gallahcher
 * @brief file with function declarations for main.cpp 
 * @version 0.1
 * @date 2021-11-22
 * 
 * @copyright Copyright (c) 2021 
 */
#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <bitset>
#include <bits/stdc++.h>
#include "main.h"
#include "memoryLocations.h"
using namespace std;

int main();

/**
 * @brief wrapper function to decode the operand and the opcode
 * 
 * @param CI 
 */
void decode(Register *CI, string *opcode, int *operand);

/**
 * @brief decode the operand
 *
 * @param register
 * @return operand
 */
int decodeOperand(Register *PI);

/**
 * @brief decode the instruction
 *
 * @param register
 * @return instruction value
 */
string decodeOpcode(Register *PI);

/**
 * @brief Increments the CI register by one 
 * 
 * @param CI 
 */
void increment_CI(Register *CI);

/**
 * @brief this method increments a bitset by one, credit is given for inspiration to this function
 * 
 * @author https://stackoverflow.com/questions/16761472/how-can-i-increment-stdbitset
 * @tparam N 
 * @param in 
 * @return std::bitset<N> 
 */
template <size_t N>
std::bitset<N> increment(bitset<N> in);

void fetch(Register *CI, Register *PI, Store *theStore);

int execute();

/**
 * @brief Reads in the machine code text file and puts all instructions in the store
 * 
 * @param machineCode 
 */
void readInMachineCode(Store *theStore);

#endif //MAIN_H