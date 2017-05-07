#include "paddle_ai.h"
#include <iostream>

paddle_ai::paddle_ai(int playerNumber)
{
    this->playerNumber = playerNumber;
    this->ballObject = ballObject;
    this->speed = 0.89f;
    switch (this->playerNumber)
    {
        case 0:
            this->Load("../Graphics/Sprites/paddle1.png");
            break;
        default:
            this->Load("../Graphics/Sprites/paddle2.png");
            break;
    }
}

void paddle_ai::setBall(ball *ballObject)
{
    this->ballObject = ballObject;
}

void paddle_ai::Update()
{
    if (this->ballObject) {
        if (this->getPosition().y + this->getGlobalBounds().height / 2 < this->ballObject->getPosition().y) {
            this->move(0, this->speed);
        }
        if (this->getPosition().y + this->getGlobalBounds().height / 2 > this->ballObject->getPosition().y) {
            this->move(0, -this->speed);
        }
    }
    Entity::Update();
    if (this->getPosition().y < 0)
    {
        this->move(0, 1.0f);
    }
    if (this->getPosition().y + this->getGlobalBounds().height > 800)
    {
        this->move(0, -1.0f);
    }
}