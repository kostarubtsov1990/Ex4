/*
 * Name: Kosta Rubtsov
 * Id: 319206892
 * Name: Alon Barkan
 * Id: 200958296
 */

#ifndef EX2_GAMEMENU_H
#define EX2_GAMEMENU_H

#include "GameFlow.h"

class GameMenu {
    public:
        virtual void Start() = 0;
        virtual GameFlow* GetGameFlow () = 0;
        virtual ~GameMenu();
};


#endif //EX2_GAMEMENU_H
