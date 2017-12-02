/*
 * Name: Kosta Rubtsov
 * Id: 319206892
 * Name: Alon Barkan
 * Id: 200958296
 */

#include "../include/ReversiGame.h"

ReversiGame::~ReversiGame() {
//    cout << "In ReversiGame D'tor" << endl;
    delete board;
    delete logic;
}

ReversiGame::ReversiGame(GameLogic* logic): Game::Game(logic) {}

GameLogic* ReversiGame::getGameLogic() const {
    return this->logic;
}


