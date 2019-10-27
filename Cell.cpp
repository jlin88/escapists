//
// Created by Justin Lin on 2019-06-04.
//

/*********************************************************************
** Program name:  Cell.cpp
** Author:        Justin Lin
** Date:          06/03/2019
** Description:   This is the implementation file for the derived Cell class.
 *                The class has two member variables that are both bools
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
#include "Cell.hpp"
#include "integerValidation.hpp"
#include "inBounds.hpp"
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

Description:  This is the default constructor for the Cell class. It calls the
              base class Space constructor, and sets cellOpened and invChecked
              to false using an initialization list.
*******************************************************************************/
Cell::Cell() : Space(), cellOpened(false), invChecked(false) {}

/*******************************************************************************
Name:         Justin Lin
Called by:    interactions()
Calls:        N/A
Passed:       N/A
Returns:      N/A

Description:  This method simply returns the name of the Space. It is used when
              a player enters a new space.
*******************************************************************************/
string Cell::name() {
    return "[Cell Car]";
}

/*******************************************************************************
Name:         Justin Lin
Called by:    info()
Calls:        N/A
Passed:       N/A
Returns:      N/A

Description:  This method prints a starting message describing the Cell itself.
              It is only used in the beginning to give some context into the
              world.
*******************************************************************************/
void Cell::start() {
    cout << "You awake to the sounds of a train horn blaring and sit up.\n"
            "You sit up on your cot and take a look at your surroundings\n"
            << endl;

    cout << "The [Cell] is quite barren. There is a small cot in the corner,\n"
            "with a scratchy blanket and what seems to be a rock\n"
            "masquerading as a mattress. Behind your bed, is a small window\n"
            "where you can surmise that you will be at your destination\n"
            "soon. You think to yourself, best get out of here soon.\n" << endl;
}

/*******************************************************************************
Name:         Justin Lin
Called by:    play()
Calls:        N/A
Passed:       N/A
Returns:      N/A

Description:  This is a polymorphic method which prints a unique train car
              description based upon whether or not the player has opened
              the cell door.
*******************************************************************************/
void Cell::info() {
    if (!cellOpened) {
        start();
        cout << "Peering through the bars of your cell, you see the guard sitting\n"
                "at a small desk straight across from you. He seems to be in a\n"
                "deep slumber. You can see the [Cell Key] to your cell on a\n"
                "desk infront of the guard. It is just out of your reach. If\n"
                "only you had something you could grab it with\n" << endl;
    } else {
        cout << "To your left you see the back of the train. Looks like we're\n"
                "going pretty fast. To your right, you smell something funky\n"
                "behind the door\n" << endl;
    }
}

/*******************************************************************************
Name:         Justin Lin
Called by:    play()
Calls:        N/A
Passed:       Character*
Returns:      Space*

Description:  This is a polymorphic method which prints a menu based upon
              what actions the player has completed. It takes as an argument
              a pointer to a Character representing the player character. The
              menu changes based on whether the player has checked their
              inventory, and whether or not the cell door has been opened. The
              interactions method presents a menu to the user indicating what
              actions they can perform. The interactions method is an infinite
              loop with the exit condition the player leaving the space. If
              the player moves right, the method will use the right link to
              return the next space.
*******************************************************************************/
Space* Cell::interactions(Character *player) {
    int choice = 0;

    while (true) {
        cout << "[Interactions]" << endl;

        //  If user has opened cell already, remove that option
        if (cellOpened) {
            cout << " 1. Look around\n 2. Move Right\n 3. Move Left\n"
                    " 4. Inventory\n 5. Stats\n" << endl;

            do {
                choice = integerValidation();
            } while (!inBounds(choice, 1, 5));

        //  If user has not checked inventory, or already has the key, restrict
        //  options
        } else if (!invChecked || player->getKey()) {
            cout << " 1. Look around\n 2. Move Right\n 3. Move Left\n"
                    " 4. Inventory\n 5. Stats\n 6. Open Cell\n" << endl;

            do {
                choice = integerValidation();
            } while (!inBounds(choice, 1, 6));

        //  If user has checked inventory, allow option to get key
        } else {
            cout << " 1. Look around\n 2. Move Right\n 3. Move Left\n"
                    " 4. Inventory\n 5. Stats\n 6. Open Cell\n 7. Get Key\n"
                    << endl;
            do {
                choice = integerValidation();
            } while (!inBounds(choice, 1, 7));
        }

        //  Prints space info
        if (choice == 1) {
            info();

        //  Attempts to move right
        } else if (choice == 2) {

            //  Checks if cell has been opened
            if (cellOpened) {
                cout << "You make your way through the carriageway to the " <<
                     getRight()->name() << "\n" << endl;

                //  Decrements hp on changing spaces
                player->setHP(player->getHP() - 1);
                return this->getRight();

            //  Cell has not been opened
            } else {
                cout << "Maybe you should look around. You're in a cell if\n"
                        "you have forgotten.\n" << endl;
            }

        //  Attempts to move left
        } else if (choice == 3) {
            //  If cell has been opened unique message indicating dead end
            if (cellOpened) {
                cout << "You peer out the door window and notice the train is\n"
                        "moving pretty fast. Jumping off a moving train does\n"
                        "not seem like a smart move. Sometimes you wonder how\n"
                        "you are still breathing.\n" << endl;

            } else {
                cout << "Maybe you should look around. You're in a cell if\n"
                        "you have forgotten.\n" << endl;
            }

        //  Prints player inventory
        } else if (choice == 4) {
            invChecked = true;
            player->inventory();

        //  Prints player stats
        } else if (choice == 5) {
            player->stats();

        //  Tries to use key item
        } else if (choice == 6) {
            openCell(player);

        //  Obtain Cell Key
        } else if (choice == 7) {
            cout << "With pencil in hand, you reach out through the cell door.\n"
                    "You slip the pencil through the keyring on the desk\n"
                    "and carefully pull it through the cell door.\n\n "
                    "[Cell Key] added to [Inventory]\n" << endl;

            cout << "[Pencil] removed from [Inventory]\n" << endl;

            player->removeItem("Pencil");
            player->takeItem("Cell Key");

            //  Set character item flags
            player->checkItems();
        }
    }
}

/*******************************************************************************
Name:         Justin Lin
Called by:    interactions()
Calls:        N/A
Passed:       N/A
Returns:      N/A

Description:  This is a helper method that will check if the player has the
              Cell Key and will allow them to open the cell if they do. If
              the player opens the cell door, the key will be removed from their
              inventory and the cellOpened flag will be set. If the player does
              not have the key, an error message will be printed.
*******************************************************************************/
void Cell::openCell(Character *player) {
    player->checkItems();

    //  If player found key open cell
    if (player->getKey()) {
        cout << "You use the [Cell Key] on the cell door. You carefully\n"
                "unlock the cell and creep outside the cell. To your left you\n"
                "see the back of the train. Looks like we're going pretty\n"
                "fast. To your right, you smell something funky behind the\n"
                "door.\n" << endl;

        cout << "[Cell Key] removed from [Inventory]\n" << endl;
        player->removeItem("Cell Key");
        cellOpened = true;

    //  Cell Key has not been found
    } else {
        cout << "What, you think it would be that easy? The cell door\n"
                "rattles loudly as you try to stick your finger in\n"
                "the keyhole. Surprisingly, your finger doesn't fit\n"
                "in the keyhole Are you trying to wake the guard up!?\n"
                "Maybe you should try something else.\n" << endl;
    }
}