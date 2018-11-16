#ifndef FOGEMITTER_HPP_INCLUDED
#define FOGEMITTER_HPP_INCLUDED

#include "../../System/LibrariesIncluding.hpp"
#include "../../System/Helpful.hpp"
#include "ParticlesManager.hpp"
#include "ParticleEmitter.hpp"

namespace RhA{
    class CFogEmitter: public CParticleEmitter{
        public:
         CFogEmitter(sf::Texture& texture, int pAmount);
         ~CFogEmitter();

         void addParticle(sf::Vector2f position, float scale);
         void addParticles(int amount, sf::Vector2f position, float scale);

         virtual void update(float dt);
         virtual void draw(sf::RenderTarget& target);

        private:
         //...
    };
}

#endif // FOGEMITTER_HPP_INCLUDED
