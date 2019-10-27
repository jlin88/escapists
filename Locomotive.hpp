//
// Created by Justin Lin on 2019-06-04.
//

/*********************************************************************
** Program name:  Locomotive.hpp
** Author:        Justin Lin
** Date:          06/04/2019
** Description:   This is the header file for the derived Locomotive class.
 *                There is one member variable that an integer.
 *                The constructor that will call the base Space class
 *                constructor and set pinsUnlatched to 0. Lastly, there are
 *                3 override methods. The name method returns the name of the
 *                class. The info method prints a description of the space.
 *                Lastly, the interactions method will provide a menu of options
 *                based upon the member variable. There is also a helper
 *                method that will 'unlatch' the train car if the player has
 *                the key item.
*********************************************************************/
#ifndef WEIGHTROOM_HPP
#define WEIGHTROOM_HPP


#include "Space.hpp"

class Locomotive : public Space {
private:
    int pinsUnlatched;
public:
    //  Ctor/Dtor
    Locomotive();
    ~Locomotive() {};

    //  Override methods
    std::string name() override;
    void info() override;
    Space* interactions(Character *player) override;

    //  Helper method interaction
    void unlatchCar(Character *player);
};


#endif //WEIGHTROOM_HPP
