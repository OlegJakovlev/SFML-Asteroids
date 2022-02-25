#include "Healthbar.h"

Healthbar::Healthbar() {
    texture.loadFromFile("Sprites/Healthbar.png");
    sprite.setTexture(texture);
    sprite.setPosition(15, 10);
}

sf::Texture& Healthbar::getTexture() {
    return texture;
}

sf::Sprite& Healthbar::getSprite() {
    return sprite;
}
