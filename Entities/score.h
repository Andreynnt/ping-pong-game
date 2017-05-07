#pragma once
#include <SFML/Graphics.hpp>

#ifndef PING_PONG_SCORE_H
#define PING_PONG_SCORE_H

class Score : public sf::Text {
public:
    Score(sf::Font &font, unsigned int size);
    void IncrementScore();
    void Update();
private:
    sf::Font *font;
    int value;
};


#endif //PING_PONG_SCORE_H
