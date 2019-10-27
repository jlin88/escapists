//
// Created by Justin Lin on 2019-06-05.
//

/*********************************************************************
** Program name:  Cargo.cpp
** Author:        Justin Lin
** Date:          06/03/2019
** Description:   This is the header file for the derived Cargo class.
 *                The class has three member variables that are all bools
 *                that will represent if the player has satisfied a
 *                condition. The constructor that will call the base
 *                Space class constructor and set guardDefeated and skipGuard
 *                and searched to false. Lastly, there are 3 override methods.
 *                The name method returns the name of the class. The info
 *                method prints a description of the cell. Lastly, the
 *                interactions method will provide a menu of options based upon
 *                the bool member variables.
*********************************************************************/
#ifndef CARGO_HPP
#define CARGO_HPP


#include "Space.hpp"

class Cargo : public Space {
    bool guardDefeated,
         skipGuard,
         searched;
public:
    //  Ctor/Dtor
    Cargo();
    ~Cargo() {};

    //  Override methods
    std::string name() override;
    void info() override;
    Space* interactions(Character *player) override;
};


#endif //CARGO_HPP
