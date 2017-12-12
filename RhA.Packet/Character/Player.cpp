#include "Player.hpp"

 #define M_PI 3.14159265359

void RhA::CPlayer::create(sf::Vector2f position, float velMoving, float velRotation, sf::Texture& textureBody, sf::Texture& textureTurret){
    this->velMoving = velMoving;
    this->velRotation = velRotation; //TODO

    spriteBody.setTexture(textureBody);
    spriteBody.setPosition(position);
    spriteBody.setOrigin(spriteBody.getTexture()->getSize().x/2, spriteBody.getTexture()->getSize().y/2);
    spriteBody.setScale(0.5, 0.5);
    spriteBody.setRotation(150);

    spriteTurret.setTexture(textureTurret);
    spriteTurret.setPosition(position.x, position.y);
    spriteTurret.setOrigin(spriteTurret.getTexture()->getSize().x/2, spriteTurret.getTexture()->getSize().y/2);
    spriteTurret.setScale(0.5, 0.5);


    shadowBody = spriteBody;
    shadowBody.setColor(sf::Color(0, 0, 0, 125));

    shadowTurret = spriteTurret;
    shadowTurret.setColor(sf::Color(0, 0, 0, 125));

    bullet.setSize(sf::Vector2f(-1000, 3)); //TODO: Change bullet system
}

void RhA::CPlayer::update(sf::Vector2f mousePosition){
    direction = mousePosition - spriteTurret.getPosition();
    bullet.setFillColor(sf::Color(255, 255, 255, 0));

    this->serveMoving();
    this->serveShooting();
}

void RhA::CPlayer::draw(sf::RenderTarget& target, sf::RenderStates stated) const{
    target.draw(shadowBody);
    target.draw(spriteBody);

     target.draw(bullet);

    target.draw(shadowTurret);
    target.draw(spriteTurret);
}
