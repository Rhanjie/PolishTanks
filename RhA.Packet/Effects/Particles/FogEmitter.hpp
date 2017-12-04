#ifndef FOGEMITTER_HPP_INCLUDED
#define FOGEMITTER_HPP_INCLUDED

#include "System/LibrariesIncluding.hpp"
#include "System/Helpful.hpp"
#include "ParticlesManager.hpp"
#include "ParticleEmitter.hpp"

namespace RhA{
    class CFogEmitter: public CParticleEmitter{
        public:
         CFogEmitter(sf::Texture& texture, int pAmount){
            this->texture = texture;

            this->pAmount = pAmount;
         }

         void addParticle(sf::Vector2f position){ //move, liveTime
            vParticles.push_back(RhA::CParticle(texture, position));
         }

         void addParticles(int amount, sf::Vector2f position){
            for(int i = 0; i < amount; ++i)
                addParticle(position);
         }

         virtual void update(){
            for(int i = 0; i < vParticles.size(); ++i){
                vParticles[i].sprite.setColor(sf::Color(255, 255, 255, vParticles[i].colorAlpha));
                vParticles[i].changeAlpha(1.0F);

                if(vParticles[i].colorAlpha >= 200){
                    vParticles[i].hiding = true;

                    continue;
                }

                if(vParticles[i].colorAlpha < 0){
                    vParticles.erase(vParticles.begin() + i);

                    i--;
                }

                vParticles[i].sprite.rotate(vParticles[i].sRotate);
            }
         }

         virtual void draw(sf::RenderTarget& target){
            for(int i = 0; i < vParticles.size(); ++i){
                target.draw(vParticles[i].sprite);
            }
         }

        private:
         //...
    };
}

#endif // FOGEMITTER_HPP_INCLUDED
