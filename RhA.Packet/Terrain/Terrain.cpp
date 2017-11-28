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
    for(int y = 0; y < arrayID.size(); ++y){
        for(int x = 0; x < arrayID[y].size(); ++x){
            helper.setTexture(RhA::CLoaderResources::get().getTexture(arrayID[y][x]));
            helper.setPosition(x*128, y*128);

            vTiles.push_back(helper);
        }
    }
}

void RhA::CTerrain::update(){
    manager.update();
}
void RhA::CTerrain::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    for(int i = 0; i < vTiles.size(); ++i)
     target.draw(vTiles[i]);
}
void RhA::CTerrain::drawObjects(sf::RenderTarget& target){
    target.draw(manager);
}
