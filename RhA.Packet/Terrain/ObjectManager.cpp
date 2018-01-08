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

    sf::Color color;
    for(int i = 0; i < vObjects.size(); ++i){
        if(vObjects[i]->sprite.getGlobalBounds().intersects(this->visibleArea)){ //TODO - Change method who support rotating objects
            vObjects[i]->update(dt);

            if(vObjects[i]->isRemoving){
                color = (vObjects[i]->sprite).getColor();
                color.a -= 0.1;
                vObjects[i]->sprite.setColor(color);

                color = (vObjects[i]->shadow).getColor();
                color.a -= 1 * dt;
                vObjects[i]->shadow.setColor(color);

                if((vObjects[i]->sprite).getColor().a <= 0){
                    vObjects.erase(vObjects.begin()+i);

                    i--;
                }
            }
        }
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

void RhA::CObjectManager::checkCollision(RhA::CPerson &person){ //RhA::CPerson &person
    for(int i = 0; i < vObjects.size(); ++i){
        if(vObjects[i]->sprite.getGlobalBounds().intersects(visibleArea)){
            if(vObjects[i]->isRemoving == false){
                if(person.getCollisionBox().intersects(vObjects[i]->getCollisionBox())){
                    vObjects[i]->isRemoving = true;

                    person.setStatus(RhA::CStats::HEALTH, -5);
                }
            }
        }
    }
}
