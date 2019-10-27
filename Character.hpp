//
// Created by Justin Lin on 2019-06-03.
//

/*********************************************************************
** Program name:  Character.hpp
** Author:        Justin Lin
** Date:          06/03/2019
** Description:   This is the header file for the Character class. It
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
#ifndef CHARACTER_HPP
#define CHARACTER_HPP


#include <string>

class Character {
private:
    int hp,
        numItems;

    std::string items[5];

    bool hasKey,
         hasCrowbar,
         hasUniform,
         hasCarrot,
         hasMustache;

public:
    //  Ctor/Dtor
    Character();
    ~Character() {};

    //  Setter/Getter for player hp
    void setHP(int hp);
    int getHP();

    //  Getters for key items
    bool getKey();
    bool getCrowbar();
    bool getUniform();
    bool getCarrot();
    bool getMustache();

    //  Item management methods
    void takeItem(std::string item);
    void checkItems();
    void removeItem(std::string item);

    //  Displays player statuses
    void inventory();
    void stats();
};


#endif //CHARACTER_HPP
