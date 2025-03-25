#pragma once
#include "Player.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "color.hpp"

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
            std::cout << "Попробуйте угадать (четыре уникальных цифры): ";
            std::cin >> guess;

            if (guess.length() != 4 || !isUnique(guess)) {
                std::cout << hue::red << "Неверный ввод. Введите четыре уникальных цифры." << hue::reset << std::endl << std::endl;
                continue;
            }

            auto result = opponentPlayer.evaluateGuess(guess);
            std::cout << hue::green << "Быков: " << result.first << std::endl << hue::yellow << "Коров: " << result.second << hue::reset << std::endl << std::endl;

            if (result.first == 4) {
                std::cout << "Поздравляю! Вы угадали!" << std::endl;
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