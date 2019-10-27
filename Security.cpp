//
// Created by Justin Lin on 2019-06-06.
//

/*********************************************************************
** Program name:  Security.cpp
** Author:        Justin Lin
** Date:          06/06/2019
** Description:   This is the implementation file for the derived Security class.
 *                The constructor that will call the base Space class
 *                constructor. Lastly, there are 3 override methods.
 *                The name method returns the name of the class. The info
 *                method prints a description of the cell. Lastly, the
 *                interactions method will provide a menu of options based upon
 *                the bool member variables. There is also a helper method that
 *                will check if the player has the required items to proceed.
*********************************************************************/
#include "Security.hpp"
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

Description:  This is the default constructor for the Security class. It calls
              the base class Space constructor.
*******************************************************************************/
Security::Security() : Space() {}

/*******************************************************************************
Name:         Justin Lin
Called by:    interactions()
Calls:        N/A
Passed:       N/A
Returns:      N/A

Description:  This method simply returns the name of the Space. It is used when
              a player enters a new space.
*******************************************************************************/
string Security::name() {
    return "[Security Car]";
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
void Security::info() {
    cout << "You step into the car and immediately realize this is a [Security\n"
            "Car] housing three of the meanest guards that could double as\n"
            "body builders. They hear you enter and immediately stand up and\n"
            "lock eyes with you. 'Uh oh...' you think yourself as you take a\n"
            "big gulp. You only manage to stammer out a 'H-Hi guys!' before\n"
            "the guards squint their ideas at you in anger. The guard in\n"
            "front takes a step forward...\n" << endl;
}

/*******************************************************************************
Name:         Justin Lin
Called by:    interactions
Calls:        N/A
Passed:       Character*
Returns:      bool

Description:  This is a helper method that performs a hard check on the player.
              If the player does not have the guard uniform and fake mustache
              the player will fail the check. The method returns whether the
              check has failed or passed. If the player fails the check it
              will be a game over.
*******************************************************************************/
bool Security::uniformCheck(Character *player) {
    bool checkFailed = true;
    //  If player passes uniform check, guards leave
    if (player->getUniform() && player->getMustache()) {
        cout << "\"Hey! Where have you been?\" shouts a guard. \"We've been\n"
                "waiting for a shift change forever.\" as the trio walks\n"
                "towards the door. \"It's your turn to guard the Locomotive\n"
                "Car, we wouldn't want our inmate escaping now would we?\".\n"
                "You stammer out a 'Y-Y-Yes sir' while sweating bullets as the\n"
                "group of guards leaves you all alone in the Security Car.\n"
                << endl;

        checkFailed = false;

    //  If player fails check, prints appropriate fail message
    } else {
        cout << "\"GET HIM!\" shouts the guard in front. The three guards take\n"
                "one look at you and whip out their trusty [batons] before you\n"
                "can blink an eye. The last thing you remember is thinking\n"
                "\'wow, they\'re so well trained!\' before you are viciously\n"
                "clubbed and dragged back into your cell.\n" << endl;

        if (!player->getMustache()) {
            cout << "What you think just a uniform is good enough to disguise\n"
                    "for yourself and the guards wouldn't recognize you??\n"
                    << endl;
        }

        if (!player->getUniform()) {
            cout << "Probably wasn't the smartest idea walking into a security\n"
                    "car full of guards without a disguise.\n" << endl;
        }
    }
    return checkFailed;
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
              interactions method presents a menu to the user indicating what
              actions they can perform. The interactions method is an infinite
              loop with the exit condition the player leaving the space. If
              the player moves right, the method will use the right link to
              return the next space.
*******************************************************************************/
 Space* Security::interactions(Character *player) {
    //  If check failed
    if (uniformCheck(player)) {
        player->setHP(0);
    } else {
        int choice = 0;

        while (true) {
            cout << " 1. Look around\n 2. Move Right\n 3. Move Left\n"
                    " 4. Inventory\n 5. Stats\n" << endl;

            do {
                choice = integerValidation();
            } while (!inBounds(choice, 1, 5));

            //  Prints space info
            if (choice == 1) {
                info();

            //  Attempts to move right
            } else if (choice == 2) {
                cout
                        << "You make your way forward through the carriageway into\n"
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
            }
        }
    }
}
