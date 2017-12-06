//
// Created by kostarubtsov1990 on 04/12/17.
//

#ifndef EX4_GAMECLIENT_H
#define EX4_GAMECLIENT_H


class GameClient {
public:
    GameClient(const char* serverIP, int serverPort);
    int connectToServer();

private:
    const char* serverIP;
    int serverPort;
    int clientSocket;

};


#endif //EX4_GAMECLIENT_H
