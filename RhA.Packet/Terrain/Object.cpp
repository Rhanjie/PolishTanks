#include "Object.hpp"

void RhA::CObject::setPosition(sf::Vector2f position, int shadowDistance){
    sprite.setPosition(position);

    shadow.setPosition(position.x+shadowDistance, position.y+shadowDistance);
}
void RhA::CObject::rotate(float angle){
    sprite.rotate(angle);

    shadow.rotate(angle);
}
void RhA::CObject::draw(sf::RenderTarget& target, bool main) const{
    switch(main){
        case true:  target.draw(sprite); break;
        case false: target.draw(shadow); break;
    }
}

RhA::CTreeObject::CTreeObject(sf::Texture& texture, float rSpeed, bool isCollision){
    sprite.setTexture(texture);
    sprite.setOrigin(sf::Vector2f(sprite.getTexture()->getSize().x/2-50, sprite.getTexture()->getSize().y/2-30));

    float random = ((rand()%6)+7);
    sprite.setScale(random/10, random/10);
    sprite.setRotation(rand()%360);

    float r = rand()%80;
    float g = rand()%80;
    float b = rand()%80;
    sprite.setColor(sf::Color(255-r, 255-g, 255-b, 255));

    shadow = sprite;
    shadow.setColor(sf::Color(0, 0, 0, 125));
}

void RhA::CTreeObject::update(){
    wind  += 0.015 + float(rand()%10)/10000.0f;
    angle += 0.0007 * std::cos(wind); //0.001

    this->rotate(angle);
}
