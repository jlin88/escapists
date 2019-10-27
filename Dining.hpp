//
// Created by Justin Lin on 2019-06-07.
//

/*********************************************************************
** Program name:  Dining.hpp
** Author:        Justin Lin
** Date:          06/07/2019
** Description:   This is the header file for the derived Dining class.
 *                The class has two member variables that are all bools
 *                that will represent if the player has satisfied a
 *                condition. The constructor that will call the base
 *                Space class constructor and set hasEaten and hasTraded
 *                to false. Lastly, there are 3 override methods.
 *                The name method returns the name of the class. The info
 *                method prints a description of the cell. Lastly, the
 *                interactions method will provide a menu of options based upon
 *                the bool member variables. There are also two helper methods
 *                eat and mustache that take as arguments a pointer to a
 *                Character representing the player.
*********************************************************************/
#ifndef DINING_HPP
#define DINING_HPP


#include "Space.hpp"

class Dining : public Space {
    bool hasEaten;
    bool hasTraded;
public:
    //  Ctor/Dtor
    Dining();
    ~Dining() {};

    //  Override methods
    std::string name() override;
    void info() override;
    Space *interactions(Character *player) override;

    //  Helper interaction methods
    void eat(Character *player);
    void mustache(Character *player);
};


#endif //DINING_HPP
