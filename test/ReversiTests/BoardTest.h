/*
 * Name: Kosta Rubtsov
 * Id: 319206892
 * Name: Alon Barkan
 * Id: 200958296
 */

#ifndef EX3_BOARDTEST_H
#define EX3_BOARDTEST_H

#include "gtest/gtest.h"
#include "../../include/Board.h"
#include <fstream>

class BoardTest: public testing::Test {
public:
    BoardTest();
    ~BoardTest();
private:
    Board* BoardFromFile (const char *fileName);
protected:
    Board* eightPossMovesForOBoard;
    Board* noPossMovesForOBoard;
    Board* noPossMovesForXBoard;
};

#endif //EX3_BOARDTEST_H
