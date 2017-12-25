#include "Player.hpp"
#define M_PI 3.14159265359

void RhA::CPlayer::serveMoving(){
    float velX =  sin((spriteBody.getRotation() * M_PI) / 180.0f);
    float velY = -cos((spriteBody.getRotation() * M_PI) / 180.0f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        currentSpeed += maxSpeed/40;

        if(currentSpeed > maxSpeed)
           currentSpeed = maxSpeed;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        currentSpeed -= maxSpeed/40;

        if(currentSpeed < -maxSpeed/2)
           currentSpeed = -maxSpeed/2;
    }

    else{
        if(currentSpeed > 0) currentSpeed -= maxSpeed/20;
        if(currentSpeed < 0) currentSpeed += maxSpeed/20;

        if(currentSpeed < maxSpeed/20 && currentSpeed > -maxSpeed/20)
            currentSpeed = 0;
    }

    if(currentSpeed != 0)
        spriteBody.move(velX * currentSpeed, velY * currentSpeed);


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        spriteBody.rotate(-velRotation);

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        spriteBody.rotate(velRotation);


    shadowBody.setPosition(sf::Vector2f(spriteBody.getPosition().x + 8, spriteBody.getPosition().y + 8));
    shadowBody.setRotation(spriteBody.getRotation());
}
