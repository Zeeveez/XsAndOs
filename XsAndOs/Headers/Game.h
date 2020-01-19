#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>

class Game {
private:
    enum class Players {
        EMPTY,
        X,
        O
    };

    Players currentPlayer;
    std::vector<std::vector<Players>> grid;
    char GetCell(Players player);
    bool CanMove(int cellNo);
    void MakeMove(int cellNo);
    char GetUserInput();
    bool GameFinished();

public:
    Game();
    std::string GetGrid();
    bool MakeMove();
};

#endif // !GAME_H
