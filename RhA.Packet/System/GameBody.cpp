#include "GameManager.hpp"

void RhA::CGameManager::bodyMenu(){
    gameplayType = GAME;

    ///TODO: Add menu
}

void RhA::CGameManager::bodyGameplay(){
    RhA::CTerrain terrain;
     terrain.generate(sf::Vector2i(30, 30));

    //TODO: Add shop with tank modules
    sf::Texture body = RhA::CLoaderResources::get().getTexture("tankBody1");
    sf::Texture turret = RhA::CLoaderResources::get().getTexture("tankTurret1");

    sf::Vector2f spawnPosition = sf::Vector2f(terrain.getSize().x*128/2, terrain.getSize().y*128/2);

    RhA::CPlayer player;
     player.create(spawnPosition, 3.0f, 1.0f, body, turret);
     player.setStatus(CStats::HEALTH, 100);


    //TODO: Add weather system
    sf::RectangleShape fogEffect = sf::RectangleShape((sf::Vector2f)window.getSize());
    fogEffect.setFillColor(sf::Color(255, 255, 255, 75));

    sf::Vector2f fogSpawnPos = sf::Vector2f(0.0F, 0.0F);
    RhA::CFogEmitter* fogEmitter = new RhA::CFogEmitter(RhA::CLoaderResources::get().getTexture("fog1"), 60);


    sf::Vector2f mousePosition;
    while(gameplayType == GAME){
        if(constLoop.isGoodTime()){
            while(window.pollEvent(event)){
                if(event.type == sf::Event::Closed)
                 gameplayType = END;
            }

            window.setView(this->camera);

            mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            terrain.update(window);

            window.setView(window.getDefaultView());

            if(fogEmitter->checkAmount()){
                fogSpawnPos = sf::Vector2f(
                    player.getPosition().x + (rand()%2024) - 1024,
                    player.getPosition().y + (rand()%1536) - 768
                );

                fogEmitter->addParticle(fogSpawnPos);
            }

            player.update(mousePosition);
            camera.setCenter(player.getPosition());
            fogEmitter->update();


            { /**Draw all objects**/
                window.clear();
                window.setView(this->camera);

                 window.draw(terrain);
                 window.draw(player);

                 terrain.drawObjects(window);
                 fogEmitter->draw(window);

                window.setView(window.getDefaultView());

                window.draw(fogEffect);
                window.display();
            }
        }
    }

    delete fogEmitter;
}
