#include "Player.hpp"

void RhA::CPlayer::create(sf::Vector2f position, float maxSpeed, float rotationSpeed, sf::Texture& textureBody, sf::Texture& textureTurret){
    body.init(position, maxSpeed, rotationSpeed, textureBody);

    turret.init(position, sf::seconds(1), textureTurret);
}

void RhA::CPlayer::update(sf::Vector2f mousePosition, float dt){
    body.update(dt);

    turret.shoot(sf::Mouse::Left);
    turret.update((body.getSprite()).getPosition(), mousePosition, dt);
}

void RhA::CPlayer::draw(sf::RenderTarget& target, sf::RenderStates stated) const{
    target.draw(body);

    target.draw(turret);
}
