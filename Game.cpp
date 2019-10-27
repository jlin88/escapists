//
// Created by Justin Lin on 2019-06-05.
//

/*********************************************************************
** Program name:  Game.cpp
** Author:        Justin Lin
** Date:          06/05/2019
** Description:   This is the header file for the implementation class. The class
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
#include "Game.hpp"
#include "Stable.hpp"
#include "Cell.hpp"
#include "Cargo.hpp"
#include "Security.hpp"
#include "Locomotive.hpp"
#include "Dining.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

/*******************************************************************************
Name:         Justin Lin
Called by:    N/A
Calls:        N/A
Passed:       N/A
Returns:      N/A

Description:  This is a the default constructor for the Game class. It
              dynamically allocates memory to create the player character using
              a Character pointer and the 6 derived Spaces using a Space pointer.
              The bool value escaped is set to false. This is done using an
              initialization list for efficiency.
*******************************************************************************/
Game::Game() : player(new Character), cellCar(new Cell), stableCar(new Stable),
               cargoCar(new Cargo), diningCar(new Dining),
               securityCar(new Security), locomotiveCar(new Locomotive),
               escaped(false) {}

/*******************************************************************************
Name:         Justin Lin
Called by:    N/A
Calls:        N/A
Passed:       N/A
Returns:      N/A

Description:  This is the default destructor and will deallocate the memory
              assigned to the player and each of the 6 derived spaces.
*******************************************************************************/
Game::~Game() {
    delete player;
    delete cellCar;
    delete stableCar;
    delete cargoCar;
    delete diningCar;
    delete securityCar;
    delete locomotiveCar;
}

/*******************************************************************************
Name:         Justin Lin
Called by:    play
Calls:        N/A
Passed:       N/A
Returns:      N/A

Description:  This method prints the title of the game.
*******************************************************************************/
//  ASCII generated from: http://patorjk.com/software/taag/#p=display&f=Slant&t=The%20Escapists
void Game::welcome() {
  cout << "  ________            ______                      _      __\n"
          " /_  __/ /_  ___     / ____/_____________ _____  (_)____/ /______\n"
          "  / / / __ \\/ _ \\   / __/ / ___/ ___/ __ `/ __ \\/ / ___/ __/ ___/\n"
          " / / / / / /  __/  / /___(__  ) /__/ /_/ / /_/ / (__  ) /_(__  )\n"
         "/_/ /_/ /_/\\___/  /_____/____/\\___/\\__,_/ .___/_/____/\\__/____/\n"
         "                                       /_/\n" << endl;
}

/*******************************************************************************
Name:         Justin Lin
Called by:    play
Calls:        N/A
Passed:       N/A
Returns:      N/A

Description:  This method prints some background information to the screen to
              let the player know how to play. It also has a getline() with
              a pause allowing the user to read the instructions. The user can
              push enter to continue.
*******************************************************************************/
void Game::background() {
    std::string temp = "";

    cout << "This game is based on the indie game 'The Escapists'\n"
            "The idea is that you are a prisoner, and must escape\n"
            "a prison through various means. This program is a text\n"
            "based simulation of one of the levels 'Cougar Creek\n"
            "Railroad.' You are are inmate aboard a train. There are\n"
            "various means of escape. You must make it off before the\n"
            "train reaches its destination. Your hp represents a timer\n"
            "that will tick down each move. You have 10 health to figure\n"
            "it out. You must collect key items along the train to hatch\n"
            "your escape. The world is navigated through a series of menus\n"
            "unique to each derived class. Good luck inmate!\n" << endl;

    cout << "Read the instructions? Push enter to continue\n" << endl;
    getline(cin, temp);
}

