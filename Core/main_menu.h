#ifndef PING_PONG_MAIN_MENU_H
#define PING_PONG_MAIN_MENU_H

#include "main_game.h"
#include "together_game.h"
#include "game_state.h"
#include "../Entities/background.h"

class main_menu : public tiny_state {
public:
    void Initialize(sf::RenderWindow *window);
    void Update(sf::RenderWindow *window);
    void Render(sf::RenderWindow *window);
    void Destroy(sf::RenderWindow *window);
private:
    sf::Font *font;
    sf::Text *title;
    sf::Text *play_solo;
    sf::Text *play_together;
    sf::Text *quit;
    background *back;
    int selected;
    float scale;
    float scaleInc;
    int mode;
    bool upKey, downKey, leftKey, rightKey;
    void UpdateMode(sf::RenderWindow *window);
};

#endif //PING_PONG_MAIN_MENU_H
