#include "Player.hpp"

 #define M_PI 3.14159265359

void RhA::CPlayer::serveMoving(){
    float velX = sin((spriteBody.getRotation()*M_PI)/180.0f);
    float velY = -cos((spriteBody.getRotation()*M_PI)/180.0f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        spriteBody.move(velX * velMoving, velY * velMoving);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        spriteBody.move(-velX * (velMoving/2), -velY * (velMoving/2));
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        spriteBody.rotate(-velRotation);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        spriteBody.rotate(velRotation);
    }


    spriteTurret.setRotation(atan2(-direction.y, -direction.x)*180/M_PI);
    shadowTurret.setRotation(spriteTurret.getRotation());
    shadowBody.setRotation(spriteBody.getRotation());

    spriteTurret.setPosition(spriteBody.getPosition().x, spriteBody.getPosition().y);
    shadowTurret.setPosition(sf::Vector2f(spriteTurret.getPosition().x+5, spriteTurret.getPosition().y+5));
    shadowBody.setPosition(sf::Vector2f(spriteBody.getPosition().x+10, spriteBody.getPosition().y+10));
}

void RhA::CPlayer::serveShooting(){
    timer++;

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(timer >= 10){ //todo - turret state
            bullet.setPosition(spriteTurret.getPosition());
            bullet.setRotation(spriteTurret.getRotation());

            bullet.setFillColor(sf::Color(255, 255, 255, 255));

            timer = 0;
        }
    }
}
