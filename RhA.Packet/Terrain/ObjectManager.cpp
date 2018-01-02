#include "ObjectManager.hpp"

void RhA::CObjectManager::addObject(RhA::CObject* object){
    vObjects.push_back(object);
}

void RhA::CObjectManager::update(sf::FloatRect visibleArea, float dt){
    visibleArea.left *= 128;
    visibleArea.top *= 128;

    visibleArea.width *= 128;
    visibleArea.height *= 128;

    this->visibleArea = visibleArea;

    for(int i = 0; i < vObjects.size(); ++i){
        if(vObjects[i]->sprite.getGlobalBounds().intersects(this->visibleArea))
            vObjects[i]->update(dt);
    }
}

void RhA::CObjectManager::draw(sf::RenderTarget& target){
    for(int i = 0; i < vObjects.size(); ++i){
        if(vObjects[i]->sprite.getGlobalBounds().intersects(visibleArea)){
            vObjects[i]->draw(target, false);

            vObjects[i]->draw(target, true);
        }
    }
}

void RhA::CObjectManager::checkCollision(sf::FloatRect collisionBox){
    for(int i = 0; i < vObjects.size(); ++i){
        if(vObjects[i]->sprite.getGlobalBounds().intersects(visibleArea)){
            if(collisionBox.intersects(vObjects[i]->sprite.getGlobalBounds())){
                vObjects.erase(vObjects.begin()+i);
                //...

                i--;
            }
        }
    }
}
