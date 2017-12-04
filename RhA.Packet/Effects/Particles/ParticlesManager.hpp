#ifndef PARTICLESMANAGER_HPP_INCLUDED
#define PARTICLESMANAGER_HPP_INCLUDED

#include "System/LibrariesIncluding.hpp"
#include "System/Helpful.hpp"

namespace RhA{
    class CParticle{
        public:
         sf::Sprite sprite;

         bool hiding = false;
         int colorAlpha = 0;
         float sRotate = 0.1;


         CParticle(sf::Texture& texture, sf::Vector2f position){
            sprite.setTexture(texture);

            sprite.setPosition(position);

            float random = rand()%4 -2;
            sRotate = random/20;
         }

         void changeAlpha(float speed){
            if(hiding == false)
                colorAlpha += speed;

            else colorAlpha -= speed;
         }

        private:

    };
}

#endif // PARTICLESMANAGER_HPP_INCLUDED
