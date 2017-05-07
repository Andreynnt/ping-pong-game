#include <SFML/Graphics.hpp>
#include <iostream>
#ifndef PING_PONG_GAME_STATE_H
#define PING_PONG_GAME_STATE_H

class tiny_state
{
public:
    tiny_state()
    {
    }
    virtual void Initialize(sf::RenderWindow *window)
    {
    }
    virtual void Update(sf::RenderWindow *window)
    {
    }
    virtual void Render(sf::RenderWindow *window)
    {
    }
    virtual void Destroy(sf::RenderWindow *window)
    {
    }
private:

};

class game_state
{
public:
    game_state()
    {
        this->state = NULL;
    }

    void SetWindow(sf::RenderWindow *window)
    {
        this->window = window;
    }

    void SetState(tiny_state *state)
    {
        if (this->state != NULL)
        {
            this->state->Destroy(this->window);
        }
        delete this->state;
        this->state = state;
        if(this->state != NULL)
        {
            this->state->Initialize(this->window);
        }
    }

    void Update()
    {
        if (this->state != NULL)
        {
            this->state->Update(this->window);
        }
    }

    void Render()
    {
        if (this->state != NULL)
        {
            this->state->Render(this->window);
        }
    }

    ~game_state()
    {
        if (this->state != NULL)
        {
            this->state->Destroy(this->window);
        }
    }
private:
    sf::RenderWindow *window;
    tiny_state *state;
};

extern game_state coreState;
extern bool quitGame;



#endif //PING_PONG_GAME_STATE_H
