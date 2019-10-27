//
// Created by Justin Lin on 2019-04-10.
//
/*********************************************************************
** Program name:  inBounds.h
** Author:        Justin Lin
** Date:          04/10/2019
** Description:   This is the header file for a bounds checking
 *                function. This function takes as parameters 3 integers,
 *                the number to validate, a minimum, and a maximum.
 *                The function will return true if the function is in
 *                the range of the min and max inclusive. If the input
 *                number is out of range, the function will return false
 *                and print an error message. This is used in conjunction
 *                with the integerValidation function to return an integer
 *                that is in the correct range of inputs.
*********************************************************************/

#ifndef INBOUNDS_HPP
#define INBOUNDS_HPP

bool inBounds(int input, int min, int max);

#endif //INBOUNDS_HPP
