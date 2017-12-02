/*
 * Name: Kosta Rubtsov
 * Id: 319206892
 * Name: Alon Barkan
 * Id: 200958296
 */

#ifndef EX2_SINGLEPLAYERFLOW_H
#define EX2_SINGLEPLAYERFLOW_H

#include "GameFlow.h"
#include "ReversiGame.h"


/*
 * SinglePlayerFlow is responsible for the flow of the player versus computer program.
 * its run method activates for each of the players human and computer
 * the appropriate methods (RunHumanPlayerGame and RunAIPlayerGame) that are actually a full turn played
 * by each of players, with printings to the screen and updatings of the
 * board till game's over.
 */
class SinglePlayerFlow : public GameFlow{
public:
    SinglePlayerFlow(Game* game);
    virtual void Run();
    ~SinglePlayerFlow();
private:
    void RunHumanPlayerGame(playerIdentifier id, boardContent symbol);
    void RunAIPlayerGame(playerIdentifier id, boardContent symbol);
    void PrintHandler(playerIdentifier id, const vector<Cell>& possibleLocations) const;
    Cell InputHandler() const;
    /*
     * This function will find the score for each of the hypothetically possible moves for the player.
     * The score equals to subscribing the amount of the  X symbols from O symbols.
     * which means that the lower score the better for the computer if its symbol is O.
     */
    int GetScore (Board* board);
    playerIdentifier player;
    playerIdentifier computer;

};


#endif //EX2_SINGLEPLAYERFLOW_H
