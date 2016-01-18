#include "SpriteAsset.hpp"

SpriteAsset::SpriteAsset(string _name, Texture _texture) {
    name = _name;
    sprite.setTexture(_texture);
}

Sprite SpriteAsset::getSprite() {
    // Check if Sprite exists
    if (sprite.getTexture()) {
        return sprite;
    } else {
        // Throw AssetException
        throw AssetException("Cannot get Sprite");
    }
}

void SpriteAsset::setPosition(float x, float y) {
    // Check if Sprite exists
    if (sprite.getTexture()) {
        sprite.setPosition(x, y);
    } else {
        // Throw AssetException
        throw AssetException("Cannot set Sprite's position");
    }
}

void SpriteAsset::draw(RenderWindow *window) {
    // Check if Sprite exists
    if (sprite.getTexture()) {
        window->draw(sprite);
    } else {
        // Throw AssetException
        throw AssetException("Cannot draw Sprite");
    }
}
