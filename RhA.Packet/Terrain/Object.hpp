#ifndef OBJECT_HPP_INCLUDED
#define OBJECT_HPP_INCLUDED

#include "System/LibrariesIncluding.hpp"
#include "System/LoaderTextures.hpp"
#include "System/Helpful.hpp"

namespace RhA{
    class CObject{ // <- Abstract class
        public:
         sf::Sprite sprite;
         sf::Sprite shadow;

         virtual void update()=0;
         void setPosition(sf::Vector2f position);
         void rotate(float angle);
         void draw(sf::RenderTarget& target, bool main = true) const;

        protected:
         CObject(){};

         bool isCollision;
    };

    class CTreeObject: public CObject{
        public:
         CTreeObject(sf::Texture& texture, float rSpeed, bool isCollision);

         virtual void update();

        private:
         //...

    };
}

#endif
