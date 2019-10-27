//
// Created by Justin Lin on 2019-06-03.
//

/*********************************************************************
** Program name:  Character.cpp
** Author:        Justin Lin
** Date:          06/03/2019
** Description:   This is the implementation file for the Character class. It
 *                has as member variables two ints representing hp
 *                and number of items. It has a string array with a max
 *                size of 5 representing the inventory of a Character.
 *                There are also 5 bools representing flags to indicate
 *                if the player has a certain key item. There is a Ctor
 *                that sets the starting values of each of the member variables.
 *                The player starts with 10hp, and 1 item (a pencil), and the
 *                bools are set to false. There are setters/getters for the hp
 *                and getters for the bool variables. There is a takeItem
 *                method that takes in as an argument a string and adds the item
 *                to the player inventory. There is a removeItem method that
 *                takes as an argument a string and removes the item from the
 *                player's inventory. There is a checkItem method that will
 *                loop through the player's inventory and set the flags based
 *                upon the items in inventory. Lastly there is a method to
 *                print the inventory and the player's stats.
*********************************************************************/
#include "Character.hpp"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

/*******************************************************************************
Name:         Justin Lin
Called by:    N/A
Calls:        N/A
Passed:       N/A
Returns:      N/A

Description:  This is the default constructor for the Character class. The
              constructor sets starting hp to 10, number of items to 1,
              initializes the item array to contain a Pencil, and all the bool
              values to false.
*******************************************************************************/
Character::Character() : hp(10), numItems(1), items{"Pencil", "", "", "", ""},
                         hasKey(false), hasCrowbar(false), hasUniform(false),
                         hasCarrot(false) {}


//  Setter for hp
void Character::setHP(int hp) {
    this->hp = hp;
}

//  Getter for hp
int Character::getHP() {
    return hp;
}

//  Getter for key
bool Character::getKey() {
    return hasKey;
}

//  Getter for crowbar
bool Character::getCrowbar() {
    return hasCrowbar;
}

//  Getter for uniform
bool Character::getUniform(){
    return hasUniform;
}

//  Getter for carrot
bool Character::getCarrot() {
    return hasCarrot;
}

//  Getter for fake mustache
bool Character::getMustache() {
    return hasMustache;
}

/*******************************************************************************
Name:         Justin Lin
Called by:    Dining::interactions, Stable::interactions, Cell::interactions,
              Cargo::interactions
Calls:        N/A
Passed:       string
Returns:      N/A

Description:  This method allows the user to pick up an item and add it to
              their inventory. If the inventory is full, the method will print
              an error message letting the user know their inventory is full.
              It takes in a string representing the item name as an argument
              and adds it to the items array.
*******************************************************************************/
//  Pick up item
void Character::takeItem(string item) {
    //  If player has space add item to inventory
    if (numItems < 5) {
        items[numItems] = item;
        numItems++;

    //  Player inventory is max
    } else {
        cout << "You think you can fit that in your pockets? Drop something!"
             << endl;
    }
}

/*******************************************************************************
Name:         Justin Lin
Called by:    Dining::interactions, Stable::interactions, Cell::interactions,
              Cell::openCell, Cargo::interactions, Dining::mustache
Calls:        N/A
Passed:       N/A
Returns:      N/A

Description:  This method checks the user's inventory for key items in the game
              and sets the respective bool flags to true if the player has the
              item.
*******************************************************************************/
//  Checks player's inventory for key items
void Character::checkItems() {
    for (int i = 0; i < numItems; i++) {
        if (items[i] == "Cell Key") {
            hasKey = true;
        }
        if (items[i] == "Crowbar") {
            hasCrowbar = true;
        }
        if (items[i] == "Guard Uniform") {
            hasUniform = true;
        }
        if (items[i] == "Carrot") {
            hasCarrot = true;
        }
        if (items[i] == "Fake mustache") {
            hasMustache = true;
        }
    }
}

/*******************************************************************************
Name:         Justin Lin
Called by:    Cell::interactions(), Cell::openCell(), Dining::mustache
Calls:        N/A
Passed:       string
Returns:      N/A

Description:  This method takes in a string argument representing the item name
              that is to be removed and removes it from the player's inventory
              if it exists. Then, it will shift the remaining items in the
              array over so there is not a gap in the array.
*******************************************************************************/
void Character::removeItem(string item) {
    for (int i = 0; i < numItems; i++) {
        if (items[i] == item) {
            items[i] = "";
            numItems--;

            //  Moves remaining items over
            for (i; i < numItems; i++) {
                items[i] = items[i+1];
            }

        }
    }
}

/*******************************************************************************
Name:         Justin Lin
Called by:    interactions()
Calls:        N/A
Passed:       N/A
Returns:      N/A

Description:  This method prints the contents of the player's inventory to the
              screen.
*******************************************************************************/
//  Prints contents of player's inventory
void Character::inventory() {
    cout << "[Inventory  " << numItems << "/5]" << endl;
    for (int i = 0; i < numItems; i++) {
        cout << "  " << i+1 << ". " << items[i] << endl;
    }
    cout << endl;
}

/*******************************************************************************
Name:         Justin Lin
Called by:    interactions()
Calls:        N/A
Passed:       N/A
Returns:      N/A

Description:  This method prints the player's hp to the screen showing the user
              how many moves (hp) is left. Hp is represented by hearts.
*******************************************************************************/
//  Prints stats represented by unicode symbols
void Character::stats() {
    cout << "[Stats]" << endl;

    //  Unicode symbol for hearts to represent hp
    cout << "  Health: ";
    for (int i = 0; i < hp; i++) {
        cout << "\u2665 ";
    }
    cout << "\n" << endl;
}