#ifndef OBJECTMANAGER_HPP_INCLUDED
#define OBJECTMANAGER_HPP_INCLUDED

#include "System/LibrariesIncluding.hpp"
#include "System/LoaderTextures.hpp"
#include "System/Helpful.hpp"

#include "Terrain/Object.hpp"

namespace RhA{
    class CObjectManager: public sf::Drawable{
        public:
         void addObject(RhA::CObject* object);
         void update();

         inline RhA::CObject* getLastObject(){
            return vObjects[vObjects.size()-1];
         }
        private:
         virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

         std::vector<RhA::CObject*>vObjects;
    };
}

#endif // OBJECTMANAGER_HPP_INCLUDED
