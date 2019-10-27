//
// Created by Justin Lin on 2019-06-06.
//

/*********************************************************************
** Program name:  Security.hpp
** Author:        Justin Lin
** Date:          06/06/2019
** Description:   This is the header file for the derived Security class.
 *                The constructor that will call the base Space class
 *                constructor. Lastly, there are 3 override methods.
 *                The name method returns the name of the class. The info
 *                method prints a description of the cell. Lastly, the
 *                interactions method will provide a menu of options based upon
 *                the bool member variables. There is also a helper method that
 *                will check if the player has the required items to proceed.
*********************************************************************/
#ifndef SECURITY_HPP
#define SECURITY_HPP


#include "Space.hpp"

class Security : public Space {
public:
    //  Ctor/Dtor
    Security();
    ~Security() {};

    //  Override methods
    std::string name() override;
    void info() override;
    Space* interactions(Character *player) override;

    //  Uniform check helper interaction
    bool uniformCheck(Character *player);

};


#endif //SECURITY_HPP
