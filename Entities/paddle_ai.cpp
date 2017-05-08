#include "paddle_ai.h"


paddle_ai::paddle_ai(int playerNumber, int difficulty)
{
    this->playerNumber = playerNumber;
    this->ballObject = ballObject;
    switch(difficulty){
        case 1:
            this->speed = 1.20f * PADDLE_SPEED;
            break;
        case 2:
            this->speed = 1.50f * PADDLE_SPEED;
            break;
        default:
            this->speed = 1.70f * PADDLE_SPEED;
            break;
    }
    this->Load("../Graphics/Sprites/paddle2.png");


}

void paddle_ai::setBall(ball *ballObject)
{
    this->ballObject = ballObject;
}

bool paddle_ai::ballAway()
{
    if (this->playerNumber == 0)
    {
        return this->ballObject->velocity.x > 0;
    }
    return this->ballObject->velocity.x < 0;
}

void paddle_ai::Update() {
    if (this->ballObject) {

        if (this->ballAway()) {
            if (target.x < 0) {
                target.x = 1;
                target.y = rand() % 800;
            }
            float temp = ((this->getPosition().y + this->getGlobalBounds().height / 2) - this->target.y - 10);
            if (temp < -5.0f) {
                this->velocity.y = this->speed;
            }
            if (temp > 5.0f) {
                this->velocity.y = -this->speed;
            }
        } else {
            target = sf::Vector2f(-1, 0);
            float temp = ((this->getPosition().y + this->getGlobalBounds().height / 2) - this->ballObject->getPosition().y);
            if (temp < -5.0f) {
                this->velocity.y = this->speed;
            }
            if (temp > 5.0f) {
                this->velocity.y = -this->speed;
            }
        }

    }

    Entity::Update();
    if (this->getPosition().y < 0)
    {
        this->move(0, this->speed);
    }
    if (this->getPosition().y + this->getGlobalBounds().height > 800)
    {
        this->move(0, -this->speed);
    }
}