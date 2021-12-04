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
        if (choice < 0 || choice > 5)
        {
            cout << "ERROR: enter a valid option"
                 << endl;
        }

        cout << "Option: ";
        cin >> choice;
        cout << endl;

    } while (choice < 0 || choice > 5);

    // switch for the menu options
    switch (choice)
    {
    case 0:
        cout << "Thank you for using the Manchester Baby simulator" << endl;
        cout << "exiting..." << endl;

        // exit command
        exit(EXIT_SUCCESS);
        break;
    case 1:
        // code block
        break;
    case 2:
        // code block
        break;

    case 3:
        // code block
        break;
    case 4:
        // code block
        break;
    case 5:
        // code block
        break;
    default:
        cout << "ERROR: invalid input" << endl;
    }
}
