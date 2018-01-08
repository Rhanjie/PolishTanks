#ifndef OBJECT_HPP_INCLUDED
#define OBJECT_HPP_INCLUDED

#include "System/LibrariesIncluding.hpp"
#include "System/LoaderTextures.hpp"
#include "System/Helpful.hpp"

namespace RhA{
    class CObject{ // <- Abstract class
        public:
         void setPosition(sf::Vector2f position, int shadowDistance = 15);
         void rotate(float angle);

         virtual void update(float dt) = 0;
         void draw(sf::RenderTarget& target, bool main = true) const;

         virtual sf::FloatRect getCollisionBox() = 0;

         sf::Sprite sprite, shadow;
         sf::RectangleShape debug;

         bool isRemoving = false;

        protected:
         CObject(){};

         bool isCollision;
    };

    class CTreeObject: public CObject{
        public:
         CTreeObject(sf::Texture& texture, float rSpeed, bool isCollision);

         virtual void update(float dt);
         virtual sf::FloatRect getCollisionBox();

        private:
         sf::FloatRect collisionBox;

         float angle = 0, wind = 0.020 + float(rand()%10) / 10000.0f;
    };
}

#endif
