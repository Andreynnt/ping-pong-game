#ifndef PING_PONG_PADDLE_AI_H
#define PING_PONG_PADDLE_AI_H

#include "ball.h"
#include "paddle.h"

class paddle_ai : public paddle {
public:
    paddle_ai(int playerNumber, int difficulty);
    void setBall(ball *ballObject);
    void Update();
private:
    bool ballAway();
    sf::Vector2f target;
    ball *ballObject;
    int playerNumber;
    float speed;
};

#endif //PING_PONG_PADDLE_AI_H
