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

/**
 * @brief Construct a new Register:: Register object
 * 
 */
Register::Register()
{

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
bool Register::getLocation(int x)
{
    return location[x];
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

/**
 * @brief gets the bool array
 * 
 * @return true 
 * @return false 
 */
bool Register::getRegister()
{
    return this->location;
}

/**
 * @brief sets a specific memory location in the store to be on or off
 * 
 * @param reg 
 * @param regLocation 
 * @param pos 
 * @return true 
 * @return false 
 */
bool Store::setRegiserLocation(int reg, int regLocation, bool pos)
{
    this->storeRegister[reg].setLocation(regLocation, pos);

    if (this->storeRegister[reg].getLocation(regLocation) == pos)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Store::getRegisterLocation(int reg, int loc)
{
    return this->storeRegister[reg].getLocation(loc);
}

ostream& operator<<(ostream &output, const Register &Reg){

        for(int i = 0; i < 32; i++){
                output << Reg.getLocation(i) <<"," << endl;             

        }
        return output;
}

ostream& operator<<(ostream &outupt, const Store &St){

        
        for(int j = 0; j < 32; j++){
                for (int i = 0; i < 32; i++){ 
                //there is an error here
                bool myBool = St.getRegisterLocation(j, i);   
                output << myBool << "," << endl;
                }
                output << endl;
        }
        return output;
} 
