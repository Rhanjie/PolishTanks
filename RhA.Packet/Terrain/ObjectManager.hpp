#ifndef OBJECTMANAGER_HPP_INCLUDED
#define OBJECTMANAGER_HPP_INCLUDED

#include "System/LibrariesIncluding.hpp"
#include "System/LoaderTextures.hpp"
#include "System/Helpful.hpp"

#include "Terrain/Object.hpp"

namespace RhA{
    class CObjectManager{
        public:
         void addObject(RhA::CObject* object);
         void update(sf::FloatRect visibleArea);
         void draw(sf::RenderTarget& target);

         void checkCollision(sf::FloatRect collisionBox);

         inline RhA::CObject* getLastObject(){
            return vObjects[vObjects.size()-1];
         }

        private:
         std::vector<RhA::CObject*>vObjects;
         sf::FloatRect visibleArea;
    };
}

#endif // OBJECTMANAGER_HPP_INCLUDED
