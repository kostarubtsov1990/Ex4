/*
 * Name: Kosta Rubtsov
 * Id: 319206892
 * Name: Alon Barkan
 * Id: 200958296
 */

#include "../include/GameFlow.h"

GameFlow::~GameFlow() {}

GameFlow::GameFlow(Game* game): game(game){}

Game* GameFlow::GetGame() {
    return this->game;
}

