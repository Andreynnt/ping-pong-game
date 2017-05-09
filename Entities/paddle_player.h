#ifndef PING_PONG_PADDLE_PLAYER_H
#define PING_PONG_PADDLE_PLAYER_H

#include "paddle.h"
#define PADDLE_SPEED 7

class paddle_player : public paddle
{
public:
    paddle_player(int playerNumber);
    void Update();
private:
    int playerNumber;
};


#endif //PING_PONG_PADDLE_PLAYER_H
