



int main() {
    Player player("Alice");
    Game game;

    game.startGame();

    // Пример предположений игрока (можно заменить на ввод от пользователя)
    std::vector<int> guess1 = { 1, 2, 3, 4 };
    game.makeGuess(guess1, player);

    std::vector<int> guess2 = { 4, 3, 2, 1 };
    game.makeGuess(guess2, player);

    std::cout << "Total attempts: " << game.getAttempts() << std::endl;

    return 0;
}
