/*
 * Name: Kosta Rubtsov
 * Id: 319206892
 * Name: Alon Barkan
 * Id: 200958296
 */

#ifndef EX2_MULTIPLAYERFLOW_H
#define EX2_MULTIPLAYERFLOW_H

#include "GameFlow.h"
#include "ReversiGame.h"

/*
 * MultiPlayerFlow is responsible for the flow of the two players program.
 * its run method activates for each of the players the methods
 * RunCurrentTurnOfTheGame that is actually a full turn played
 * by the current player, with printings to the screen and updatings of the
 * board till game's over.
 */

enum gameType {local, remote};

class MultiPlayerFlow : public GameFlow {
public:
//    MultiPlayerFlow();
    MultiPlayerFlow(Game* game, gameType type);
    virtual void Run();
    ~MultiPlayerFlow();

private:
    
    gameType type;
    
    void RunLocal();
    void RunRemote();
    void PrintHandler(playerIdentifier id, const vector<Cell>& possibleLocations) const;
    string RunCurrentTurnOfTheGame(playerIdentifier id, boardContent symbol);
    Cell InputHandler() const;
};

#endif //EX2_MULTIPLAYERFLOW_H
