
#include "main_menu.h"
void together_game::Initialize(sf::RenderWindow *window)
{
    this->back = new background("../Graphics/wood.jpg");
    this->font = new sf::Font();
    this->font->loadFromFile("../Graphics/font1.otf");

    this->score1 = new Score (*font, 64U);
    this->score2 = new Score (*font, 64U);
    this->score2->setPosition(window->getSize().x - this->score2->getGlobalBounds().width , 0);

    this->player1 = new paddle_player(0);
    this->player2 = new paddle_player(1);
    this->ballObject = new ball(this->score1, this->score2, this->player1, this->player2);

    this->ballObject->Reset(window);
}

void together_game::Update(sf::RenderWindow *window)
{
    this->ballObject->Update(window);
    this->player1->Update();
    this->player2->Update();
    this->score1->Update();
    this->score2->Update();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
    {
        coreState.SetState(new main_menu());
    }
}

void together_game::Render(sf::RenderWindow *window)
{
    window->draw(*this->back);
    window->draw(*this->ballObject);
    window->draw(*this->player1);
    window->draw(*this->player2);
    window->draw(*this->score1);
    window->draw(*this->score2);
}

void together_game::Destroy(sf::RenderWindow *window)
{
    delete this->back;
    delete this->player1;
    delete this->player2;
    delete this->ballObject;
    delete this->score1;
    delete this->score2;
    delete this->font;
}