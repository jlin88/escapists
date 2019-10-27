//
// Created by Justin Lin on 2019-04-10.
//
/*********************************************************************
** Program name:  inBounds.cpp
** Author:        Justin Lin
** Date:          04/10/2019
** Description:   This is the implementation file for a bounds checking
 *                function. This function takes as parameters 3 integers,
 *                the number to validate, a minimum, and a maximum.
 *                The function will return true if the function is in
 *                the range of the min and max inclusive. If the input
 *                number is out of range, the function will return false
 *                and print an error message. This is used in conjunction
 *                with the integerValidation function to validate an input
 *                as an integer that is in the correct range of inputs.
*********************************************************************/
#include "inBounds.hpp"
#include <iostream>
using std::cout;
using std::endl;

bool inBounds(int input, int min, int max) {
    //  Returns true if within min/max range.
    if ((input >= min) && (input <= max)) {
        return true;
    }
    else {
        cout << "Error: Value not in range. Please enter an integer between "
            << min << " and " << max << endl;
        return false;
    }
}
