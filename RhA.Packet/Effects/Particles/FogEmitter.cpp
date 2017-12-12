#include "FogEmitter.hpp"

RhA::CFogEmitter::CFogEmitter(sf::Texture& texture, int pAmount){
    this->texture = texture;

    this->pAmount = pAmount;
}

void RhA::CFogEmitter::addParticle(sf::Vector2f position){ //texture, position, scale, rotate:
    vParticles.push_back(RhA::CParticle(texture, position, (float)(rand()%10 + 15)/10, (float)(rand()%4 - 2)/20));
}

void RhA::CFogEmitter::addParticles(int amount, sf::Vector2f position){
    for(int i = 0; i < amount; ++i)
        addParticle(position);
}

void RhA::CFogEmitter::update(){
    for(int i = 0; i < vParticles.size(); ++i){
        vParticles[i].sprite.setColor(sf::Color(255, 255, 255, vParticles[i].colorAlpha));
        vParticles[i].changeAlpha();

        if(vParticles[i].colorAlpha >= 100){ //200
            vParticles[i].hiding = true;

            continue;
        }

        if(vParticles[i].colorAlpha < 0){
            vParticles.erase(vParticles.begin() + i);

            i--;
        }

        vParticles[i].sprite.rotate(vParticles[i].rotateSpeed);
    }
}

void RhA::CFogEmitter::draw(sf::RenderTarget& target){
    for(int i = 0; i < vParticles.size(); ++i){
        target.draw(vParticles[i].sprite);
    }
}
