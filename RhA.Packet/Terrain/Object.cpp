#include "Object.hpp"

void RhA::CObject::setPosition(sf::Vector2f position){
    sprite.setPosition(position);

    shadow.setPosition(position.x+10, position.y+10);
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
    sprite.setOrigin(sf::Vector2f(sprite.getTexture()->getSize().x/2, sprite.getTexture()->getSize().y/2));

    float random = ((rand()%6)+7);
    sprite.setScale(random/10, random/10);

    float a = rand()%70;
    float b = rand()%70;
    float c = rand()%70;
    sprite.setColor(sf::Color(255-a, 255-b, 255-c, 255));

    shadow = sprite;
    shadow.setColor(sf::Color(0, 0, 0, 125));
}

void RhA::CTreeObject::update(){
    this->rotate(0.1f);

    //...
}
