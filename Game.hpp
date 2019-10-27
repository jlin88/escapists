//
// Created by Justin Lin on 2019-06-05.
//

/*********************************************************************
** Program name:  Game.hpp
** Author:        Justin Lin
** Date:          06/05/2019
** Description:   This is the header file for the Game class. The class
 *                has several member variables, a Character pointer representing
 *                the player, 6 Space pointers representing each of the derived
 *                spaces, and a bool flag to see if the player has escaped.
 *                There is a constructor that initializes the pointers with
 *                dynamically allocated memory, and sets escaped to false.
 *                The destructor conversely, will delete all the allocated
 *                memory. There are five methods used to print information
 *                about the game. There is a void method mapSetup that sets
 *                the links between each of the derived Spaces. Lastly, there
 *                is the play method that calls the methods in the correct order
 *                to run the entire game.
*********************************************************************/
#ifndef GAME_HPP
#define GAME_HPP


#include "Character.hpp"
#include "Space.hpp"

class Game {
private:
    Character *player;

    Space *cellCar;
    Space *stableCar;
    Space *cargoCar;
    Space *diningCar;
    Space *securityCar;
    Space *locomotiveCar;

    bool escaped;
public:
    //  Ctor/Dtor
    Game();
    ~Game();

    //  Prints instructions/information for user
    void welcome();
    void background();
    void levelInfo();

    //  Winning/Losing screen
    void winner();
    void gameOver();

    //  Links spaces together
    void mapSetup();

    //  Runs game
    void play();
};


#endif //GAME_HPP
