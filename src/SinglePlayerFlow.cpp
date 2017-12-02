/*
 * Name: Kosta Rubtsov
 * Id: 319206892
 * Name: Alon Barkan
 * Id: 200958296
 */

#include "../include/SinglePlayerFlow.h"
#include <cstdlib>
#include <map>

SinglePlayerFlow::SinglePlayerFlow(Game *game) : GameFlow(game){
    player = xplayer;
    computer = oplayer;
}


void SinglePlayerFlow::Run() {

    GameLogic* logic = game->GetLogic();
    Board* board = game->GetBoard();

    cout << "current board:" << endl << endl;
    board->printBoard();

    //each player plays its turn till game's over.
    while (!logic->IsGameOver(board)) {//?
        RunHumanPlayerGame(xplayer, X);
        RunAIPlayerGame(oplayer, O);
    }
    //declare the winner of the game (or draw)
    logic->DeclareWinner(board);
}


void SinglePlayerFlow::RunHumanPlayerGame(playerIdentifier id,
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
    while(!logic->IsLocationValid(chosenCell)) {
        PrintHandler(id, logic->GetMoves());
        chosenCell = InputHandler();
    }
    //update the board and print it to the screen
    logic->UpdateBoard(board,chosenCell.getX(),chosenCell.getY(),symbol);
    cout << "current board:" << endl << endl;
    board->printBoard();
}

void SinglePlayerFlow::RunAIPlayerGame(playerIdentifier id, boardContent symbol) {
    int min = NUM_OF_ROWS*NUM_OF_ROWS;
    map <int , Cell> cellToScore;
    GameLogic* logic = game->GetLogic();
    Board* board = game->GetBoard();
    //check possible moves of current player
    logic->CheckPossibleMoves(board,id);
    vector <Cell> computerMoves = logic->GetMoves();

    PrintHandler(id,logic->GetMoves());
    //if no possible moves, pass turn to the second player
    if (logic->GetMoves().empty()) {
        return;
    }

    for (int i = 0; i < computerMoves.size(); ++i) {
        int max = -NUM_OF_ROWS*NUM_OF_ROWS;

        //Implement cc'tor for board and make a copy from original board
        Board currentBoard = *board;
        //Make one step from the possible moves
        logic->CheckPossibleMoves(&currentBoard,id);
        logic->UpdateBoard(&currentBoard, computerMoves[i].getX(), computerMoves[i].getY(), O);
        //Find all the possible moves for that step for the human player.
        logic->CheckPossibleMoves(&currentBoard,xplayer);
        //for moves for the human player go through the loop..
        for (int j = 0; j < logic->GetMoves().size(); ++j) {
            Board humanPlayerBoard = currentBoard;
            logic->UpdateBoard(&humanPlayerBoard, logic->GetMoves()[j].getX(), logic->GetMoves()[j].getY(), X);
            int currentScore = GetScore(&humanPlayerBoard);
            if (max < currentScore) {
                max = currentScore;
            }
            //Find the maximum and save it
        }
        cellToScore[max] = computerMoves[i];
        //add the current cell with the max value.
    }

    //Go through the map and find the minimum key.
    for(map<int ,Cell>::iterator iter = cellToScore.begin(); iter != cellToScore.end(); ++iter)
    {
        int score =  iter->first;
        if (score < min) {
            min = score;
        }
    }

    //Take the step that is the best for the computer.
    logic->CheckPossibleMoves(board,id);
    Cell moveToTake = cellToScore[min];
    logic->UpdateBoard(board, moveToTake.getX(), moveToTake.getY(), O);
    cout << "current board:" << endl << endl;
    board->printBoard();
}


int SinglePlayerFlow::GetScore(Board *board) {
    int Xcounter = 0, Ocounter = 0;
    for (int i = 0; i < NUM_OF_ROWS; ++i) {
        for (int j = 0; j < NUM_OF_COLS; ++j) {
            if (board->getBoardContent()[i][j] == X) {
                Xcounter++;
            } else if (board->getBoardContent()[i][j] == O) {
                Ocounter++;
            }
        }
    }
    return Xcounter - Ocounter;
}

void SinglePlayerFlow::PrintHandler(playerIdentifier id,
                                   const vector<Cell>& possibleLocations) const {
    //xplayer
    if (id == player) {
        cout << "\nX: " << "It's your move." << endl;
    }
    //oplayer
    else {
        cout << "\n" << "It's computer move. Press enter to accept." << endl;
        string enter ="";
        getline(cin, enter);
    }
    //current player has no possible moves
    if (id == player && possibleLocations.empty()) {
        cout << "No possible moves. play passes back to the computer. Press enter to accept." << endl;
        string enter ="";
        getline(cin, enter);
    }
    else if (id == computer && possibleLocations.empty()) {
        cout << "No possible moves for the computer. It's your move now." << endl;
    }
        //print the possible moves to the screen
    else if (id == player) {
        cout << "Your possible moves: " << endl;
        possibleLocations[0].printFormatOfCell();
        for (int i = 1; i < possibleLocations.size(); i++) {
            cout << ", ";
            possibleLocations[i].printFormatOfCell();
        }
        cout << endl;
    }
}

Cell SinglePlayerFlow::InputHandler() const {

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

SinglePlayerFlow::~SinglePlayerFlow() {
    delete game;
}