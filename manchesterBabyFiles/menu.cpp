/**
 * @file menu.cpp
 * @author David Topping, Christian Zlatanov, Mathew Gallahcher
 * @brief This file holds the user menu for the manchester baby
 * @version 0.1
 * @date 2021-11-29
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>
#include "manchesterBaby.h"
#include "memoryLocations.h"
using namespace std;

/**
 * @brief Main menu where the user can select which option they want to run
 *
 */
void menu()
{
    // init local variables
    int choice;

    // menu choices
    cout << "Please select from one of the following options" << endl;

    cout << "0. Exit" << endl;
    cout << "1. Run the manchester baby (default)" << endl;
    cout << "2. Run the manchester (custom store size)" << endl;
    cout << "3. Run the assembler" << endl;
    cout << "4." << endl;
    cout << "5.\n"
         << endl;

    do
    {
        cout << "Option: ";
        cin >> choice;
        cout << endl;

        if (choice < 0 || choice > 5)
        {
            cout << "ERROR: enter a valid option"
                 << endl;
        }

    } while (choice < 0 || choice > 5);

    // running the menu options
    if (choice == 0)
    {
        cout << "Thank you for using the Manchester Baby simulator" << endl;
        cout << "Exting...\n"
             << endl;
        exit(EXIT_SUCCESS);
    }
    if (choice == 1)
    {
        // running default manchester baby
        Store *theStore = new Store;
        manchesterBabySimulator(theStore);
    }
    else if (choice == 2)
    {
        // running manchester baby with custom store size
        int size;

        cout << "Enter a store size (must be greater than 8)" << endl;

        do
        {
            cout << "Size: ";
            cin >> size;
            cout << endl;

            if (size < 8)
            {
                cout << "ERROR: enter a valid option"
                     << endl;
            }
        } while (size < 8);

        Store *theStore = new Store(size);
        manchesterBabySimulator(theStore);
    }
}

/**
 * @brief Main function where the menu is called
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char const *argv[])
{
    menu();
    return 0;
}
