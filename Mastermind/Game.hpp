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
    Player computer;
    bool singlePlayerMode;

public:
    Game(bool singlePlayerMode) : singlePlayerMode(singlePlayerMode) {
        srand(static_cast<unsigned>(time(0)));
    }

    void play() {
        if (singlePlayerMode) {
            playSinglePlayer();
        }
        else {
            playMultiplayer();
        }
    }

private:
    void playSinglePlayer() {
        std::string guess;

        std::cout << "Компьютер загадал число. Попробуйте угадать!" << std::endl;

        while (true) {
            std::cout << "Введите вашу догадку (четыре уникальных цифры): ";
            std::cin >> guess;

            if (guess.length() != 4 || !isUnique(guess)) {
                std::cout << hue::red << "Неверный ввод. Введите четыре уникальных цифры." << hue::reset << std::endl << std::endl;
                continue;
            }

            auto result = computer.evaluateGuess(guess);
            std::cout << hue::green << "Быков: " << result.first << std::endl
                << hue::yellow << "Коров: " << result.second << hue::reset << std::endl
                << std::endl;

            if (result.first == 4) {
                std::cout << hue::green << "Поздравляю! Вы угадали число!" << hue::reset << std::endl;
                break;
            }
        }
    }

    void playMultiplayer() {
        std::string guess;
        Player& currentPlayer = player1;
        Player& opponentPlayer = player2;

        while (true) {
            std::cout << "Попробуйте угадать (четыре уникальных цифры): ";
            std::cin >> guess;

            if (guess.length() != 4 || !isUnique(guess)) {
                std::cout << hue::red << "Неверный ввод. Введите четыре уникальных цифры." << hue::reset << std::endl << std::endl;
                continue;
            }

            auto result = opponentPlayer.evaluateGuess(guess);
            std::cout << hue::green << "Быков: " << result.first << std::endl
                << hue::yellow << "Коров: " << result.second << hue::reset << std::endl
                << std::endl;

            if (result.first == 4) {
                std::cout << hue::green << "Поздравляю! Вы угадали число!" << hue::reset << std::endl;
                break;
            }

            std::swap(currentPlayer, opponentPlayer);
        }
    }

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