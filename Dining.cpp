//
// Created by Justin Lin on 2019-06-07.
//

/*********************************************************************
** Program name:  Dining.cpp
** Author:        Justin Lin
** Date:          06/07/2019
** Description:   This is the implementation file for the derived Dining class.
 *                The class has two member variables that are all bools
 *                that will represent if the player has satisfied a
 *                condition. The constructor that will call the base
 *                Space class constructor and set hasEaten and hasTraded
 *                to false. Lastly, there are 3 override methods.
 *                The name method returns the name of the class. The info
 *                method prints a description of the cell. Lastly, the
 *                interactions method will provide a menu of options based upon
 *                the bool member variables. There are also two helper methods
 *                eat and mustache that take as arguments a pointer to a
 *                Character representing the player.
*********************************************************************/
#include "Dining.hpp"
#include "integerValidation.hpp"
#include "inBounds.hpp"
#include <iostream>
using std::cout;
using std::endl;

/*******************************************************************************
Name:         Justin Lin
Called by:    N/A
Calls:        Space()
Passed:       N/A
Returns:      N/A

Description:  This is the default constructor for the Dining class. It calls the
              base class Space constructor, and sets hasEaten to false using an
              initialization list.
*******************************************************************************/
Dining::Dining() : Space(), hasEaten(false) {};

/*******************************************************************************
Name:         Justin Lin
Called by:    interactions()
Calls:        N/A
Passed:       N/A
Returns:      N/A

Description:  This method simply returns the name of the Space. It is used when
              a player enters a new space.
*******************************************************************************/
std::string Dining::name() {
    return "[Dining Car]";
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
void Dining::info() {
    cout << "You walk into the dining car and are immediately greeted by an\n"
            "array of heavenly smells. You take quick glance around the room\n"
            "and notice several tables draped with a white tablecloth. There\n"
            "is a mysterious mustached man is behind a counter. He has on a\n"
            "large chef hat and is glaring daggers at you. The man is standing\n"
            "in a small kitchen with several pots boiling and is in a flurry\n"
            "of motion chopping and stirring. You lock onto his mustache and\n"
            "boy is it glorious. It's shaped like a pair of handlebars and\n"
            "has the most beautiful curve you have ever seen. You are lost in\n"
            "its beauty. The mustached man shouts at you \"WHAT DO YOU WANT!?\""
            "\n" << endl;
}

/*******************************************************************************
Name:         Justin Lin
Called by:    play()
Calls:        N/A
Passed:       Character*
Returns:      Space*

Description:  This is a polymorphic method which prints a menu of interactions
              the player can perform . It takes as an argument a pointer to a
              Character representing the player character. The interactions
              method is an infinite loop with the exit condition the player
              leaving the space. If the player moves right, the method will use
              the right/left link to move the player to the next space by
              returning the space.
*******************************************************************************/
Space* Dining::interactions(Character *player) {
    int choice = 0;

    while (true) {

        //  Interaction menu
        cout << " 1. Look around\n 2. Move Right\n 3. Move Left\n"
                " 4. Inventory\n 5. Stats\n 6. Ask for food\n"
                " 7. Ask about mustache\n" << endl;

        do {
            choice = integerValidation();
        } while (!inBounds(choice, 1, 7));

        //  Prints space info
        if (choice == 1) {
            info();

        //  Attempts to move right
        } else if (choice == 2) {
            cout << "You make your way forward through the carriageway into\n"
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

        //  Eat food
        } else if (choice == 6) {
            eat(player);

        //  Trade items
        } else if (choice == 7) {
            mustache(player);
        }
    }
}

/*******************************************************************************
Name:         Justin Lin
Called by:    interactions()
Calls:        N/A
Passed:       Character*
Returns:      N/A

Description:  This is a helper method that performs the eat interaction. The
              player can only use this once a game, and will print some flavor
              text as well as restore 3 hp to the player. Once the action has
              been completed, an alternate text will be printed instead. The
              method uses the hasEaten bool flag to determine what to do.
*******************************************************************************/
//  Restores 3 hp to player
void Dining::eat(Character *player) {

    //  Player has not eaten
    if (!hasEaten) {
        cout << "Your stomach grumbles loudly. The chef immediately lights up\n"
                "\"Ah, you're hungry, sit down!\" he exclaims as he plates a\n"
                "mysterious meal in front of you. Without another word, you\n"
                "scraf down the plate nearly licking it clean. You instantly\n"
                "feel much better.\n" << endl;

        cout << "You have gained [HP]: +3\n" << endl;

        //  Adds 3 health to player
        player->setHP(player->getHP() + 3);

        //  Set flag to prevent infinite eating
        hasEaten = true;

    //  Player has eaten already
    } else {
        cout << "You've already devoured an entire plate of food. Don't be a\n"
                "glutton. You couldn't possibly eat another bite.\n" << endl;
    }
}

/*******************************************************************************
Name:         Justin Lin
Called by:    interactions()
Calls:        N/A
Passed:       Character*
Returns:      N/A

Description:  This is a helper method which will perform an item trade. The
              method allows the player to trade a carrot for a fake mustache.
              If the trade has already taken place, an alternate message will
              be printed. If the player has not traded, the method will check
              the player flags to see if he has a carrot to trade. If he has
              the carrot, he will receive a fake mustache and the carrot will
              be removed from his inventory.
*******************************************************************************/
void Dining::mustache(Character *player) {
    if (!hasTraded) {
        cout << "You point at the mysterious Chef's mustache excitedly. The chef\n"
                "immediately recognizes what you're after. \"Ah you want a mustache"
                "\nof your own eh? I know just what you need\" The man rummages\n"
                "around in a drawer and pulls out a fake mustache equally as\n"
                "beautiful as his own. \"This is what you're after. Very well!\n"
                "Get me a carrot for my stew and it's yours!\"\n" << endl;

        //  Trade happens if player has carrot
        if (player->getCarrot()) {
            cout << "You pull the carrot of your pocket surprisingly undamaged\n"
                    "and hold it up in the air. The two of you quickly make\n"
                    "the exchange each satisfied with your new trinket\n" << endl;

            //  Remove carrot from inventory
            cout << "[Carrot] removed from [Inventory]\n" << endl;
            player->removeItem("Carrot");

            //  Add fake mustache to inventory
            cout << "[Fake mustache] added to [Inventory]\n" << endl;
            player->takeItem("Fake mustache");
            player->checkItems();

            cout << "You happily slap the fake mustache onto your upper lip\n"
                    "and peer at your reflection in a small mirror on the wall"
                    ".\n \'Suave and debonair\' you think to yourself.\n"
                    << endl;

            //  Set flag to prevent infinite trading
            hasTraded = true;
        }
    //  Already traded
    } else {
        cout << "Look, you already got the [Fake mustache]. Lets not get greedy\n"
                "here and push our luck.\n" << endl;
    }

}

