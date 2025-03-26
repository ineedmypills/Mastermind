#include "Game.hpp"
#include "Player.hpp"
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(static_cast<unsigned int>(time(0)));
    bool singlePlayer = true;

    Game game(singlePlayer);
    game.play();
    return 0;
}