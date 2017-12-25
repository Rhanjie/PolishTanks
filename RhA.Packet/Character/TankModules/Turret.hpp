#ifndef TURRET_HPP_INCLUDED
#define TURRET_HPP_INCLUDED

#include "System/LibrariesIncluding.hpp"
#include "System/LoaderTextures.hpp"

namespace RhA{
    class CTurret: public sf::Drawable{ //and gun
        public:
         void init(sf::Vector2f position, sf::Texture& texture);
         void update(sf::Vector2f position, sf::Vector2f mousePosition);
         void shoot(sf::Mouse::Button button);

         sf::FloatRect getCollisionBox();

        private:
         virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


         sf::Sprite sprite;
         sf::Sprite shadow;
         sf::Vector2f direction;

         sf::RectangleShape bullet; ///TODO: Change bullet system
         const float bulletSpeed = 10.0f;
         bool isShooting = false;
         int timer = 0;
    };
}

#endif // TURRET_HPP_INCLUDED
