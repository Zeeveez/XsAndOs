#include "Game.h"

#include <iostream>

int main() {
    Game game;
    bool finished = false;
    while (!finished)
    {
        std::cout << "\033[F                                           \033[F\033[F\033[F\033[F\033[F";
        std::cout << game.GetGrid();
        finished = game.MakeMove();
    }
    std::cout << "\033[F                                           \033[F\033[F\033[F\033[F\033[F";
    std::cout << game.GetGrid();
    std::cout << "Game Complete\n";
}