#ifndef PING_PONG_ENTITY_H
#define PING_PONG_ENTITY_H

#include <SFML/Graphics.hpp>
#include <string>


class Entity : public sf::Sprite
{
public:
    Entity()
    {
        this->texture = new sf::Texture();
    }

    void Load(std::string filename)
    {
        this->texture->loadFromFile(filename);
        this->setTexture(*this->texture);
    }

    virtual void Update()
    {
        this->move(this->velocity);
    }

    bool CheckCollision(Entity *entity)
    {
        if (this->getGlobalBounds().intersects(entity->getGlobalBounds())){

        }
    }

    ~Entity()
    {
        delete this->texture;
    }
    sf::Vector2f velocity;
private:
    sf::Texture* texture;

};
#endif //PING_PONG_ENTITY_H
