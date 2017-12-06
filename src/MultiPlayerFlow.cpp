/*
 * Name: Kosta Rubtsov
 * Id: 319206892
 * Name: Alon Barkan
 * Id: 200958296
 */

#include <cstdlib>
#include <zconf.h>
#include <cstring>
#include <sstream>
#include "../include/MultiPlayerFlow.h"
#include "../include/GameClient.h"
#define BUF_SIZE 1024

using namespace std;
/*
MultiPlayerFlow::MultiPlayerFlow() {
    
}
*/
MultiPlayerFlow::MultiPlayerFlow(Game* game, gameType type): type(type),  GameFlow::GameFlow(game){}

void MultiPlayerFlow::Run() {
    //This will run one of the possible game types of multi player.
    switch (type){
        case local:
            RunLocal();
        case remote:
            RunRemote();
    }
}

void MultiPlayerFlow::RunLocal() {
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

void MultiPlayerFlow::RunRemote() {
    playerIdentifier player;
    boardContent playerSymbol;
    boardContent opponentPlayerSymbol;
    GameLogic* logic = game->GetLogic();
    Board* board = game->GetBoard();

    char answerBuffer [BUF_SIZE];
    int gameClientSocket;

    GameClient gameClient("127.0.0.1",8000);
    try {
        gameClientSocket = gameClient.connectToServer();
    }catch (const char* msg) {
        cout << "Failed to connect to server. Reason: " << msg << endl;
        exit(-1);
    }

    int n = read(gameClientSocket, answerBuffer, sizeof(answerBuffer));


    if (strcmp(answerBuffer, "wait_for_opponent") == 0){
        player = xplayer;
        playerSymbol = X;
        opponentPlayerSymbol = O;
        n = read(gameClientSocket, answerBuffer, sizeof(answerBuffer));
    }
    else if (strcmp(answerBuffer, "Wait_for_first_move") == 0) {
        player = oplayer;
        playerSymbol = O;
        opponentPlayerSymbol = X;
        n = read(gameClientSocket, answerBuffer, sizeof(answerBuffer));
        logic->UpdateBoard(board, atoi(&answerBuffer[0]), atoi(&answerBuffer[1]), playerSymbol);
    } else {
        cout<<"Writing error occurred";
        return;
    }

    //each player plays its turn till game's over.
    while (!logic->IsGameOver(board)) {
        string result = RunCurrentTurnOfTheGame(player, playerSymbol);
        //To add failure condition.
        int n = write(gameClientSocket, result.c_str(), strlen(result.c_str()) + 1);
        n = read(gameClientSocket, answerBuffer, sizeof(answerBuffer));
        logic->UpdateBoard(board, atoi(&answerBuffer[0]), atoi(&answerBuffer[1]), opponentPlayerSymbol);
    }
    //To add finishing massages to close the opponent client.
}

string MultiPlayerFlow::RunCurrentTurnOfTheGame(playerIdentifier id,
                                               boardContent symbol) {
    GameLogic* logic = game->GetLogic();
    Board* board = game->GetBoard();
    //check possible moves of current player
    logic->CheckPossibleMoves(board,id);

    PrintHandler(id,logic->GetMoves());
    //if no possible moves, pass turn to the second player
    if (logic->GetMoves().empty()) {
        return "no_moves";
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

    ostringstream ss;
    ss << chosenCell.getX() << chosenCell.getY();
    return ss.str();


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
