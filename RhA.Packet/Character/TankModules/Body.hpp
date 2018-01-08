#ifndef BODY_HPP_INCLUDED
#define BODY_HPP_INCLUDED

#include "System/LibrariesIncluding.hpp"
#include "System/LoaderTextures.hpp"

namespace RhA{
    class CBody: public sf::Drawable{
        public:
         void init(sf::Vector2f position, float maxSpeed, float rotationSpeed, sf::Texture& texture);
         void update(float dt);

         sf::Sprite getSprite(); //only copied object

        private:
         virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

         sf::Sprite sprite;
         sf::Sprite shadow;

         float maxSpeed, currentSpeed = 0;
         float rotationSpeed;
    };
}


#endif // BODY_HPP_INCLUDED
