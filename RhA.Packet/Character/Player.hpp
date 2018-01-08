#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include "System/LibrariesIncluding.hpp"
#include "System/LoaderTextures.hpp"
#include "TankModules/Turret.hpp"
#include "TankModules/Body.hpp"
#include "Status.hpp"

namespace RhA{
    class CPerson: public CStats{
        public:
         virtual inline sf::Vector2f getPosition() = 0;
         virtual inline sf::FloatRect getCollisionBox() = 0;
    };

    class CPlayer: public CPerson{
        public:
         void create(sf::Vector2f position, float maxSpeed, float rotationSpeed, sf::Texture& textureBody, sf::Texture& textureTurret);

         void update(sf::Vector2f mousePosition, float dt);
         void render(sf::RenderTarget& target);

         virtual inline sf::Vector2f getPosition(){return (body.getSprite()).getPosition();}
         virtual inline sf::FloatRect getCollisionBox(){return (body.getSprite()).getGlobalBounds();}

        private:
         virtual void draw(sf::RenderTarget& target, sf::RenderStates stated) const;

         RhA::CBody body;
         RhA::CTurret turret;

         float maxSpeed, currentSpeed = 0;
         float velRotation;
    };
}

#endif // PLAYER_HPP_INCLUDED
