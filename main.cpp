#include <SFML/Window.hpp>
#include "Core/game_state.h"
#include "Core/main_menu.h"
game_state coreState;
bool quitGame = false;

int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Ping!");
    coreState.SetWindow(&window);
    coreState.SetState(new main_menu());

    sf::Clock timer;
    sf::Time elapsed;

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }

        elapsed = timer.getElapsedTime();
        if (elapsed.asMicroseconds() > 16666)
        {
            window.clear(sf::Color::Cyan);
            coreState.Update();
            coreState.Render();
            window.display();
            if (quitGame){
                window.close();
            }
            timer.restart();
        }
    }
    return 0;
}