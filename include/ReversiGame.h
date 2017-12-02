/*
 * Name: Kosta Rubtsov
 * Id: 319206892
 * Name: Alon Barkan
 * Id: 200958296
 */

#ifndef EX2_REVERSIGAME_H
#define EX2_REVERSIGAME_H

#define INITIAL_X_AND_O_COUNTER 2

#include "Game.h"
#include "GameLogic.h"

/*
 * ReversiGame is a son of the Game class and it gets its logic in its
 * C'tor that sends it to its father C'tor (the C'tor of Game class).
 */
class ReversiGame : public Game {

public:
    ~ReversiGame();
    ReversiGame(GameLogic* logic);
    GameLogic* getGameLogic() const;

};

#endif //EX2_REVERSIGAME_H
