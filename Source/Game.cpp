#include "Game.h"

#include <sstream>
#include <iostream>

Game::Game() {
    grid = {
        { Players::EMPTY, Players::EMPTY, Players::EMPTY },
        { Players::EMPTY, Players::EMPTY, Players::EMPTY },
        { Players::EMPTY, Players::EMPTY, Players::EMPTY }
    };
    currentPlayer = Players::X;
}

char Game::GetCell(Players player) {
    switch (player) {
    case Players::EMPTY:
        return ' ';
    case Players::X:
        return 'X';
    case Players::O:
        return 'O';
    }
}

bool Game::CanMove(int cellNo) {
    return grid[cellNo % 3][cellNo / 3] == Players::EMPTY;
}

void Game::MakeMove(int cellNo) {
    grid[cellNo % 3][cellNo / 3] = currentPlayer;
}

char Game::GetUserInput() {
    std::cout << "Enter cell number to make move (" << GetCell(currentPlayer) << "): ";
    std::string input;
    std::getline(std::cin, input);
    return input.length() == 1 ? input[0] : ' ';
}

bool Game::GameFinished() {
    // Horizontals
    if (grid[0][0] != Players::EMPTY && grid[0][0] == grid[1][0] && grid[1][0] == grid[2][0]) { return true; }
    if (grid[0][1] != Players::EMPTY && grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1]) { return true; }
    if (grid[0][2] != Players::EMPTY && grid[0][2] == grid[1][2] && grid[1][2] == grid[2][2]) { return true; }

    // Verticals
    if (grid[0][0] != Players::EMPTY && grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2]) { return true; }
    if (grid[1][0] != Players::EMPTY && grid[1][0] == grid[1][1] && grid[1][1] == grid[1][2]) { return true; }
    if (grid[2][0] != Players::EMPTY && grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2]) { return true; }

    // Diagonals
    if (grid[0][0] != Players::EMPTY && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) { return true; }
    if (grid[2][0] != Players::EMPTY && grid[2][0] == grid[1][1] && grid[1][1] == grid[0][2]) { return true; }

    // Empty Cells
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (grid[x][y] == Players::EMPTY) { return false; }
        }
    }

    return true;
}



std::string Game::GetGrid() {
    std::stringstream ss;
    ss << GetCell(grid[0][0]) << '|' << GetCell(grid[1][0]) << '|' << GetCell(grid[2][0]) << '\t';
    ss << 1 << '|' << 2 << '|' << 3 << '\n';
    ss << "-+-+-\t-+-+-\n";
    ss << GetCell(grid[0][1]) << '|' << GetCell(grid[1][1]) << '|' << GetCell(grid[2][1]) << '\t';
    ss << 4 << '|' << 5 << '|' << 6 << '\n';
    ss << "-+-+-\t-+-+-\n";
    ss << GetCell(grid[0][2]) << '|' << GetCell(grid[1][2]) << '|' << GetCell(grid[2][2]) << '\t';
    ss << 7 << '|' << 8 << '|' << 9 << '\n';
    return ss.str();
}

bool Game::MakeMove() {
    char move = GetUserInput();
    if ('1' <= move && move <= '9' && CanMove(move - '1')) {
        MakeMove(move - '1');
        currentPlayer = currentPlayer == Players::X ? Players::O : Players::X;
        return GameFinished();
    }
    return false;
}