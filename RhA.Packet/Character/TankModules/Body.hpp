#ifndef BODY_HPP_INCLUDED
#define BODY_HPP_INCLUDED

#include "System/LibrariesIncluding.hpp"
#include "System/LoaderTextures.hpp"

namespace RhA{
    class CBody: public sf::Drawable{
        public:
         void init(sf::Vector2f position, float maxSpeed, float rotationSpeed, sf::Texture& texture);
         void update(float dt);

         sf::Sprite getSprite(); //get copied object

         float maxSpeed = 0;
         float currentSpeed = 0;
         float rotationSpeed = 0;

        private:
         virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

         sf::Sprite sprite;
         sf::Sprite shadow;
    };
}


#endif // BODY_HPP_INCLUDED
