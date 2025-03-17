#pragma once
#include <iostream>
#include <string>

class Player {
public:
    std::string name;
    int score;

    Player(std::string playerName) : name(playerName), score(0) {}

    void guessNumber(int guess) {
        std::cout << name << " guessed: " << guess << std::endl;
   
    }

    void receiveFeedback(int bulls, int cows) {
        std::cout << name << " received feedback: " << bulls << " bulls and " << cows << " cows." << std::endl;
    }
};
