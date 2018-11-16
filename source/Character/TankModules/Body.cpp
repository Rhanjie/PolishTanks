#include "Body.hpp"
#define M_PI 3.14159265359

void RhA::CBody::init(sf::Vector2f position, float maxSpeed, float rotationSpeed, sf::Texture& texture){
    this->maxSpeed = maxSpeed;
    this->rotationSpeed = rotationSpeed; //TODO

    sprite.setTexture(texture);
    sprite.setPosition(position);
    sprite.setOrigin(sprite.getTexture()->getSize().x/2, sprite.getTexture()->getSize().y/2);
    sprite.setScale(0.5, 0.5);
    sprite.setRotation(150);

    shadow = sprite;
    shadow.setColor(sf::Color(0, 0, 0, 125));
}


void RhA::CBody::update(float dt){
    float velX =  sin((sprite.getRotation() * M_PI) / 180.0f);
    float velY = -cos((sprite.getRotation() * M_PI) / 180.0f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        currentSpeed += maxSpeed/40 * (dt * 100);

        if(currentSpeed > maxSpeed)
           currentSpeed = maxSpeed;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        currentSpeed -= maxSpeed/40 * (dt * 100);

        if(currentSpeed < -maxSpeed/2)
           currentSpeed = -maxSpeed/2;
    }

    else{
        if(currentSpeed > 0) currentSpeed -= maxSpeed/20 * (dt * 100);
        if(currentSpeed < 0) currentSpeed += maxSpeed/20 * (dt * 100);

        if(currentSpeed < maxSpeed/20 * (dt * 100) && currentSpeed > -maxSpeed/20 * (dt * 100))
            currentSpeed = 0;
    }

    if(currentSpeed != 0)
        sprite.move(velX * currentSpeed * dt, velY * currentSpeed * dt);


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        sprite.rotate(-rotationSpeed * dt);

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        sprite.rotate(rotationSpeed * dt);


    shadow.setPosition(sf::Vector2f(sprite.getPosition().x + 8, sprite.getPosition().y + 8));
    shadow.setRotation(sprite.getRotation());
}

void RhA::CBody::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(shadow);

    target.draw(sprite);
}

sf::Sprite RhA::CBody::getSprite(){
    return sprite;
}
