#pragma once
#include "Game.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

class Player {
private:
    std::string secretNumber;

public:
    Player() {
        while (true) {
            secretNumber = std::to_string(rand() % 9000 + 1000);
            std::vector<bool> digitUsed(10, false);
            bool unique = true;

            for (char digit : secretNumber) {
                if (digitUsed[digit - '0']) {
                    unique = false;
                    break;
                }
                digitUsed[digit - '0'] = true;
            }

            if (unique) break;
        }
    }

    std::string getSecretNumber() const {
        return secretNumber;
    }

    std::pair<int, int> evaluateGuess(const std::string& guess) const {
        int bulls = 0;
        int cows = 0;

        for (size_t i = 0; i < secretNumber.size(); ++i) {
            if (guess[i] == secretNumber[i]) {
                bulls++;
            }
            else if (secretNumber.find(guess[i]) != std::string::npos) {
                cows++;
            }
        }

        return { bulls, cows };
    }
};
