
#ifndef PING_PONG_GAME_STATE_H
#define PING_PONG_GAME_STATE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

extern bool quitGame;

class tiny_state {
public:
    tiny_state() { }
    virtual void Initialize(sf::RenderWindow *window) { }
    virtual void Update(sf::RenderWindow *window) { }
    virtual void Render(sf::RenderWindow *window) { }
    virtual void Destroy(sf::RenderWindow *window) { }
private:
};

class game_state {
public:
    void SetWindow(sf::RenderWindow *window) {
        this->window = window;
    }
    void SetState(std::shared_ptr<tiny_state> state) {
        if (this->state != NULL) {
            this->state->Destroy(this->window);
        }
        this->state = state;
        if(this->state != NULL) {
            this->state->Initialize(this->window);
        }
    }
    void Update() {
        if (this->state != NULL) {
            this->state->Update(this->window);
        }
    }
    void Render() {
        if (this->state != NULL) {
            this->state->Render(this->window);
        }
    }

    static game_state& instance() {
        static game_state instance;
        return instance;
    }
private:
    game_state(game_state const&) = delete;
    game_state& operator= (game_state const&) = delete;

    game_state() {
        this->state = NULL;
    }
    ~game_state() {
        if (this->state != NULL) {
            this->state->Destroy(this->window);
        }
    }
    sf::RenderWindow *window;
    std::shared_ptr<tiny_state> state;
};



#endif //PING_PONG_GAME_STATE_H
