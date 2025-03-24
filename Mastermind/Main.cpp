#include "Game.hpp"
#include "Player.hpp"
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(static_cast<unsigned int>(time(0)));
    bool player1Starts = true;
    Game game(player1Starts);
    game.play();
    return 0;
}