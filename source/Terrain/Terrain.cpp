#include "Terrain.hpp"

void RhA::CTerrain::generate(sf::RenderTarget& target, sf::Vector2i size, int textureSize){
    this->textureSize = textureSize;

    arrayID.resize(size.y);
    vTiles.resize(arrayID.size());

    for(int y = 0; y < arrayID.size(); ++y){
        arrayID[y].resize(size.x);

        vTiles[y].resize(arrayID.size());
    }

     sf::Sprite helper;
     std::string path = "";
    for(int y = 0; y < arrayID.size(); ++y){
        for(int x = 0; x < arrayID[y].size(); ++x){
            arrayID[y][x] = "terrain/grass" + RhA::toString((rand()%7)+1);

            helper.setTexture(RhA::CLoaderResources::get().getTexture(arrayID[y][x]));
            helper.setPosition(x*textureSize, y*textureSize);

            vTiles[y][x] = helper;


            float random = rand()%100;
            //if(y < arrayID.size()/2 && x < arrayID[y].size()/2){
                path = "terrain/objects/tree" + RhA::toString((rand()%3)+1);

                if(random < 40){
                    manager.addObject(new RhA::CTreeObject(RhA::CLoaderResources::get().getTexture(path), 2.0f, true));
                    manager.getLastObject()->setPosition(sf::Vector2f(x*170 + rand()%60-30, y*170 + rand()%50-20));
                }
            //}
        }
    }
}

void RhA::CTerrain::update(sf::RenderTarget& target, float dt){
    visibleArea.left   = (target.getView().getCenter().x - (target.getView().getSize()).x / 2) / textureSize;
    visibleArea.top    = (target.getView().getCenter().y - (target.getView().getSize()).y / 2) / textureSize;
    visibleArea.width  = (target.getView().getSize()).x / textureSize;
    visibleArea.height = (target.getView().getSize()).y / textureSize;

    if(visibleArea.left <= 0) visibleArea.left = 0;
    if(visibleArea.top <= 0) visibleArea.top = 0;

    if(visibleArea.left > arrayID[0].size() - visibleArea.width)
        visibleArea.left = arrayID[0].size() - visibleArea.width;

    if(visibleArea.top > arrayID.size() - visibleArea.height)
        visibleArea.top = arrayID.size() - visibleArea.height;

    manager.update(visibleArea, dt);
}
void RhA::CTerrain::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    for(int y = visibleArea.top; y < visibleArea.top + visibleArea.height; ++y){
        for(int x = visibleArea.left; x < visibleArea.left + visibleArea.width; ++x){
            target.draw(vTiles[y][x]);
        }
    }
}

void RhA::CTerrain::drawObjects(sf::RenderTarget& target){
    manager.draw(target);
}

void RhA::CTerrain::checkCollision(RhA::CPlayer &person){
    manager.checkCollision(person);
}


