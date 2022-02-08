#include "Entity.h"

namespace Entities {

Entity::Entity() {
}

Entity::Entity(const std::string& newTexturePath,
    const sf::Vector2f& newPosition, const float newRotation) {

    // Set sprite and its transform
    setSprite(newTexturePath);
    sprite.setPosition(newPosition);
    sprite.setRotation(newRotation);
    sprite.setOrigin(sprite.getLocalBounds().width / 2,
        sprite.getLocalBounds().height / 2);
}

Entity::~Entity() {
}

void Entity::update(sf::RenderWindow* window) {
    // Move sprite
    sprite.move(
        velocity * cos(sprite.getRotation() * 3.14 / 180),
        velocity * sin(sprite.getRotation() * 3.14 / 180)
    );

    // Check if object is out of level bounds
    sf::Vector2f position = sprite.getPosition();
    //std::cout << "X: " << (position.x) << " | Y: " << (position.y) << "\n";

    if (position.x < 0) position.x = window->getSize().x;
    if (position.x > window->getSize().x) position.x = 0;
    if (position.y < 0) position.y = window->getSize().y;
    if (position.y > window->getSize().y) position.y = 0;

    sprite.setPosition(position);
}

void Entity::setSprite(const std::string path) {
    if (!texture.loadFromFile(path))
        return;

    sprite = sf::Sprite(texture);
}

sf::Sprite& Entity::getSprite() {
    return sprite;
}

}  // namespace Entities
