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

        ///TODO: Rotating objects not supported
        if(vObjects[i]->sprite.getGlobalBounds().intersects(this->visibleArea)){
            vObjects[i]->update(dt);

            if(vObjects[i]->isRemoving){
                color = (vObjects[i]->sprite).getColor();
                vObjects[i]->cAlpha -= speed * (dt * 100);

                color.a = vObjects[i]->cAlpha;
                vObjects[i]->sprite.setColor(color);


                color = (vObjects[i]->shadow).getColor();
                vObjects[i]->cAlphaShadow -= speed * (dt * 100);

                if(vObjects[i]->cAlphaShadow < 0)
                    vObjects[i]->cAlphaShadow = 0;

                color.a = vObjects[i]->cAlphaShadow;
                vObjects[i]->shadow.setColor(color);

                if(vObjects[i]->cAlpha <= 0){
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

void RhA::CObjectManager::checkCollision(RhA::CPlayer &person){ //RhA::CPerson &person
    for(int i = 0; i < vObjects.size(); ++i){
        if(vObjects[i]->sprite.getGlobalBounds().intersects(visibleArea)){
            if(vObjects[i]->isRemoving == false){
                if(person.getCollisionBox().intersects(vObjects[i]->getCollisionBox())){
                    vObjects[i]->isRemoving = true;

                    //person.body.currentSpeed /= 3;
                    person.setStatus(HEALTH, -5);
                }
            }
        }
    }
}
