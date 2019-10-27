//
// Created by Justin Lin on 2019-06-03.
//

/*********************************************************************
** Program name:  Space.hpp
** Author:        Justin Lin
** Date:          06/03/2019
** Description:   This is the header file for the base Space class. The
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
#ifndef SPACE_HPP
#define SPACE_HPP

#include "Character.hpp"

class Space {
private:
    Space *top,
          *right,
          *left,
          *bottom;

public:
    //  Ctor/Dtor
    Space();
    virtual ~Space() {};

    //  Setter/Getters for links
    void setTop(Space *room);
    Space *getTop();

    void setRight(Space *room);
    Space *getRight();

    void setLeft(Space *room);
    Space *getLeft();

    void setBottom(Space *room);
    Space *getBottom();

    //  Polymorphic pure virtual methods
    virtual std::string name() = 0;
    virtual void info() = 0;
    virtual Space* interactions(Character *player) = 0;
};


#endif //SPACE_HPP
