#ifndef PING_PONG_TOGETHER_GAME_H
#define PING_PONG_TOGETHER_GAME_H

#include "main_menu.h"
#include "game_state.h"
#include "../Entities/entity.h"
#include "../Entities/score.h"
#include "../Entities/paddle_player.h"
#include "../Entities/ball.h"
#include "../Entities/paddle_ai.h"
#include "../Entities/background.h"

class together_game : public tiny_state{
public:
    void Initialize(sf::RenderWindow *window);
    void Update(sf::RenderWindow *window);
    void Render(sf::RenderWindow *window);
    void Destroy(sf::RenderWindow *window);
private:
    background *back;
    paddle_player *player1;
    paddle_player *player2;
    ball *ballObject;
    Score *score1;
    Score *score2;
    sf::Font* font;
    sf::Font* pausedFont;
    sf::Font* scoreFont;
    sf::Text* pausedText;
    bool paused, enterKey;
    sf::Clock startTimer;
    sf::Time startElapsed;
    sf::Text* startDigits;

};



#endif //PING_PONG_TOGETHER_GAME_H
