/*
 * Name: Kosta Rubtsov
 * Id: 319206892
 * Name: Alon Barkan
 * Id: 200958296
 */


/*
#include "../gtest_src/gtest/gtest.h"
#include "../include/DefaultLogic.h"
*/

#include "gtest/gtest.h"
#include "../../include/DefaultLogic.h"
#include <fstream>
#include "BoardTest.h"
#include "UpdateBoardTest.h"
#include "WinOrLoseTest.h"


const Board createBoardFromFile(const char* fileName) {

    string line;
    string boardStr;
    ifstream myfile(fileName);

    if (myfile.is_open()) {
        for (int i = 0; i < NUM_OF_ROWS; i++) {
            getline(myfile, line);
            boardStr += line;
            boardStr += "\n";
        }
    }
    myfile.close();


    Board b = Board(boardStr);
    return b;
}


TEST_F(BoardTest, CheckPossibleMovesMethod) {

    DefaultLogic dl = DefaultLogic();

    Board b = Board();

    dl.CheckPossibleMoves(&b,xplayer);
    EXPECT_EQ(dl.GetMoves().size(),4);

    dl.CheckPossibleMoves(&b,oplayer);
    EXPECT_EQ(dl.GetMoves().size(),4);


    //Board b1 = createBoardFromFile("noPossibleMovesForX.txt");
    dl.CheckPossibleMoves(noPossMovesForXBoard, xplayer);
    EXPECT_EQ(dl.GetMoves().size(), 0);


    //Board b2 = createBoardFromFile("eightPossMovesForO.txt");
    dl.CheckPossibleMoves(eightPossMovesForOBoard, oplayer);
    EXPECT_EQ(dl.GetMoves().size(), 8);


    //Board b3 = createBoardFromFile("noPossibleMovesForO.txt");
    dl.CheckPossibleMoves(noPossMovesForOBoard, oplayer);
    EXPECT_EQ(dl.GetMoves().size(), 0);

}

TEST_F (BoardTest, CheckIfGameIsOver) {

    DefaultLogic dl = DefaultLogic();
    Board b = Board();

    for (int i = 0; i < NUM_OF_ROWS; i++) {
        for (int j = 0; j < NUM_OF_COLS; j++) {
            b.getBoardContent()[i][j] = X;
        }
    }
    EXPECT_TRUE(dl.IsGameOver(&b));

    for (int i = 0; i < NUM_OF_ROWS; i++) {
        for (int j = 0; j < NUM_OF_COLS; j++) {
            b.getBoardContent()[i][j] = O;
        }
    }

    EXPECT_TRUE(dl.IsGameOver(&b));

    //Board b1 = createBoardFromFile("noPossibleMovesForX.txt");
    EXPECT_FALSE(dl.IsGameOver(noPossMovesForXBoard));

   // Board b2 = createBoardFromFile("noPossibleMovesForO.txt");
    EXPECT_FALSE(dl.IsGameOver(noPossMovesForOBoard));
}


TEST_F (BoardTest, CheckIfChosenLocationIsValid) {

    DefaultLogic dl = DefaultLogic();
    Board b = Board();
    dl.CheckPossibleMoves(&b,xplayer);

    //The case where location doesnt appear in moves vector.
    EXPECT_FALSE(dl.IsLocationValid(Cell(0,0)));

    dl.CheckPossibleMoves(eightPossMovesForOBoard, oplayer);
    //The case where location appear in moves vector.
    EXPECT_TRUE(dl.IsLocationValid(Cell(2,4)));


    dl.CheckPossibleMoves(noPossMovesForOBoard, oplayer);
    //The case where the moves vector is empty.
    EXPECT_FALSE(dl.IsLocationValid(Cell(2,4)));

}


TEST_F(UpdateBoardTest, CheckUpdateBoardMethod) {
    DefaultLogic dl = DefaultLogic();
    //Check every possible direction of reversal row.

    dl.CheckPossibleMoves(beforeRightBlockForXBoard, xplayer);
    dl.UpdateBoard(beforeRightBlockForXBoard, 4, 1, X);
    EXPECT_TRUE(*beforeRightBlockForXBoard == *afterRightBlockForXBoard);

    dl.CheckPossibleMoves(beforeLeftBlockForXBoard, xplayer);
    dl.UpdateBoard(beforeLeftBlockForXBoard, 2, 6, X);
    EXPECT_TRUE(*beforeLeftBlockForXBoard == *afterLeftBlockForXBoard);

    dl.CheckPossibleMoves(beforeUpBlockForXBoard, xplayer);
    dl.UpdateBoard(beforeUpBlockForXBoard, 5, 2, X);
    EXPECT_TRUE(*beforeUpBlockForXBoard == *afterUpBlockForXBoard);

    dl.CheckPossibleMoves(beforeDownBlockForXBoard, xplayer);
    dl.UpdateBoard(beforeDownBlockForXBoard, 2, 1, X);
    EXPECT_TRUE(*beforeDownBlockForXBoard == *afterDownBlockForXBoard);

    dl.CheckPossibleMoves(beforeRightUpBlockForXBoard, xplayer);
    dl.UpdateBoard(beforeRightUpBlockForXBoard, 4, 2, X);
    EXPECT_TRUE(*beforeRightUpBlockForXBoard == *afterRightUpBlockForXBoard);

    dl.CheckPossibleMoves(beforeRightDownBlockForOBoard, oplayer);
    dl.UpdateBoard(beforeRightDownBlockForOBoard, 2, 2, O);
    EXPECT_TRUE(*beforeRightDownBlockForOBoard == *afterRightDownBlockForOBoard);

    dl.CheckPossibleMoves(beforeLeftDownBlockForXBoard, xplayer);
    dl.UpdateBoard(beforeLeftDownBlockForXBoard, 1, 5, X);
    EXPECT_TRUE(*beforeLeftDownBlockForXBoard == *afterLeftDownBlockForXBoard);

    dl.CheckPossibleMoves(beforeUpLeftBlockForOBoard, oplayer);
    dl.UpdateBoard(beforeUpLeftBlockForOBoard, 3, 6, O);
    EXPECT_TRUE(*beforeUpLeftBlockForOBoard == *afterUpLeftBlockForOBoard);

    //Check two reversal rows directions.
    dl.CheckPossibleMoves(beforeTwoBlocksForOBoard, oplayer);
    dl.UpdateBoard(beforeTwoBlocksForOBoard, 5, 3, O);
    EXPECT_TRUE(*beforeTwoBlocksForOBoard == *afterTwoBlocksForOBoard);

    //Check three reversal rows directions.
    dl.CheckPossibleMoves(beforeThreeBlocksForXBoard, xplayer);
    dl.UpdateBoard(beforeThreeBlocksForXBoard, 2, 5, X);
    EXPECT_TRUE(*beforeThreeBlocksForXBoard == *afterThreeBlocksForXBoard);
}

TEST_F(WinOrLoseTest, DeclareWinnerMethodTest) {
    DefaultLogic dl = DefaultLogic();
    //Check the case where X wins.
    testing::internal::CaptureStdout();
    dl.DeclareWinner(XwinsBoard);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "X Player Is The Winner!\n");

    //Check the case where O wins.
    testing::internal::CaptureStdout();
    dl.DeclareWinner(OwinsBoard);
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "O Player Is The Winner!\n");

    //Check the case where there is a draw.
    testing::internal::CaptureStdout();
    dl.DeclareWinner(DrawGameBoard);
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Draw!\n");

}




