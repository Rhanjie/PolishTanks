#include "Player.hpp"

void RhA::CPlayer::create(sf::Vector2f position, float maxSpeed, float velRotation, sf::Texture& textureBody, sf::Texture& textureTurret){
    this->maxSpeed = maxSpeed;
    this->velRotation = velRotation; //TODO

    spriteBody.setTexture(textureBody);
    spriteBody.setPosition(position);
    spriteBody.setOrigin(spriteBody.getTexture()->getSize().x/2, spriteBody.getTexture()->getSize().y/2);
    spriteBody.setScale(0.5, 0.5);
    spriteBody.setRotation(150);

    shadowBody = spriteBody;
    shadowBody.setColor(sf::Color(0, 0, 0, 125));

    turret.init(position, sf::seconds(1), textureTurret);
}

void RhA::CPlayer::update(sf::Vector2f mousePosition, float dt){
    this->serveMoving(dt);

    turret.shoot(sf::Mouse::Left);
    turret.update(spriteBody.getPosition(), mousePosition, dt);
}

void RhA::CPlayer::draw(sf::RenderTarget& target, sf::RenderStates stated) const{
    target.draw(shadowBody);
    target.draw(spriteBody);

    target.draw(turret);
}