/*******************************************************************************
Name:         Justin Lin
Called by:    play
Calls:        N/A
Passed:       N/A
Returns:      N/A

Description:  This method prints the level information with some background
              text. There is a pause using getline() allowing the user to read
              before starting the game.
*******************************************************************************/
//  ASCII generated from: http://patorjk.com/software/taag/#p=display&f=Graffiti&t=Type%20Something%20
//  Train from: http://www.ascii-art.de/ascii/t/train.txt
//  Text from: https://theescapists.gamepedia.com/Cougar_Creek_Railroad
void Game::levelInfo() {
    std::string temp = "";

    cout << "     _________                                   \n"
            "     __  ____/_________  ________ ______ ________\n"
            "     _  /    _  __ \\  / / /_  __ `/  __ `/_  ___/\n"
            "     / /___  / /_/ / /_/ /_  /_/ // /_/ /_  /    \n"
            "     \\____/  \\____/\\__,_/ _\\__, / \\__,_/ /_/     \n"
            "                       /____/                 \n"
            "        _________                ______  \n"
            "        __  ____/___________________  /__\n"
            "        _  /    __  ___/  _ \\  _ \\_  //_/\n"
            "        / /___  _  /   /  __/  __/  ,<   \n"
            "        \\____/  /_/    \\___/\\___//_/|_|  \n"
            "                                 \n"
            "________       ___________                   _________\n"
            "___  __ \\_____ ___(_)__  /__________________ ______  /\n"
            "__  /_/ /  __ `/_  /__  /__  ___/  __ \\  __ `/  __  / \n"
            "_  _, _// /_/ /_  / _  / _  /   / /_/ / /_/ // /_/ /  \n"
            "/_/ |_| \\__,_/ /_/  /_/  /_/    \\____/\\__,_/ \\__,_/   \n"
            "                                                      " << endl;

    cout << "       o x o x o x o . . .\n"
            "      o      _____            _______________ ___=====__T___\n"
            "     .][__n_n_|DD[  ====_____  |    |.\\/.|   | |   |_|     |_\n"
            "    >(________|__|_[_________]_|____|_/\\_|___|_|___________|_|\n"
            "    _/oo OOOOO oo`  ooo   ooo   o^o       o^o   o^o     o^o\n"
            "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n"
        << endl;

    cout << "You and the vultures overhead know what fate awaits once this\n"
            "train reaches the end of the line. If you plan to see another\n"
            "sunrise you'd better disembark by whatever means necessary.\n"
            << endl;

    cout << "Read to play? Push enter to continue\n" << endl;
    getline(cin, temp);
}

/*******************************************************************************
Name:         Justin Lin
Called by:    play
Calls:        N/A
Passed:       N/A
Returns:      N/A

Description:  This method prints a winning message.
*******************************************************************************/
//  ASCII text from: http://patorjk.com/software/taag/#p=display&f=Ivrit&t=Winner%0AWinner%0AChicken%0A%20%20%20Dinner
//  ASCII art from: https://www.asciiart.eu/nature/sunset
void Game::winner() {
    cout << " __        ___                       \n"
            " \\ \\      / (_)_ __  _ __   ___ _ __ \n"
            "  \\ \\ /\\ / /| | '_ \\| '_ \\ / _ \\ '__|\n"
            "   \\ V  V / | | | | | | | |  __/ |   \n"
            "    \\_/\\_/  |_|_| |_|_| |_|\\___|_|   \n"
            " __        ___                       \n"
            " \\ \\      / (_)_ __  _ __   ___ _ __ \n"
            "  \\ \\ /\\ / /| | '_ \\| '_ \\ / _ \\ '__|\n"
            "   \\ V  V / | | | | | | | |  __/ |   \n"
            "    \\_/\\_/  |_|_| |_|_| |_|\\___|_|   \n"
            "   ____ _     _      _               \n"
            "  / ___| |__ (_) ___| | _____ _ __   \n"
            " | |   | '_ \\| |/ __| |/ / _ \\ '_ \\  \n"
            " | |___| | | | | (__|   <  __/ | | | \n"
            "  \\____|_| |_|_|\\___|_|\\_\\___|_| |_| \n"
            "     ____  _                         \n"
            "    |  _ \\(_)_ __  _ __   ___ _ __   \n"
            "    | | | | | '_ \\| '_ \\ / _ \\ '__|  \n"
            "    | |_| | | | | | | | |  __/ |     \n"
            "    |____/|_|_| |_|_| |_|\\___|_|   \n" << endl;

    cout << "                        |\n"
            "                    \\       /\n"
            "                      .-\"-.\n"
            "                 --  /     \\  --\n"
            "`~~^~^~^~^~^~^~^~^~^-=======-~^~^~^~~^~^~^~^~^~^~^~`\n"
            "`~^_~^~^~-~^_~^~^_~-=========- -~^~^~^-~^~^_~^~^~^~`\n"
            "`~^~-~~^~^~-^~^_~^~~ -=====- ~^~^~-~^~_~^~^~~^~-~^~`\n"
            "`~^~^~-~^~~^~-~^~~-~^~^~-~^~~^-~^~^~^-~^~^~^~^~~^~-`\n" << endl;

    cout << "Congratulations! You have escaped from Cougar Creek Railroad!\n"
            "Thank you for playing. I hope you enjoyed the game!\n" << endl;
}

