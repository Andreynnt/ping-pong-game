#include "ball.h"

ball::ball(Score* score1, Score* score2, paddle *player1,  paddle *player2) {
    this->Load("../Graphics/Sprites/ball2.png");
    this->score1 = score1;
    this->score2 = score2;
    this->player1 = player1;
    this->player2 = player2;
    this->velocity.y = 1.0f;
    this->buffer = new sf::SoundBuffer();
    this->buffer->loadFromFile("../Sounds/bounce.wav");
    this->sound = new sf::Sound(*this->buffer);
}

void ball::AddVelocity(paddle* paddle){
    if (this->velocity.y > 0){
        if (paddle->velocity.y > 0) {
            this->velocity.y *= 1.30f;
        }else if(paddle->velocity.y < 0 && this->velocity.y != 5.5f){
            this->velocity.y = 5.5f;
        }
    }else if(this->velocity.y < 0){
        if (paddle->velocity.y < 0) {
            this->velocity.y *=  1.30f;
        }else if(paddle->velocity.y > 0 && this->velocity.y != -5.5f){
            this->velocity.y = -5.5f;
        }
    }
}

bool ball::GoingToCeil() {
    float py = 0;
    float oy = this->getPosition().y;
    float vy = this->velocity.y;
    float d = (py - oy) / vy;
    float ox = this->getPosition().x;
    float vx = this->velocity.x;
    float px = d * vx + ox;
    return  (px > 5 || px < 1200);
}

bool ball::GoingToFloar(){
    float py = 1200;
    float oy = this->getPosition().y;
    float vy = this->velocity.y;
    float d = (py - oy) / vy;
    float ox = this->getPosition().x;
    float vx = this->velocity.x;
    float px = d * vx + ox;
    return  (px > 5 || px < 1200);
}



void ball::Update(sf::RenderWindow *window) {

    if (this->CheckCollision(this->player1)) {
                this->velocity.x *= -1;
                AddVelocity(player1);
                this->sound->play();
    }
    if (this->CheckCollision(this->player2)) {
                this->velocity.x *= -1;
                AddVelocity(player2);
                this->sound->play();
    }
    if (this->getPosition().y < 0 || this->getPosition().y + this->getGlobalBounds().height > window->getSize().y) {
        this->velocity.y *= -1;
        this->sound->play();
    }
    if (this->getPosition().x <  this->player1->getGlobalBounds().width - 5) {
        this->score2->IncrementScore();
        this->Reset(window);
    }
    if (this->getPosition().x  > window->getSize().x - this->player2->getGlobalBounds().width + 5) {
        this->score1->IncrementScore();
        this->Reset(window);
    }
    Entity::Update();
}

void ball::Reset(sf::RenderWindow *window) {
    this->velocity.x = ((rand() % 2) == 0) ? 6.5f : -6.5f;
    this->velocity.y = ((rand() % 2) == 0) ? 6.5f : -6.5f;
    this->setPosition(window->getSize().x / 2 - 14, window->getSize().y / 2 - 10);
}

ball::~ball() {
    delete(this->buffer);
    delete(this->sound);
}