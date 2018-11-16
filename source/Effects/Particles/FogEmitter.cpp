#include "FogEmitter.hpp"

RhA::CFogEmitter::CFogEmitter(sf::Texture& texture, int pAmount){
    this->texture = texture;

    this->pAmount = pAmount;
}

RhA::CFogEmitter::~CFogEmitter(){
    vParticles.clear();
}

void RhA::CFogEmitter::addParticle(sf::Vector2f position, float scale){ //texture, position, scale, rotate:
    vParticles.push_back(RhA::CParticle(texture, position, (float)(rand()%10 + 15)/10 * scale, (float)(rand()%4 - 2)/20)); //(float)(rand()%10 + 15)/10
}

void RhA::CFogEmitter::addParticles(int amount, sf::Vector2f position, float scale){
    for(int i = 0; i < amount; ++i)
        addParticle(position, scale);
}

void RhA::CFogEmitter::update(float dt){
    for(int i = 0; i < vParticles.size(); ++i){
        (vParticles[i].sprite).rotate(vParticles[i].rotateSpeed * (dt * 100));
        (vParticles[i].sprite).setColor(sf::Color(255, 255, 255, vParticles[i].colorAlpha));
         vParticles[i].changeAlpha(dt);

        if(vParticles[i].colorAlpha >= 80){ //200
            vParticles[i].hiding = true;

            continue;
        }

        if(vParticles[i].colorAlpha < 0){
            vParticles.erase(vParticles.begin() + i);

            i--;
        }
    }
}

void RhA::CFogEmitter::draw(sf::RenderTarget& target){
    for(int i = 0; i < vParticles.size(); ++i)
        target.draw(vParticles[i].sprite);
}
