#ifndef FOGEMITTER_HPP_INCLUDED
#define FOGEMITTER_HPP_INCLUDED

#include "System/LibrariesIncluding.hpp"
#include "System/Helpful.hpp"
#include "ParticlesManager.hpp"
#include "ParticleEmitter.hpp"

namespace RhA{
    class CFogEmitter: public CParticleEmitter{
        public:
         CFogEmitter(sf::Texture& texture, int pAmount);

         void addParticle(sf::Vector2f position);
         void addParticles(int amount, sf::Vector2f position);

         virtual void update();
         virtual void draw(sf::RenderTarget& target);

        private:
         //...
    };
}

#endif // FOGEMITTER_HPP_INCLUDED
