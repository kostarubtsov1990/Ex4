/*
 * Name: Kosta Rubtsov
 * Id: 319206892
 * Name: Alon Barkan
 * Id: 200958296
 */

#ifndef EX3_UPDATEBOARDTEST_H
#define EX3_UPDATEBOARDTEST_H

#include "gtest/gtest.h"
#include "../../include/Board.h"
#include <fstream>

class UpdateBoardTest: public testing::Test {
public:
    UpdateBoardTest();
    ~UpdateBoardTest();

private:
    Board* BoardFromFile (const char *fileName);
protected:
    Board* beforeTwoBlocksForOBoard;
    Board* afterTwoBlocksForOBoard;
    Board* beforeThreeBlocksForXBoard;
    Board* afterThreeBlocksForXBoard;
    Board* afterRightBlockForXBoard;
    Board* beforeRightBlockForXBoard;
    Board* beforeLeftBlockForXBoard;
    Board* afterLeftBlockForXBoard;
    Board* beforeUpBlockForXBoard;
    Board* afterUpBlockForXBoard;
    Board* beforeDownBlockForXBoard;
    Board* afterDownBlockForXBoard;
    Board* afterRightUpBlockForXBoard;
    Board* beforeRightUpBlockForXBoard;
    Board* beforeRightDownBlockForOBoard;
    Board* afterRightDownBlockForOBoard;
    Board* beforeLeftDownBlockForXBoard;
    Board* afterLeftDownBlockForXBoard;
    Board* beforeUpLeftBlockForOBoard;
    Board* afterUpLeftBlockForOBoard;
};


#endif //EX3_UPDATEBOARDTEST_H
