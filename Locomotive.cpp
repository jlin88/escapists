//
// Created by Justin Lin on 2019-06-04.
//

/*********************************************************************
** Program name:  Locomotive.cpp
** Author:        Justin Lin
** Date:          06/04/2019
** Description:   This is the implementation file for the derived Locomotive
 *                class. There is one member variable that an integer.
 *                The constructor that will call the base Space class
 *                constructor and set pinsUnlatched to 0. Lastly, there are
 *                3 override methods. The name method returns the name of the
 *                class. The info method prints a description of the space.
 *                Lastly, the interactions method will provide a menu of options
 *                based upon the member variable. There is also a helper
 *                method that will 'unlatch' the train car if the player has
 *                the key item.
*********************************************************************/
#include "Locomotive.hpp"
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

Description:  This is the default constructor for the Locomotive class. It calls
              the base class Space constructor, and sets pinsUnlatched to zero
              using an initialization list.
*******************************************************************************/
Locomotive::Locomotive() : Space(), pinsUnlatched(0) {}

/*******************************************************************************
Name:         Justin Lin
Called by:    interactions()
Calls:        N/A
Passed:       N/A
Returns:      N/A

Description:  This method simply returns the name of the Space. It is used when
              a player enters a new space.
*******************************************************************************/
string Locomotive::name() {
    return "[Locomotive Car]";
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
void Locomotive::info() {
    cout << "You step into the Locomotive car and see a giant control panel\n"
            "housing the train controls. Surprisingly, nobody seems to be in\n"
            "the train car. Looking closely, at the panel you have no idea\n"
            "what any of the buttons do and there sure are lots of them\n"
            "A few of the buttons stand out to you, but which should you\n"
            "push!? Wait...you've seen train escapes on TV before. You step \n"
            "into the carriageway, and look down to see two coupling pins\n"
            "holding the Locomotive to the rest of the train\n" << endl;
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
              menu changes based on whether the player has unlatched both
              coupling pins. The interactions method presents a menu to the user
              indicating what actions they can perform. The interactions method
              is an infinite loop with the exit condition the player leaving the
              space. If the player moves right, the method will use the
              right/left links to return the next space. If the player has
              unlatched the train car, the method will automatically return
              the right space.
*******************************************************************************/
Space* Locomotive::interactions(Character *player) {
    int choice = 0;

    while (true) {
        //  Win condition
        if (pinsUnlatched == 2) {
            cout << "The locomotive speeds up with the weight of the other\n"
                    "carriages removed. You watch as the unlatched carriages\n"
                    "get smaller and smaller as you ride off into the sunset.\n"
                    "You're a free man! What will you do with your newfound\n"
                    "freedom?\n" << endl;

            return this->getRight();
        }

        //  Interaction menu
        cout << " 1. Look around\n 2. Move Right\n 3. Move Left\n"
                " 4. Inventory\n 5. Stats\n 6. Decouple Car\n" << endl;

        do {
            choice = integerValidation();
        } while (!inBounds(choice, 1, 6));

        //  Prints space info
        if (choice == 1) {
            info();

        //  Attempts to move right
        } else if (choice == 2) {
            cout << "You're in the front of the train. I don't think jumping\n"
                    "infront of a moving train is the 'escape' you're looking\n"
                    "for.\n" << endl;

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

        //  Unlatch car
        } else if (choice == 6) {
            unlatchCar(player);
        }
    }
}

/*******************************************************************************
Name:         Justin Lin
Called by:    interactions()
Calls:        N/A
Passed:       Character*
Returns:      N/A

Description:  This is a helper method which will check if the player has the
              crowbar. If the player has the crowbar, will allow the player
              to decouple the trains. The method will keep track of how many
              pins the player has removed. Otherwise an error message is printed.
*******************************************************************************/
void Locomotive::unlatchCar(Character *player) {
    //  Player has crowbar
    if (player->getCrowbar()) {
        //  Unlatch first pin
        if (pinsUnlatched == 0) {
            cout << "You whip out your handy [Crowbar]. Ooooh, shiny. Before you\n"
                    "get too distracted by the beautiful beautiful crowbar,\n"
                    "you should probably focus\n" << endl;

            cout << "You stick the crowbar into the coupling and pry out the\n"
                    "pin holding the coupling together.\n" << endl;
            pinsUnlatched++;

        //  Unlatch second pin
        } else if (pinsUnlatched == 1) {
            cout << "You stick the crowbar into the coupling and pry out the\n"
                    "pin holding the second coupling together.\n" << endl;
            pinsUnlatched++;

        //  Already unlatched
        } else {
            cout << "Listen, I know you love that [Crowbar], but you already\n"
                    "uncoupled the trains. Maybe you should focus on something\n"
                    "else like escaping.\n" << endl;
        }
    //  Player does not have crowbar
    } else {
        cout << "Those pins are mighty heavy to remove without some leverage\n"
                "Looks like you'll need some sort of tool to pull them out.\n"
                << endl;
    }
}
