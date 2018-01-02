#ifndef TERRAIN_HPP_INCLUDED
#define TERRAIN_HPP_INCLUDED
#include "System/LibrariesIncluding.hpp"
#include "System/LoaderTextures.hpp"
#include "System/Helpful.hpp"
#include "ObjectManager.hpp"

namespace RhA{
    class CTerrain: public sf::Drawable{
        public:
         void generate(sf::RenderTarget& target, sf::Vector2i size, int textureSize);
         void checkCollision(sf::FloatRect collisionBox);

         void update(sf::RenderTarget& target, float dt);
         void drawObjects(sf::RenderTarget& target);

         inline sf::Vector2f getSize(){return sf::Vector2f(arrayID.size(), arrayID[0].size());}

        private:
         virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; //tiles

         std::vector<std::vector<std::string>>arrayID;
         std::vector<std::vector<sf::Sprite>>vTiles;

         RhA::CObjectManager manager;
         sf::FloatRect visibleArea;
         int textureSize;
    };
}

#endif // TERRAIN_HPP_INCLUDED
