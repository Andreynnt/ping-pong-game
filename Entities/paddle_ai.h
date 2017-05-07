#pragma once
#include "ball.h"
#include "paddle.h"

#ifndef PING_PONG_PADDLE_AI_H
#define PING_PONG_PADDLE_AI_H


class paddle_ai : public paddle {
public:
    paddle_ai(int playerNumber);
    void setBall(ball *ballObject);
    void Update();
private:
    ball *ballObject;
    int playerNumber;
    float speed;
};

#endif //PING_PONG_PADDLE_AI_H
