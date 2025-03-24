




int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation
    bool player1Starts = true; // You can change this to let player 2 start
    Game game(player1Starts);
    game.play();
    return 0;
}