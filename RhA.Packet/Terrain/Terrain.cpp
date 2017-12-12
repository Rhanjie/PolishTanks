#include "Terrain.hpp"

void RhA::CTerrain::generate(sf::Vector2i size){
    arrayID.resize(size.y);
    for(int y = 0; y < arrayID.size(); ++y)
     arrayID[y].resize(size.x);

     std::string path = "";
    for(int y = 0; y < arrayID.size(); ++y){
        for(int x = 0; x < arrayID[y].size(); ++x){
            arrayID[y][x] = "terrain/grass" + RhA::toString((rand()%7)+1);

            float random = rand()%100;

            //if(y < arrayID.size()/2 && x < arrayID[y].size()/2){
                path = "terrain/objects/tree" + RhA::toString((rand()%3)+1); //TODO: Problem with performance

                if(random < 40){
                    manager.addObject(new RhA::CTreeObject(RhA::CLoaderResources::get().getTexture(path), 2.0f, true));
                    manager.getLastObject()->setPosition(sf::Vector2f(x*170, y*170));
                }
            //}
        }
    }

     sf::Sprite helper;
    vTiles.resize(arrayID.size());

    for(int y = 0; y < arrayID.size(); ++y){
        vTiles[y].resize(arrayID.size());

        for(int x = 0; x < arrayID[y].size(); ++x){
            helper.setTexture(RhA::CLoaderResources::get().getTexture(arrayID[y][x]));
            helper.setPosition(x*128, y*128);

            vTiles[y][x] = helper;
        }
    }
}

void RhA::CTerrain::update(sf::RenderTarget& target){
    manager.update();

    fixPosition  = sf::Vector2i((target.getView().getCenter().x - target.getSize().x/2)/128, (target.getView().getCenter().y - target.getSize().y/2)/128);
    fixPosition2 = sf::Vector2i((target.getView().getCenter().x + target.getSize().x/2+256)/128, (target.getView().getCenter().y + target.getSize().y/2+256)/128);

    if(fixPosition.x <= 0) fixPosition.x = 0;
    if(fixPosition.y <= 0) fixPosition.y = 0;

    if(fixPosition2.x >= arrayID[0].size()) fixPosition2.x = arrayID[0].size();
    if(fixPosition2.y >= arrayID.size()) fixPosition2.y = arrayID.size();
}
void RhA::CTerrain::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    for(int y = fixPosition.y; y < fixPosition2.y; ++y){
        for(int x = fixPosition.x; x < fixPosition2.x; ++x){
            target.draw(vTiles[y][x]);
        }
    }
}
void RhA::CTerrain::drawObjects(sf::RenderTarget& target){
    //... performance

    target.draw(manager);
}
