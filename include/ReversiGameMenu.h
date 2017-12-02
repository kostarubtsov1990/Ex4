/*
 * Name: Kosta Rubtsov
 * Id: 319206892
 * Name: Alon Barkan
 * Id: 200958296
 */

#ifndef EX2_REVERSIGAMEMENU_H
#define EX2_REVERSIGAMEMENU_H

#include "GameFlow.h"
#include "SinglePlayerFlow.h"
#include "MultiPlayerFlow.h"
#include "GameMenu.h"
#include "DefaultLogic.h"

class ReversiGameMenu : public GameMenu {

private:
    //All of the user choices through the game menu process.
    GameFlow* userChoiceFlow;
public:
    void Start();
    GameFlow* GetGameFlow ();
    ~ReversiGameMenu();
};


#endif //EX2_REVERSIGAMEMENU_H
