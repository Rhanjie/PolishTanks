#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include "System/LibrariesIncluding.hpp"
#include "System/LoaderTextures.hpp"
#include "Status.hpp"

namespace RhA{
    class CPlayer : public CStats{
        public:
         void create(sf::Vector2f position, float velMoving, float velRotation, sf::Texture& textureBody, sf::Texture& textureTurret);

         void update(sf::Vector2f mousePosition);
         void render(sf::RenderTarget& target);

         inline sf::Vector2f getPosition(){return spriteBody.getPosition();}

        private:
         void serveMoving();
         void serveShooting();

         virtual void draw(sf::RenderTarget& target, sf::RenderStates stated) const;


         sf::Sprite spriteBody;
         sf::Sprite spriteTurret;

         sf::Sprite shadowBody;
         sf::Sprite shadowTurret;
         sf::RectangleShape bullet;

         sf::Vector2f direction;
         float velMoving;
         float velRotation;

         int timer = 0;
    };
}

#endif // PLAYER_HPP_INCLUDED
