/*
 * Name: Alon Barkan
 * Id: 200958296
 */

#include "include/MultiPlayerFlow.h"
#include "include/GameMenu.h"
#include "include/ReversiGameMenu.h"

int main() {
    //create the default logic and reversi game with the default logic
    GameMenu* menu = new ReversiGameMenu ();
    menu->Start();
    GameFlow* flow = menu->GetGameFlow();
    flow->Run();


    delete menu;

    return 0;
}

