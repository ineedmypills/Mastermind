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
    bool debugMode = true;

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
            if (unique)
            {
                if (debugMode) { std::cout << secretNumber << std::endl; };
                break;
            }
        }
    }

    std::string getSecretNumber() const {
        return secretNumber;
    }

    std::pair<int, int> evaluateGuess(const std::string& guess) const {
        int bulls = 0;
        int cows = 0;
        std::vector<bool> secretUsed(secretNumber.size(), false);
        std::vector<bool> guessUsed(guess.size(), false);

        for (size_t i = 0; i < secretNumber.size(); ++i) {
            if (guess[i] == secretNumber[i]) {
                bulls++;
                secretUsed[i] = true;
                guessUsed[i] = true;
            }
        }

        for (size_t i = 0; i < guess.size(); ++i) {
            if (!guessUsed[i]) {
                for (size_t j = 0; j < secretNumber.size(); ++j) {
                    if (!secretUsed[j] && guess[i] == secretNumber[j]) {
                        cows++;
                        secretUsed[j] = true;
                        break;
                    }
                }
            }
        }

        return { bulls, cows };
    }
};
