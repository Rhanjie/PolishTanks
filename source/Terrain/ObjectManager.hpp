#ifndef OBJECTMANAGER_HPP_INCLUDED
#define OBJECTMANAGER_HPP_INCLUDED

#include "../System/LibrariesIncluding.hpp"
#include "../System/LoaderTextures.hpp"
#include "../System/Helpful.hpp"
#include "../Character/Player.hpp"

#include "../Terrain/Object.hpp"

namespace RhA{
    class CObjectManager{
        public:
         void addObject(RhA::CObject* object);
         void update(sf::FloatRect visibleArea, float dt);
         void draw(sf::RenderTarget& target);

         void checkCollision(RhA::CPlayer &person);

         inline RhA::CObject* getLastObject(){
            return vObjects[vObjects.size()-1];
         }

        private:
         std::vector<RhA::CObject*>vObjects;
         sf::FloatRect visibleArea;

         sf::Color color;
         float speed = 3;
    };
}

#endif // OBJECTMANAGER_HPP_INCLUDED
