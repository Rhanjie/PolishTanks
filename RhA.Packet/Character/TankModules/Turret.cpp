#include "Turret.hpp"
#define M_PI 3.14159265359

void RhA::CTurret::init(sf::Vector2f position, sf::Time reloadTime, sf::Texture& texture){
    this->reloadTime = reloadTime;

    sprite.setTexture(texture);
    sprite.setPosition(position.x, position.y);
    sprite.setOrigin(sprite.getTexture()->getSize().x/2, sprite.getTexture()->getSize().y/2);
    sprite.setScale(0.5, 0.5);

    shadow = sprite;
    shadow.setColor(sf::Color(0, 0, 0, 125));
}

void RhA::CTurret::shoot(sf::Mouse::Button button){
    if(sf::Mouse::isButtonPressed(button)){
        if(!isShooting){
            isShooting = true;

            vBullets.push_back(sf::RectangleShape());
            vBullets[vBullets.size()-1].setPosition(sprite.getPosition());
            vBullets[vBullets.size()-1].setRotation(sprite.getRotation());
            vBullets[vBullets.size()-1].setSize(sf::Vector2f(100, 4));

            vBullets[vBullets.size()-1].setOrigin(-sprite.getGlobalBounds().width/2, 2); //-Gun length, gun width
            vBullets[vBullets.size()-1].setTexture(&RhA::CLoaderResources::get().getTexture("bullet1"));
            vBullets[vBullets.size()-1].setFillColor(sf::Color(255, 255, 255, 255));

            clock.restart();
        }
    }
}

void RhA::CTurret::update(sf::Vector2f position, sf::Vector2f mousePosition, float dt){
    float velX = 0, velY = 0; int todohelper = 500;

    direction = mousePosition - sprite.getPosition();

    sprite.setRotation(atan2(direction.y, direction.x) * 180 / M_PI);
    shadow.setRotation(sprite.getRotation());

    sprite.setPosition(position.x, position.y);
    shadow.setPosition(position.x + 3, position.y + 3);

    for(auto bullet = vBullets.begin(); bullet != vBullets.end();){
        velX =  sin(((bullet->getRotation() + 90) * M_PI) / 180.0f);
        velY = -cos(((bullet->getRotation() + 90) * M_PI) / 180.0f);

        bullet->setSize(sf::Vector2f((bullet->getSize()).x + 10 * (dt * 100) , 4));
        bullet->move(velX * bulletSpeed  * (dt * 100), velY * bulletSpeed  * (dt * 100));

        if(bullet->getPosition().x - sprite.getPosition().x <= -todohelper || bullet->getPosition().x - sprite.getPosition().x >= todohelper
            || bullet->getPosition().y - sprite.getPosition().y <= -todohelper || bullet->getPosition().y - sprite.getPosition().y >= todohelper)
            bullet = vBullets.erase(bullet);
        else ++bullet;
    }

    if(isShooting && clock.getElapsedTime() >= reloadTime){
        isShooting = false;

        clock.restart();
    }
}

void RhA::CTurret::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    for(auto &bullet: vBullets)
        target.draw(bullet);

    target.draw(shadow);
    target.draw(sprite);
}

sf::FloatRect RhA::CTurret::getCollisionBox(unsigned int i){
    if(i >= vBullets.size())
        return sf::FloatRect(0, 0, 0, 0);

    return vBullets[i].getGlobalBounds();
}

