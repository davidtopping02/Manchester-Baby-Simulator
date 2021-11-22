/**
 * @file memoryLocations.cpp
 * @author David Topping, Christian Zlatanov, Mathew Gallahcher
 * @brief register class that has an array representing a 32 bit memory storage 
 * @version 0.1
 * @date 2021-11-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include "memoryLocations.h"
using namespace std;

Register::Register(){

    for (int i = 0; i < 32; i++)
    {
        this->setLocation(i, false);
    }
    
}

/**
 * @brief gets the 32 position loacation array
 * 
 * @return true 
 * @return false 
 */
bool Register::getLocation()
{
    return this->location;
}

/**
 * @brief sets an value 'true(1) or false(0)' for an indivual memory location
 * 
 * @param n 
 * @param pos 
 */
void Register::setLocation(int n, bool pos)
{
    this->location[n] = pos;
}

/**
 * @brief copys a full register into the specified store location
 * 
 * @param inputRegister 
 * @param reg 
 */
void Register::setRegister(bool inputRegister[])
{
    for (int i = 0; i < 32; i++)
    {
       this->setLocation(i, inputRegister[i]);
    }
}