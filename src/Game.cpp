/*
 * Name: Kosta Rubtsov
 * Id: 319206892
 * Name: Alon Barkan
 * Id: 200958296
 */

#include "../include/Game.h"

Game::~Game() {
 //   cout << "In Game D'tor" << endl;

}

Game::Game() {
 //   this->gameBoard = Board();
}

Game::Game(GameLogic* logic) {
   this->logic = logic;
}

Board* Game::GetBoard() const {
    return this->board;
}

void Game::SetBoard(Board* board) {
    this->board = board;
}

GameLogic* Game::GetLogic() const {
    return this->logic;
}

