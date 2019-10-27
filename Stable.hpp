//
// Created by Justin Lin on 2019-06-06.
//

/*********************************************************************
** Program name:  Stable.hpp
** Author:        Justin Lin
** Date:          06/03/2019
** Description:   This is the header file for the derived Stable class.
 *                The class has two member variables that are both bools
 *                that will represent if the player has satisfied a
 *                condition. The constructor that will call the base
 *                Space class constructor and set horseFed and carrotTaken
 *                to false. Lastly, there are 3 override methods. The name
 *                method returns the name of the class. The info method prints
 *                a description of the cell. Lastly, the interactions method
 *                will provide a menu of options based upon the bool member
 *                variables.
*********************************************************************/
#ifndef STABLE_HPP
#define STABLE_HPP


#include "Space.hpp"

class Stable : public Space {
private:
    bool horseFed;
    bool carrotTaken;
public:
    Stable();
    ~Stable() {};

    // Override methods
    std::string name() override;
    void info() override;
    Space *interactions(Character *player) override;
};


#endif //STABLE_HPP
