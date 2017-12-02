/*
 * Name: Kosta Rubtsov
 * Id: 319206892
 * Name: Alon Barkan
 * Id: 200958296
 */

#include <cstdlib>
#include "../include/MultiPlayerFlow.h"
#include "../include/ReversiGame.h"

/*
MultiPlayerFlow::MultiPlayerFlow() {
    
}
*/
MultiPlayerFlow::MultiPlayerFlow(Game* game): GameFlow::GameFlow(game){}

void MultiPlayerFlow::Run() {

    GameLogic* logic = game->GetLogic();
    Board* board = game->GetBoard();

    cout << "current board:" << endl << endl;
    board->printBoard();

    //each player plays its turn till game's over.
    while (!logic->IsGameOver(board)) {//?
        RunCurrentTurnOfTheGame(xplayer, X);
        RunCurrentTurnOfTheGame(oplayer, O);
    }
    //declare the winner of the game (or draw)
    logic->DeclareWinner(board);
}

void MultiPlayerFlow::RunCurrentTurnOfTheGame(playerIdentifier id,
                                               boardContent symbol) {
    GameLogic* logic = game->GetLogic();
    Board* board = game->GetBoard();
    //check possible moves of current player
    logic->CheckPossibleMoves(board,id);

    PrintHandler(id,logic->GetMoves());
    //if no possible moves, pass turn to the second player
    if (logic->GetMoves().empty()) {
        return;
    }
    //chosen cell of current player
    Cell chosenCell = this->InputHandler();
    //if cellisnt validask again the playerto choose cell from the possiblelist
    while(!logic->IsLocationValid(chosenCell)) {//
        PrintHandler(id, logic->GetMoves());
        chosenCell = InputHandler();
    }
    //update the board and print it to the screen
    logic->UpdateBoard(board,chosenCell.getX(),chosenCell.getY(),symbol);
    cout << "current board:" << endl << endl;
    board->printBoard();
}

void MultiPlayerFlow::PrintHandler(playerIdentifier id,
                                    const vector<Cell>& possibleLocations) const {
    //xplayer
    if (id == xplayer) {
        cout << "\nX: " << "It's your move." << endl;
    }
    //oplayer
    else {
        cout << "\nO: " << "It's your move." << endl;
    }
    //current player has no possible moves
    if (possibleLocations.empty()) {
        cout << "No possible moves. play passes back to the other player." << endl;
    }
    //print the possible moves to the screen
    else {
        cout << "Your possible moves: " << endl;
        possibleLocations[0].printFormatOfCell();
        for (int i = 1; i < possibleLocations.size(); i++) {
            cout << ", ";
            possibleLocations[i].printFormatOfCell();
        }
        cout << endl;
    }
}

Cell MultiPlayerFlow::InputHandler() const {

    cout << "Please enter your move row,col:";
    string input = "";
    getline(cin, input);
    //input is valid
    if (!((input.size() == 3) && (atoi(&input[0]) >= 1 && atoi(&input[0]) <= 8)
          &&(input[1] == ',')&&(atoi(&input[2]) >= 1 && atoi(&input[2]) <= 8))){
        return Cell(-1,-1);
    }
    //input is invalid
    else {
        int row, col;
        char comma;
        row = atoi(&input[0]);
        comma = input[1];
        col = atoi(&input[2]);

        row--;
        col--;
        return Cell(row, col);
    }
}

MultiPlayerFlow::~MultiPlayerFlow() {
    delete game;
}
