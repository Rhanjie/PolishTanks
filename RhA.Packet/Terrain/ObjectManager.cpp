#include "ObjectManager.hpp"

void RhA::CObjectManager::addObject(RhA::CObject* object){
    vObjects.push_back(object);
}

void RhA::CObjectManager::update(){
    for(int i = 0; i < vObjects.size(); ++i)
     vObjects[i]->update();
}

void RhA::CObjectManager::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    for(int i = 0; i < vObjects.size(); ++i)
     vObjects[i]->draw(target, false);

    for(int i = 0; i < vObjects.size(); ++i)
     vObjects[i]->draw(target, true);
}
