#ifndef TURRET_HPP_INCLUDED
#define TURRET_HPP_INCLUDED

#include "System/LibrariesIncluding.hpp"
#include "System/LoaderTextures.hpp"

namespace RhA{
    class CTurret: public sf::Drawable{
        public:
         void init(sf::Vector2f position, sf::Time reloadTime, sf::Texture& texture);
         void update(sf::Vector2f position, sf::Vector2f mousePosition, float dt);
         void shoot(sf::Mouse::Button button);

         sf::FloatRect getCollisionBox(unsigned int i);

        private:
         virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

         sf::Sprite sprite;
         sf::Sprite shadow;
         sf::Vector2f direction;

         sf::Clock clock;
         sf::Time reloadTime;
         std::vector<sf::RectangleShape>vBullets;

         const float bulletSpeed = 12.0f;
         bool isShooting = false;
    };
}

#endif // TURRET_HPP_INCLUDED
