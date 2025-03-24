#pragma once
#include "Player.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

class Game {
private:
    Player player1;
    Player player2;
    bool player1Starts;

public:
    Game(bool player1Starts) : player1Starts(player1Starts) {}

    void play() {
        std::string guess;
        Player& currentPlayer = player1Starts ? player1 : player2;
        Player& opponentPlayer = player1Starts ? player2 : player1;

        while (true) {
            std::cout << "Enter your guess (4 unique digits): ";
            std::cin >> guess;

            if (guess.length() != 4 || !isUnique(guess)) {
                std::cout << "Invalid guess. Please enter 4 unique digits." << std::endl;
                continue;
            }

            auto result = opponentPlayer.evaluateGuess(guess);
            std::cout << "Bulls: " << result.first << ", Cows: " << result.second << std::endl;

            if (result.first == 4) {
                std::cout << "Congratulations! You've guessed the number!" << std::endl;
                break;
            }

            // Swap players
            std::swap(currentPlayer, opponentPlayer);
        }
    }

private:
    bool isUnique(const std::string& str) const {
        std::vector<bool> digitUsed(10, false);
        for (char digit : str) {
            if (digitUsed[digit - '0']) {
                return false;
            }
            digitUsed[digit - '0'] = true;
        }
        return true;
    }
};