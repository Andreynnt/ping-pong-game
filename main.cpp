#include <SFML/Window.hpp>
#include "Core/game_state.h"
#include "Core/main_menu.h"

game_state coreState;
bool quitGame = false;

int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Ping!");
    coreState.SetWindow(&window);
    coreState.SetState(new main_menu());
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Cyan);
        coreState.Update();
        coreState.Render();
        window.display();

        if (quitGame){
            window.close();
        }
    }
    return 0;
}