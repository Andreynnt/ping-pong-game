#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Core/game_state.h"
#include "Core/main_menu.h"

bool quitGame = false;

int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 800), "P!ng");
    game_state& coreState = game_state::instance();
    coreState.SetWindow(&window);
    std::shared_ptr<main_menu> menu(new main_menu());
    coreState.SetState(menu);

    sf::Clock timer;
    sf::Time elapsed;

    sf::SoundBuffer musicBuffer;
    musicBuffer.loadFromFile("../Sounds/trust_MkPKkUHd.wav");
    sf::Sound music(musicBuffer);
    music.setLoop(true);
    music.play();
    music.setVolume(30);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        elapsed = timer.getElapsedTime();
        if (elapsed.asMicroseconds() > 16666) {
            coreState.Update();
            coreState.Render();
            window.display();
            if (quitGame) {
                window.close();
            }
            timer.restart();
        }
    }
    music.stop();
    return 0;
}