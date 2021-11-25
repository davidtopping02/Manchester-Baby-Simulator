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

int decodeInstruction(bool a, bool b, bool c);

int decodeOperand();

/**
 * @brief increments CI register
 * 
 * @param machineCode 
 * @param iteration 
 */
void increment_CI(vector<Register> *machineCode, Register *CI, int iteration);

int fetch();

int execute();

/**
 * @brief Reads in the machine code text file and stores it in a vector of registers
 * 
 * @param machineCode 
 */
void readInMachineCode(vector<Register> *machineCode);

#endif //MAIN_H