#include "Entity.h"

namespace Entities {
    Entity::Entity() {
    }

    Entity::Entity(std::string newTexturePath, sf::Vector2f* newPosition, float newRotation) {
        setSprite(newTexturePath);
        sprite.setPosition(*newPosition);
        sprite.setRotation(360 - newRotation);
        sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    }

    Entity::~Entity() {
    }

    void Entity::update(sf::RenderWindow* window) {
    }

    void Entity::setSprite(std::string path) {
        if (!texture.loadFromFile(path))
            return;

        sprite = sf::Sprite(texture);
    }

    sf::Sprite& Entity::getSprite() {
        return sprite;
    }
}