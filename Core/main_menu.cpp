#include "main_menu.h"

void main_menu::Initialize(sf::RenderWindow *window) {
    this->mode = 0;
    this->selected = 0;
    this->scale = 1;
    this->scaleInc = 0.01f;

    this->back = new background("../Graphics/cosmos.jpg");
    this->font = new sf::Font();
    this->font->loadFromFile("../Graphics/font1.otf");

    this->title = new sf::Text("P!ng", *this->font, 256U);
    this->title->setFillColor(sf::Color::White);
    this->title->setOrigin(this->title->getGlobalBounds().width / 2 , this->title->getGlobalBounds().height / 2 );
    this->title->setPosition(window->getSize().x / 2, window->getSize().y / 8);

    this->play_solo = new sf::Text("Easy", *this->font, 128U);
    this->play_solo->setOrigin(this->play_solo->getGlobalBounds().width / 2 , this->play_solo->getGlobalBounds().height / 2 );
    this->play_solo->setPosition(window->getSize().x / 2, window->getSize().y / 2);

    this->play_together = new sf::Text("Play VS", *this->font, 128U);
    this->play_together->setOrigin(this->play_together->getGlobalBounds().width / 2 , this->play_together->getGlobalBounds().height / 2 );
    this->play_together->setPosition(window->getSize().x / 2, window->getSize().y / 2 + this->play_solo->getGlobalBounds().height);

    this->quit = new sf::Text("Quit", *this->font, 128U);
    this->quit->setOrigin(this->quit->getGlobalBounds().width / 2 , this->quit->getGlobalBounds().height / 2 );
    this->quit->setPosition(window->getSize().x / 2, window->getSize().y / 2 + 2 * this->play_solo->getGlobalBounds().height);

}

void main_menu::Update(sf::RenderWindow *window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !this->upKey) {
        this->selected -= 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !this->downKey) {
        this->selected += 1;
    }
    if (this->selected > 2) {
        this->selected = 0;
    }
    if (this->selected < 0) {
        this->selected = 2;
    }

    if (this->selected == 0){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !this->leftKey) {
            this->mode -= 1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && !this->rightKey) {
            this->mode += 1;
        }
    }
    if (this->mode > 2) {
        this->mode = 0;
    }
    if (this->mode < 0) {
        this->mode = 2;
    }

    switch(mode){
        case 0:
            this->play_solo->setString("Easy");
            break;
        case 1:
            this->play_solo->setString("Norm");
            break;
        case 2:
            this->play_solo->setString("Hard");
            break;
    }

    this->play_solo->setScale(1, 1);
    this->play_together->setScale(1, 1);
    this->quit->setScale(1, 1);

    switch (this->selected){
        case 0:
            this->play_solo->setScale(this->scale, this->scale);
            break;
        case 1:
            this->play_together->setScale(this->scale, this->scale);
            break;
        case 2:
            this->quit->setScale(this->scale, this->scale);
            break;
    }

    this->scale += this->scaleInc;

    if (this->scale > 1.00f || this->scale < 0.8){
        this->scaleInc *= -1;
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)) {
        game_state& coreState = game_state::instance();
        switch (this->selected) {
            case 0:{
                std::shared_ptr<main_game> main(new main_game(this->mode));
                coreState.SetState(main);
            }
                break;
            case 1:{
                std::shared_ptr<together_game> together(new together_game());
                coreState.SetState(together);
            }
                break;
            case 2:
                quitGame = true;
                break;
        }
    }
    this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
    this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
    this->rightKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
    this->leftKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
}


void main_menu::Render(sf::RenderWindow *window) {
    window->draw(*this->back);

    this->play_solo->setFillColor(sf::Color::White);
    this->play_together->setFillColor(sf::Color::White);
    this->quit->setFillColor(sf::Color::White);
    switch(this->selected)
    {
        case 0:
            this->play_solo->setFillColor(sf::Color(93,236,203));
            break;
        case 1:
            this->play_together->setFillColor(sf::Color(93,236,203));
            break;
        case 2:
            this->quit->setFillColor(sf::Color(93,236,203));
            break;
    }

    window->draw(*this->title);
    window->draw(*this->play_solo);
    window->draw(*this->play_together);
    window->draw(*this->quit);
}

void main_menu::Destroy(sf::RenderWindow *window) {
    delete this->font;
    delete this->title;
    delete this->play_solo;
    delete this->play_together;
    delete this->quit;
    delete this->back;
}