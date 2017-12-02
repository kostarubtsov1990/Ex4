/*
 * Name: Kosta Rubtsov
 * Id: 319206892
 * Name: Alon Barkan
 * Id: 200958296
 */

#ifndef EX2_GAMEFLOW_H
#define EX2_GAMEFLOW_H

#include "Game.h"
#include "ReversiGame.h"

class GameFlow {
public:
//    GameFlow();
    GameFlow(Game* game);
    Game* GetGame();
    virtual void Run() = 0;
    virtual ~GameFlow();

protected:
    Game* game;
};

#endif //EX2_GAMEFLOW_H
