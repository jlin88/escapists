//
// Created by Justin Lin on 2019-04-09.
//

/*********************************************************************
** Program name:  integerValidation.cpp
** Author:        Justin Lin
** Date:          04/09/2019
** Description:   This is the implementation file for the a modular
 *                integer input validation. The function will ask for
 *                a user input and check to see if it is an integer.
 *                The input is taken as a string and converted into a
 *                stringstream object. It then is passed to an integer
 *                variable using the extraction operator. If it is
 *                passed successfully to the integer variable and
 *                there is nothing remaining in the string input,
 *                the integer will be returned. Otherwise, an error
 *                message will be printed and the program will loop
 *                until an integer input is received.
*********************************************************************/

// Adapted from: http://www.cplusplus.com/forum/beginner/170685/#msg851160
#include "integerValidation.hpp"
#include <iostream>
#include <string>
#include <sstream>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::stringstream;

int integerValidation() {

    string input = "";
    int integer = 0;

    while (true) {
        getline(cin, input);
        stringstream convert(input);

        //  Checks to see if the full string was converted. If there is
        //  something left in the string input, that means the input is not
        //  an integer.
        if ((convert >> integer) && !(convert >> input)) {
            return integer;
        }
        cout << "Error: Please enter a valid integer." << endl;
    }
}
