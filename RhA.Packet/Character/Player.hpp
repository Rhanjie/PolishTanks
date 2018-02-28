#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include "System/LibrariesIncluding.hpp"
#include "System/LoaderTextures.hpp"
#include "TankModules/Turret.hpp"
#include "TankModules/Body.hpp"
#include "Person.hpp"

namespace RhA{
    class CPlayer: public sf::Drawable, public CPerson{
        public:
         void create(sf::Vector2f position, float maxSpeed, float rotationSpeed, sf::Texture& textureBody, sf::Texture& textureTurret);

         void update(sf::Vector2f mousePosition, float dt);
         void render(sf::RenderTarget& target);

         virtual inline sf::Vector2f getPosition(){return (body.getSprite()).getPosition();}
         virtual inline sf::FloatRect getCollisionBox(){return (body.getSprite()).getGlobalBounds();}

         RhA::CBody body;
         RhA::CTurret turret;

        private:
         virtual void draw(sf::RenderTarget& target, sf::RenderStates stated) const;
    };
}

#endif // PLAYER_HPP_INCLUDED
