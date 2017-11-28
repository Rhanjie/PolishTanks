#ifndef PARTICLEEMITTER_HPP_INCLUDED
#define PARTICLEEMITTER_HPP_INCLUDED

#include "System/LibrariesIncluding.hpp"
#include "System/Helpful.hpp"
#include "ParticlesManager.hpp"

namespace RhA{
    class CParticleEmitter{
        public:
         virtual void update()=0;
         virtual void draw(sf::RenderTarget& target)=0;

        protected:
         sf::Texture texture;
    };

    class CFogEmitter: CParticleEmitter{
        public:
         CFogEmitter(sf::Texture& texture){
            this->texture = texture;

            //...
         }

         void addParticle(sf::Vector2f position){
            vParticles.push_back(RhA::CParticle(texture, position));
         }

         void addParticles(int amount, sf::Vector2f position){
            for(int i = 0; i < amount; ++i)
                this->addParticle(position);
         }

         virtual void update(){
            //...
         }

         virtual void draw(sf::RenderTarget& target){
            for(int i = 0; i < vParticles.size(); ++i){
                target.draw(vParticles[i].sprite);
            }
         }

        private:
         std::vector<RhA::CParticle>vParticles;
    };
}

#endif // PARTICLEEMITTER_HPP_INCLUDED
