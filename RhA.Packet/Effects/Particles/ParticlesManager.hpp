#ifndef PARTICLESMANAGER_HPP_INCLUDED
#define PARTICLESMANAGER_HPP_INCLUDED

#include "System/LibrariesIncluding.hpp"
#include "System/Helpful.hpp"

namespace RhA{
    class CParticle{
        public:
         sf::Sprite sprite;

         CParticle(sf::Texture& texture, sf::Vector2f position){
            sprite.setTexture(texture);

            sprite.setPosition(position);
         }

        private:

    };
}

#endif // PARTICLESMANAGER_HPP_INCLUDED
