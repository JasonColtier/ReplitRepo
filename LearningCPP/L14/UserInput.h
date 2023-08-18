//
// Created by User on 18/08/2023.
//

#ifndef REPLITREPO_USERINPUT_H
#define REPLITREPO_USERINPUT_H

#include "Direction.h"
#include <iostream>
#include <cassert>

namespace UserInput {

    void ignoreLine() {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    bool isValidInput(char c) {
        if (c == 'z' ||
            c == 'q' ||
            c == 's' ||
            c == 'd' ||
            c == 'f'
                )
            return true;
        return false;
    }

    //gets a valid command from the user
    char getCommandFromUser() {
        while (true) {
            char userKey{};
            std::cin >> userKey;
            if (isValidInput(userKey)) {
//                std::cout << "Valid command " << userKey << "\n";
                return userKey;
            } else {
                std::cout << "wrong input \n";
                ignoreLine();
            }
        }
    }

    //We return et direction from the user Command
    Direction ConvertCommandToDirection(char command) {
        switch (command) {
            case 'z':
                return Direction{Direction::top};
            case 'q':
                return Direction{Direction::left};
            case 's':
                return Direction{Direction::down};
            case 'd':
                return Direction{Direction::right};
            default:
                assert(0 && "Unsupported direction was passed!");
                return Direction{ Direction::top };
        }
    }

}


#endif //REPLITREPO_USERINPUT_H
