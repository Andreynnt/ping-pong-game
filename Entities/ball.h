#ifndef PING_PONG_BALL_H
#define PING_PONG_BALL_H

#include <SFML/Audio.hpp>
#include "paddle_player.h"
#include "score.h"

class ball : public Entity {
public:
    ball(Score* score1, Score* score2, paddle *player1,  paddle *player2);
    void Update(sf::RenderWindow *window);

    bool GoingToCeil();
    bool GoingToFloar();

    void AddVelocity(paddle* paddle);
    void Reset(sf::RenderWindow* window);
    ~ball();
private:
    Score* score1;
    Score* score2;
    paddle *player1;
    paddle *player2;
    sf::SoundBuffer *buffer;
    sf::Sound *sound;

    sf::SoundBuffer *score_buffer;
    sf::Sound *score_sound;
};



#endif //PING_PONG_BALL_H
