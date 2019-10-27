//
// Created by Justin Lin on 2019-06-06.
//

/*********************************************************************
** Program name:  Stable.cpp
** Author:        Justin Lin
** Date:          06/03/2019
** Description:   This is the implementation file for the derived Stable class.
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
#include "Stable.hpp"
#include "inBounds.hpp"
#include "integerValidation.hpp"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

/*******************************************************************************
Name:         Justin Lin
Called by:    N/A
Calls:        Space()
Passed:       N/A
Returns:      N/A

Description:  This is the default constructor for the Stable class. It calls the
              base class Space constructor, and sets horseFed and carrotTaken
              to false using an initialization list.
*******************************************************************************/
Stable::Stable() : Space(), horseFed(false), carrotTaken(false) {};

/*******************************************************************************
Name:         Justin Lin
Called by:    interactions()
Calls:        N/A
Passed:       N/A
Returns:      N/A

Description:  This method simply returns the name of the Space. It is used when
              a player enters a new space.
*******************************************************************************/
string Stable::name() {
    return "[Stable Car]";
}

/*******************************************************************************
Name:         Justin Lin
Called by:    play()
Calls:        N/A
Passed:       N/A
Returns:      N/A

Description:  This is a polymorphic method which prints a unique train car
              description.
*******************************************************************************/
void Stable::info() {
    cout << "The smell of manure hits you instantly. Ah, that's what that\n"
            "smell was. You see a large horse staring back at you. Why is\n"
            "there a horse on this train!? There is a large stack of hay in\n"
            "the corner of the Stable Car. Across from you, you see the door\n"
            "to the next train car. Across the car from the stack of hay you\n"
            "see a pile of carrots \'Yuck\' you think to yourself.\n" << endl;
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
              menu changes based on whether the horse has been fed. The
              interactions method presents a menu to the user indicating what
              actions they can perform. The interactions method is an infinite
              loop with the exit condition the player leaving the space. If
              the player moves right/;eft, the method will use the respective
              links to return the next space.
*******************************************************************************/
Space* Stable::interactions(Character *player) {
    int choice = 0;

    while (true) {
        //  If horse is not fed, provide option
        if (!horseFed) {
            cout << " 1. Look around\n 2. Move Right\n 3. Move Left\n"
                    " 4. Inventory\n 5. Stats\n 6. Take Carrot\n"
                    " 7. Feed horse hay\n" << endl;
            do {
                choice = integerValidation();
            } while (!inBounds(choice, 1, 7));

        //  If horse has already been fed
        } else {
            cout << " 1. Look around\n 2. Move Right\n 3. Move Left\n"
                    " 4. Inventory\n 5. Stats\n 6. Take Carrot" << endl;
            do {
                choice = integerValidation();
            } while (!inBounds(choice, 1, 6));
        }

        //  Prints space info
        if (choice == 1) {
            info();

            //  Attempts to move right
        } else if (choice == 2) {
            cout << "You make your way through the carriageway forward into\n"
                    "the " << getRight()->name() << "\n" << endl;

            player->setHP(player->getHP() - 1);
            return this->getRight();

            //  Attempts to move left
        } else if (choice == 3) {
            cout << "You make your way back through the carriageway into\n"
                    "the " << getLeft()->name() << "\n" << endl;

            player->setHP(player->getHP() - 1);
            return this->getLeft();

            //  Prints player inventory
        } else if (choice == 4) {
            player->inventory();

            //  Prints player stats
        } else if (choice == 5) {
            player->stats();

        //  Take carrot
        } else if (choice == 6) {
            if (!carrotTaken) {
                cout << "You grab a [Carrot] out of the pile and shove it in your"
                        " pockets.\n" << endl;

                cout << "[Carrot] added to [Inventory]\n" << endl;
                player->takeItem("Carrot");
                player->checkItems();
                carrotTaken = true;
            } else {
                cout << "You already took a [Carrot]. You only have so many\n"
                        "pockets. Best not to fill them all up with carrots.\n"
                     << endl;
            }
        //  Feed horse
        } else if (choice == 7) {
            cout << "You grab some hay out of the corner and place it infront of\n"
                    "the horse. He or maybe she...what do you know, you're no\n"
                    "horse expert. AHEM! The horse begins munching away happily\n"
                    "at the stack of hay. Looking back over at the haystack\n"
                    "you see something shiny poking out. You walk over and pick\n"
                    "it up\n" << endl;

            cout << "[Crowbar] added to [Inventory]\n" << endl;
            player->takeItem("Crowbar");
            player->checkItems();
            horseFed = true;
        }
    }
}