#pragma once
#include "main_menu.h"
#include "game_state.h"
#include "../Entities/entity.h"
#include "../Entities/score.h"
#include "../Entities/paddle_player.h"
#include "../Entities/ball.h"
#include "../Entities/paddle_ai.h"
#include "../Entities/background.h"

#ifndef PING_PONG_MAIN_GAME_H
#define PING_PONG_MAIN_GAME_H


class main_game : public tiny_state
{
public:
    void Initialize(sf::RenderWindow *window);
    void Update(sf::RenderWindow *window);
    void Render(sf::RenderWindow *window);
    void Destroy(sf::RenderWindow *window);
private:
    background *back;
    paddle_player *player1;
    paddle_ai *player2;
    ball *ballObject;
    Score *score1;
    Score *score2;
    sf::Font* font;
    sf::Text* pausedText;
    bool paused, enterKey;
};


#endif //PING_PONG_MAIN_GAME_H
