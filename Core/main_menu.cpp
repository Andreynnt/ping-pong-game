#include "main_menu.h"

void main_menu::Initialize(sf::RenderWindow *window)
{
    this->back = new background("../Graphics/wood.jpg");

    this->selected = 0;
    this->font = new sf::Font();
    this->font->loadFromFile("../Graphics/font1.otf");

    this->title = new sf::Text("P!ng", *this->font, 256U);
    this->title->setFillColor(sf::Color::White);
    this->title->setOrigin(this->title->getGlobalBounds().width / 2 , this->title->getGlobalBounds().height / 2 );
    this->title->setPosition(window->getSize().x / 2, window->getSize().y / 8);

    this->play_solo = new sf::Text("Play solo", *this->font, 128U);
    this->play_solo->setOrigin(this->play_solo->getGlobalBounds().width / 2 , this->play_solo->getGlobalBounds().height / 2 );
    this->play_solo->setPosition(window->getSize().x / 2, window->getSize().y / 2);

    this->play_together = new sf::Text("Play VS", *this->font, 128U);
    this->play_together->setOrigin(this->play_together->getGlobalBounds().width / 2 , this->play_together->getGlobalBounds().height / 2 );
    this->play_together->setPosition(window->getSize().x / 2, window->getSize().y / 2 + this->play_solo->getGlobalBounds().height);

    this->quit = new sf::Text("Quit", *this->font, 128U);
    this->quit->setOrigin(this->quit->getGlobalBounds().width / 2 , this->quit->getGlobalBounds().height / 2 );
    this->quit->setPosition(window->getSize().x / 2, window->getSize().y / 2 + 2 * this->play_solo->getGlobalBounds().height);


    paused = false;
}

void main_menu::Update(sf::RenderWindow *window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !this->upKey)
    {
        this->selected -= 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !this->downKey)
    {
        this->selected += 1;
    }

    if (this->selected > 2)
    {
        this->selected = 0;
    }

    if (this->selected < 0)
    {
        this->selected = 2;
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
    {
        switch (this->selected)
        {
            case 0:
                coreState.SetState(new main_game());
                break;
            case 1:
                coreState.SetState(new together_game());
                break;
            case 2:
                quitGame = true;
                break;
        }
    }

    this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
    this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);

    if (paused)
    {
        // normal game
        paused = true;
    }
    else
    {
        //paused game
    }
}

void main_menu::Render(sf::RenderWindow *window)
{
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

void main_menu::Destroy(sf::RenderWindow *window)
{
    delete this->font;
    delete this->title;
    delete this->play_solo;
    delete this->play_together;
    delete this->quit;
    delete this->back;
}