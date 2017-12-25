#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include "System/LibrariesIncluding.hpp"
#include "System/LoaderTextures.hpp"
#include "TankModules/Turret.hpp"
#include "Status.hpp"

namespace RhA{
    class CPlayer : public CStats{
        public:
         void create(sf::Vector2f position, float maxSpeed, float velRotation, sf::Texture& textureBody, sf::Texture& textureTurret);

         void update(sf::Vector2f mousePosition);
         void render(sf::RenderTarget& target);

         inline sf::Vector2f getPosition(){return spriteBody.getPosition();}

        private:
         void serveMoving(); //TODO: Delete
         virtual void draw(sf::RenderTarget& target, sf::RenderStates stated) const;

         sf::Sprite spriteBody;
         sf::Sprite shadowBody;
         RhA::CTurret turret;

         float maxSpeed, currentSpeed = 0;
         float velRotation;
    };
}

#endif // PLAYER_HPP_INCLUDED
