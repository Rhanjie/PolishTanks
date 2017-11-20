#include "GameManager.hpp"

void RhA::CGameManager::bodyMenu(){
    gameplayType = GAME;

    ///... TODO
}

void RhA::CGameManager::bodyGameplay(){

/** DEBUG */
    sf::Texture body = RhA::CLoaderResources::get().getTexture("tankBody1");
    sf::Texture turret = RhA::CLoaderResources::get().getTexture("tankTurret1");

    RhA::CTerrain terrain;
    terrain.generate(sf::Vector2i(30, 30));

     sf::Vector2f spawnPosition = sf::Vector2f(terrain.getSize().x*128/2, terrain.getSize().y*128/2);
/** DEBUG */


     RhA::CPlayer player;
    player.create(spawnPosition, 3.0f, 1.0f, body, turret);
    player.setStatus(CStats::HEALTH, 50);

    while(gameplayType == GAME){
        if(constLoop.isGoodTime()){
            while(window.pollEvent(event)){
                if(event.type == sf::Event::Closed)
                 gameplayType = END;
            }

             window.setView(this->camera);
            sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
             window.setView(window.getDefaultView());


            player.update(mousePosition);
            camera.setCenter(player.getPosition());

            terrain.update();
        }


        window.clear();
        window.setView(this->camera);

         window.draw(terrain);
         window.draw(player);

         terrain.drawObjects(window);

        window.setView(window.getDefaultView());
        window.display();
    }
}
