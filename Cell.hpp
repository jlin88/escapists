//
// Created by Justin Lin on 2019-06-04.
//
/*********************************************************************
** Program name:  Cell.hpp
** Author:        Justin Lin
** Date:          06/03/2019
** Description:   This is the header file for the derived Cell class. The
 *                class has two member variables that are both bools
 *                that will represent if the player has satisfied a
 *                condition. The constructor that will call the base
 *                Space class constructor and set cellOpened and invChecked
 *                to false. There are setter/getters for each of the member
 *                variables. Lastly, there are 3 override methods. The name
 *                method returns the name of the class. The info method prints
 *                a description of the cell. Lastly, the interactions method
 *                will provide a menu of options based upon the bool member
 *                variables.
*********************************************************************/
#ifndef CELL_HPP
#define CELL_HPP


#include "Space.hpp"

class Cell : public Space {
private:
    bool cellOpened;
    bool invChecked;
public:
    //  Ctor/Dtor
    Cell();
    ~Cell() {};

    //  Override methods
    std::string name() override;
    void info() override;
    Space *interactions(Character *player) override;

    //  Unique helper interactions for Cell class
    void start();
    void openCell(Character *player);
};


#endif //CELL_HPP
