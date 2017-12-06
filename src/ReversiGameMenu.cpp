/*
 * Name: Kosta Rubtsov
 * Id: 319206892
 * Name: Alon Barkan
 * Id: 200958296
 */

#include <cstdio>
#include "../include/ReversiGameMenu.h"


void ReversiGameMenu::Start() {
    cout<<"~Welcome to Reversi Game~"<<endl<<endl;
    cout<<"Please choose below options:"<<endl;
    cout<<"1.Single Player"<<endl;
    cout<<"2.Local Multi Player"<<endl;
    cout<<"3.Remote Multi Player"<<endl<<endl;
    cout<<"Press the number and enter to continue: ";

    int gameOption;
    cin>>gameOption;

    cout<<endl<<"Please choose the game style:"<<endl;
    cout<<"1.Classic Game"<<endl;
    cout<<"2.Alternate Game"<<endl<<endl;
    cout<<"Press the number and enter to continue: ";

    int gameStyleOption;
    cin>>gameStyleOption;
    getchar();

    GameLogic* logic;
    Game* game;
    Board* board;


    switch (gameStyleOption) {
        case 1:
            logic = new DefaultLogic();
            game = new ReversiGame(logic);
            board = new Board();
            game->SetBoard(board);

            switch (gameOption) {
                case 1:
                    //To add SinglePlayerFlow in the future.
                    userChoiceFlow = new SinglePlayerFlow(game);
                    break;
                case 2:
                    userChoiceFlow = new MultiPlayerFlow(game,local);
                    break;
                case 3:
                    userChoiceFlow = new MultiPlayerFlow(game,remote);
                    break;
            }
            break;

        //Add alternate game style in the future.
        case 2:
            break;
    }
}

GameFlow* ReversiGameMenu::GetGameFlow() {
    return userChoiceFlow;
}

ReversiGameMenu::~ReversiGameMenu() {
    delete userChoiceFlow;
}