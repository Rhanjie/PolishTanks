#ifndef PARTICLESMANAGER_HPP_INCLUDED
#define PARTICLESMANAGER_HPP_INCLUDED

#include "../../System/LibrariesIncluding.hpp"
#include "../../System/Helpful.hpp"

namespace RhA{
    class CParticle{
        public:
         sf::Sprite sprite;
         bool hiding = false;

         float rotateSpeed = 0;
         float colorSpeed = 0;
         float colorAlpha = 0;


         CParticle(sf::Texture& texture, sf::Vector2f position, float scale = 1, float rotateSpeed = 0){
            sprite.setTexture(texture);

            sprite.setPosition(position);
            sprite.setScale(scale, scale);

            this->rotateSpeed = rotateSpeed;
            this->colorSpeed = (float)((rand()%10)+5)/10;
         }

         void changeAlpha(float dt){
            if(hiding == false)
                colorAlpha += colorSpeed * (dt * 100);

            else colorAlpha -= colorSpeed * (dt * 100);
         }

        private:

    };
}

#endif // PARTICLESMANAGER_HPP_INCLUDED