/*******************************************************************************
Name:         Justin Lin
Called by:    play
Calls:        N/A
Passed:       N/A
Returns:      N/A

Description:  This method prints a game over message.
*******************************************************************************/
//  ASCII generated from: http://patorjk.com/software/taag/#p=display&f=Ivrit&t=Game%20Over
//  ASCII art from: http://ascii.co.uk/art/jail
void Game::gameOver() {
    cout << "  ____    _    __  __ _____    _____     _______ ____\n"
            " / ___|  / \\  |  \\/  | ____|  / _ \\ \\   / / ____|  _ \\ \n"
            "| |  _  / _ \\ | |\\/| |  _|   | | | \\ \\ / /|  _| | |_) |\n"
            "| |_| |/ ___ \\| |  | | |___  | |_| |\\ V / | |___|  _ <\n"
            " \\____/_/   \\_\\_|  |_|_____|  \\___/  \\_/  |_____|_| \\_\\\n"
         << endl;

    cout << "               _________________________\n"
            "                  ||   ||     ||   ||\n"
            "                  ||   ||, , ,||   ||\n"
            "                  ||  (||/|/(\\||/  ||\n"
            "                  ||  ||| _'_`|||  ||\n"
            "                  ||   || o o ||   ||\n"
            "                  ||  (||  - `||)  ||\n"
            "                  ||   ||  =  ||   ||\n"
            "                  ||   ||\\___/||   ||\n"
            "                  ||___||) , (||___||\n"
            "                 /||---||-\\_/-||---||\\\n"
            "                / ||--_||_____||_--|| \\\n"
            "               (_(||)-| S123-45 |-(||)_)\n" << endl;

    cout << "SCREEEEECH! The train suddenly screeches to a halt sending you\n"
            "falling over your feet. As you stand back up, you are suddenly\n"
            "grabbed by three guards. \"Ah there you are, we've been looking\n"
            "all over the train for you.\" Unfortunately, you didn't seem to\n"
            "have a sense of urgency in escaping your fate and the train has\n"
            "arrived at its destination. God knows what is in store for you.\n"
            << endl;
}

/*******************************************************************************
Name:         Justin Lin
Called by:    play
Calls:        N/A
Passed:       N/A
Returns:      N/A

Description:  This methods sets up the game world by linking the derived spaces
              together to form the connections between spaces. Each derived
              space has four pointers but only two are used (left and right)
              indicating that you are navigating through a 2D world.
*******************************************************************************/
//  Links spaces together
void Game::mapSetup() {
    //  Set cellCar links
    cellCar->setLeft(nullptr);
    cellCar->setRight(stableCar);

    //  Set stableCar links
    stableCar->setLeft(cellCar);
    stableCar->setRight(cargoCar);

    //  Set cargoCar links
    cargoCar->setLeft(stableCar);
    cargoCar->setRight(diningCar);

    // Set diningCar links
    diningCar->setLeft(cargoCar);
    diningCar->setRight(securityCar);

    //  Set securityCar links
    securityCar->setLeft(diningCar);
    securityCar->setRight(locomotiveCar);

    // Set locomotiveCar links
    locomotiveCar->setLeft(securityCar);
    locomotiveCar->setRight(nullptr);
}

/*******************************************************************************
Name:         Justin Lin
Called by:    N/A
Calls:        info, interactions, winner, gameOver
Passed:       N/A
Returns:      N/A

Description:  This method runs the entire game. It will print the relevant
              starting messages by calling the relevant methods. Then, a
              Space pointer is initializes to be the cellCar which is the
              starting Space. The method will loop through calling the info
              and interactions methods while the player still has hp or has
              not escaped. If the player runs out of hp, a game over screen
              is displayed. If the player wins, a winning message is displayed.
*******************************************************************************/
void Game::play() {
    Space *nextLevel = cellCar;

    //  Welcome messasge
    welcome();

    // Prints instructions on how to play
    background();

    //  Prints level information
    levelInfo();

    //  Set links to create map
    mapSetup();

    //  Game runs until player runs out of life or has escaped
    while ((player->getHP() > 0) && (!escaped)) {
        nextLevel->info();
        nextLevel = nextLevel->interactions(player);

        if (nextLevel == nullptr) {
            escaped = true;
        }
    }

    //  Prints winning message
    if (escaped) {
        winner();
    }

    //  Prints game over message
    if (player->getHP() == 0) {
        gameOver();
    }
}
