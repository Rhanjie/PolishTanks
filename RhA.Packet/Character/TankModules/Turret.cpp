#include "Turret.hpp"
#define M_PI 3.14159265359

void RhA::CTurret::init(sf::Vector2f position, sf::Texture& texture){
    sprite.setTexture(texture);
    sprite.setPosition(position.x, position.y);
    sprite.setOrigin(sprite.getTexture()->getSize().x/2, sprite.getTexture()->getSize().y/2);
    sprite.setScale(0.5, 0.5);

    shadow = sprite;
    shadow.setColor(sf::Color(0, 0, 0, 125));


    bullet.setSize(sf::Vector2f(100, 4));
    bullet.setOrigin(-sprite.getGlobalBounds().width/2, 2); //-Gun length, gun width

    bullet.setTexture(&RhA::CLoaderResources::get().getTexture("bullet1"));
}

void RhA::CTurret::shoot(sf::Mouse::Button button){
    float velX =  sin(((bullet.getRotation() + 90) * M_PI) / 180.0f);
    float velY = -cos(((bullet.getRotation() + 90) * M_PI) / 180.0f);

    if(sf::Mouse::isButtonPressed(button)){
        if(!isShooting){
            isShooting = true;

            bullet.setPosition(sprite.getPosition());
            bullet.setRotation(sprite.getRotation());

            bullet.setFillColor(sf::Color(255, 255, 255, 255));

            timer = 0;
        }
    }

    if(isShooting){
        timer++;

        bullet.setSize(sf::Vector2f(bullet.getSize().x + timer, 4));
        bullet.move(velX * bulletSpeed, velY * bulletSpeed);

        if(timer >= 30){
            bullet.setFillColor(sf::Color(255, 255, 255, 0));
            bullet.setSize(sf::Vector2f(50, 4));

            isShooting = false;
            timer = 0;
        }
    }
}

void RhA::CTurret::update(sf::Vector2f position, sf::Vector2f mousePosition){
    direction = mousePosition - sprite.getPosition();

    sprite.setRotation(atan2(direction.y, direction.x) * 180 / M_PI);
    shadow.setRotation(sprite.getRotation());

    sprite.setPosition(position.x, position.y);
    shadow.setPosition(position.x + 3, position.y + 3);
}

void RhA::CTurret::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(bullet);

    target.draw(shadow);
    target.draw(sprite);
}

sf::FloatRect RhA::CTurret::getCollisionBox(){
    return bullet.getGlobalBounds();
}

