#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

class Game {
private:
    std::vector<int> secretNumber;
    int attempts;
    int bulls;
    int cows;

    void generateSecretNumber() {
        // Генерация секретного числа (например, 4 уникальных цифры)
        while (secretNumber.size() < 4) {
            int digit = rand() % 10;
            if (std::find(secretNumber.begin(), secretNumber.end(), digit) == secretNumber.end()) {
                secretNumber.push_back(digit);
            }
        }
    }

    void calculateBullsAndCows(const std::vector<int>& guess) {
        bulls = cows = 0;
        for (size_t i = 0; i < guess.size(); ++i) {
            if (guess[i] == secretNumber[i]) {
                bulls++;
            }
            else if (std::find(secretNumber.begin(), secretNumber.end(), guess[i]) != secretNumber.end()) {
                cows++;
            }
        }
    }

public:
    Game() : attempts(0), bulls(0), cows(0) {
        srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел
        generateSecretNumber();
    }

    void startGame() {
        std::cout << "Game started! Try to guess the secret number!" << std::endl;
    }

    void makeGuess(const std::vector<int>& guess, Player& player) {
        attempts++;
        calculateBullsAndCows(guess);
        player.receiveFeedback(bulls, cows);
    }

    int getAttempts() const {
        return attempts;
    }
};

