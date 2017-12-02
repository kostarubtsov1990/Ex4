/*
 * Name: Kosta Rubtsov
 * Id: 319206892
 * Name: Alon Barkan
 * Id: 200958296
 */

#ifndef EX2_GAME_H
#define EX2_GAME_H

#include "Board.h"
#include "GameLogic.h"
/*
 * Game holds pointer to Board and to GameLogic. different logics
 * can be passed to its C'tor that gets general GameLogic so in run time
 * this pointer may point to any logic that can be added tomorrow.
 * In addition, it holds pointer to Board since board games are all holding
 * a board.
 */
class Game {
public:
    Game();
    Game(GameLogic* logic);
    Board* GetBoard() const;
    GameLogic* GetLogic() const;
    void SetBoard(Board* board);
    virtual ~Game();

protected:
    Board* board;
    GameLogic* logic;
};

#endif //EX2_GAME_H
