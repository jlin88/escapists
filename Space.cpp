//
// Created by Justin Lin on 2019-06-03.
//

/*********************************************************************
** Program name:  Space.cpp
** Author:        Justin Lin
** Date:          06/03/2019
** Description:   This is the implementation file for the base Space class. The
 *                class has four member variables that are all Space
 *                pointers representing the links to the new space.
 *                The game is linear so only the left and right pointers
 *                are used, so the top and bottom are always nullptr.
 *                The class includes a constructor that will set all
 *                Space pointers to nullptr and a virtual destructor.
 *                There are setter/getters for each of the Space pointers.
 *                Lastly, there are 3 pure virtual methods making the
 *                Space class an abstract class. There will be polymorphic
 *                methods that will have unique implementations in each
 *                derived Space class.
*********************************************************************/
#include "Space.hpp"
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

/*******************************************************************************
Name:         Justin Lin
Called by:    N/A
Calls:        N/A
Passed:       N/A
Returns:      N/A

Description:  This method is the default constructor for the Space class. It
              sets all the links to nullptr. This constructor will be inherited
              by derived classes and used to initialize base class member
              variables.
*******************************************************************************/
Space::Space() : top(nullptr), right(nullptr), left(nullptr), bottom(nullptr) {}

//  Setter for top link
void Space::setTop(Space *room) {
    this->top = room;
}

//  Getter for top link
Space* Space::getTop() {
    return top;
}

//  Setter for right link
void Space::setRight(Space *room) {
    this->right = room;
}

//  Getter for right link
Space* Space::getRight() {
    return right;
}

//  Setter for left link
void Space::setLeft(Space *room) {
    this->left = room;
}

//  Getter for left link
Space* Space::getLeft() {
    return left;
}

//  Setter for bottom link
void Space::setBottom(Space *room) {
    this->bottom = room;
}

//  Getter for bottom link
Space* Space::getBottom() {
    return bottom;
}

