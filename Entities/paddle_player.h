#pragma once
#include "paddle.h"
#ifndef PING_PONG_PADDLE_PLAYER_H
#define PING_PONG_PADDLE_PLAYER_H


class paddle_player : public paddle
{
public:
    paddle_player(int playerNumber);
    void Update();
private:
    int playerNumber;
};


#endif //PING_PONG_PADDLE_PLAYER_H
