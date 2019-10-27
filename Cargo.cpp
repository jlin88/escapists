//
// Created by Justin Lin on 2019-06-05.
//

/*********************************************************************
** Program name:  Cargo.cpp
** Author:        Justin Lin
** Date:          06/03/2019
** Description:   This is the implementation file for the derived Cargo class.
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
#include "Cargo.hpp"
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

Description:  This is the default constructor for the Cargo class. It calls the
              base Space class constructor and sets guardDefeated, skipGuard,
              and searched to false.
*******************************************************************************/
Cargo::Cargo() : Space(), guardDefeated(false), skipGuard(false)
                 , searched(false) {}


/*******************************************************************************
Name:         Justin Lin
Called by:    interactions()
Calls:        N/A
Passed:       N/A
Returns:      N/A

Description:  This method simply returns the name of the Space. It is used when
              a player enters a new space.
*******************************************************************************/
string Cargo::name() {
    return "[Cargo Car]";
}

/*******************************************************************************
Name:         Justin Lin
Called by:    play()
Calls:        N/A
Passed:       N/A
Returns:      N/A

Description:  This is a polymorphic method which prints a unique train car
              description based on the status of the guard using the bool
              flags that are private data members of the Cargo class.
*******************************************************************************/
void Cargo::info() {
    //  If guard has not been defeated
    if (!guardDefeated) {
        cout << "The [Cargo Car] is full to the brim with various wooden crates.\n"
                "You notice a crowbar on top of one of the crates at the other\n"
                "side of the room. However, You can see a guard between you and\n"
                "the [crowbar]. Luckily, He looks to be distracted and has his\n"
                "back turned towards you. On the other side of the train car,\n"
                "you can make out a door to the next train car.\n" << endl;

    //  Guard is defeated
    } else if (guardDefeated) {
        cout << "The [Cargo Car] is full to the brim with various wooden crates.\n"
                "The guard is slumped over on the ground unconscious. He won't\n"
                "be waking up anytime soon. Hope nobody was looking for him.\n"
                "In front lies the door to the next carriage.\n" << endl;
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
              menu changes based on whether the player has searched the guard,
              attacked the guard or snuck past the guard. The interactions
              method presents a menu to the user indicating what
              actions they can perform. The interactions method is an infinite
              loop with the exit condition the player leaving the space. If
              the player moves right, the method will use the right link to
              return the next space.
*******************************************************************************/
Space* Cargo::interactions(Character *player) {
    int choice = 0;
    cout << "[Interactions]" << endl;

    while (true) {
        if (searched) {
            cout << " 1. Look around\n 2. Move Right\n 3. Move Left\n 4. Inventory\n"
                   " 5. Stats\n " << endl;
            do {
                choice = integerValidation();
            } while (!inBounds(choice, 1, 5));

            //  Prints space info
            if (choice == 1) {
                info();

            //  Attempts to move right
            } else if (choice == 2) {
                cout << "You make your way through the carriageway into the\n"
                     << getRight()->name() << "\n" << endl;

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
        //  If player has not defeated or skipped past guard
        } else if (!guardDefeated && !skipGuard) {
            cout << " 1. Look around\n 2. Move Right\n 3. Move Left\n 4. Inventory\n"
                    " 5. Stats\n 6. Attack the guard\n 7. Sneak past the guard\n"
                    << endl;
            do {
                choice = integerValidation();
            } while (!inBounds(choice, 1, 7));

            //  Prints space info
            if (choice == 1) {
                info();

            //  Attempts to move right
            } else if (choice == 2) {
                cout << "If you haven't noticed there is a guard RIGHT THERE\n"
                        "infront of you. Maybe you should do something about it"
                        ".\n" << endl;

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

            //  Attack Guard
            } else if (choice == 6) {
                cout << "You muster up what courage you have and let out your best\n"
                        "war cry as you charge towards the guard. He is startled by\n"
                        "the what can only be described as odd noises you're making\n"
                        "THUNK! You run headfirst into the guard somehow knocking him\n"
                        "unconscious.\n" << endl;
                guardDefeated = true;
            //  Sneak past guard
            } else if (choice == 7) {
                player->setHP(player->getHP() - 1);
                cout << "You slowly creep around the guard careful not to make any\n"
                        "noise. Slowly, but surely you make your way to the end of\n"
                        "the Cargo Car. You stop infront of the door and look\n"
                        "back to see if the guard notices.\n" << endl;
                skipGuard = true;
            }

        //  If player defeated guard
        } else if (guardDefeated) {
            cout << " 1. Look around\n 2. Move Right\n 3. Move Left\n 4. Inventory\n"
                    " 5. Stats\n 6. Search guard\n" << endl;
            do {
                choice = integerValidation();
            } while (!inBounds(choice, 1, 6));

            //  Prints space info
            if (choice == 1) {
                info();

            //  Attempts to move right
            } else if (choice == 2) {
                cout << "You make your way through the carriageway into the\n"
                     << getRight()->name() << "\n" << endl;

                player->setHP(player->getHP() - 1);
                return this->getRight();

            //  Attempts to move left
            } else if (choice == 3) {
                cout << "You make your way back through the carriageway into\n"
                        "the " << getLeft()->name() << "\n" <<endl;

                player->setHP(player->getHP() - 1);
                return this->getLeft();

            //  Prints player inventory
            } else if (choice == 4) {
                player->inventory();

            //  Prints player stats
            } else if (choice == 5) {
                player->stats();

            //  Search Guard
            } else if (choice == 6) {
                cout << "You search through the Guard's pockets and don't find\n"
                        "much, except for some crumbs. Hmm, that uniform looks\n"
                        "mighty fancy though. You take the guard's clothes and\n"
                        "put them on.\n" << endl;

                cout << "[Guard Uniform] added to [Inventory]\n" << endl;
                player->takeItem("Guard Uniform");
                player->checkItems();
                searched = true;
            }
        // If player skipped guard
        } else {
            cout << " 1. Look around\n 2. Move Right\n 3. Move Left\n "
                    "4. Inventory\n 5. Stats\n 6. Attack the guard\n" << endl;
            do {
                choice = integerValidation();
            } while (!inBounds(choice, 1, 6));
            //  Prints space info
            if (choice == 1) {
                info();

            //  Attempts to move right
            } else if (choice == 2) {
                cout << "You make your way through the carriageway into the\n"
                     << getRight()->name() << "\n" << endl;

                player->setHP(player->getHP() - 1);
                return this->getRight();

            //  Attempts to move left
            } else if (choice == 3) {
                    cout << "If you haven't noticed, there is still a guard\n"
                            "you snuck past in the way.\n" << endl;

            //  Prints player inventory
            } else if (choice == 4) {
                player->inventory();

            //  Prints player stats
            } else if (choice == 5) {
                player->stats();

            //  Attack Guard
            } else if (choice == 6) {
                cout << "You muster up what courage you have and let out your best\n"
                        "war cry as you charge towards the guard. He is startled by\n"
                        "the what can only be described as odd noises you're making\n"
                        "THUNK! You run headfirst into the guard somehow knocking him\n"
                        "unconscious.\n" << endl;
                guardDefeated = true;
            }
        }
    }
}


