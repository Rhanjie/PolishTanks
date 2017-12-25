#include "GameManager.hpp"

void RhA::CGameManager::bodyMenu(){
    gameplayType = GAME;

    ///TODO: Add menu
}

void RhA::CGameManager::bodyGameplay(){
    const int TEXTURE_SIZE = 128;

    RhA::CTerrain terrain;
     terrain.generate(window, sf::Vector2i(200, 200), TEXTURE_SIZE);

    //TODO: Add shop with tank modules
    sf::Texture body = RhA::CLoaderResources::get().getTexture("tankBody1");
    sf::Texture turret = RhA::CLoaderResources::get().getTexture("tankTurret1");

    sf::Vector2f spawnPosition = sf::Vector2f(terrain.getSize().x*TEXTURE_SIZE/2, terrain.getSize().y*TEXTURE_SIZE/2);

    RhA::CPlayer player;
     player.create(spawnPosition, 3.0f, 1.0f, body, turret);
     player.setStatus(CStats::HEALTH, 100);


    //TODO: Add weather system
    sf::RectangleShape fogEffect = sf::RectangleShape((sf::Vector2f)window.getSize());
    fogEffect.setFillColor(sf::Color(255, 255, 255, 75));

    sf::Vector2f fogSpawnPos = sf::Vector2f(0.0F, 0.0F);
    RhA::CFogEmitter fogEmitter = RhA::CFogEmitter(RhA::CLoaderResources::get().getTexture("fog1"), 60); //TODO: Improve fog system when camera_scale > 1.0

    //camera.zoom(1.2);

    sf::Vector2f mousePosition;
    while(gameplayType == GAME){
        if(constLoop.isGoodTime()){
            while(window.pollEvent(event)){
                if(event.type == sf::Event::Closed)
                 gameplayType = END;
            }

            if(gameplayType == END) //DEBUG
                break;

            window.setView(camera);{
                mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                terrain.update(window);

                if(fogEmitter.checkAmount()){
                    fogSpawnPos = sf::Vector2f(
                        player.getPosition().x + (rand()%(int)((window.getView()).getSize().x * 2)) - (window.getView()).getSize().x,
                        player.getPosition().y + (rand()%(int)((window.getView()).getSize().x * 2)) - (window.getView()).getSize().y
                    );

                    fogEmitter.addParticle(fogSpawnPos);
                }


                //terrain.checkCollision(player.turret.getCollisionBox()); //Only debug code, will be fixed in next commit
            }
            window.setView(window.getDefaultView());

            player.update(mousePosition);
            camera.setCenter(player.getPosition());
            fogEmitter.update();


            { /**Draw all objects**/
                window.clear();
                window.setView(camera);

                 window.draw(terrain);
                 window.draw(player);

                 terrain.drawObjects(window);
                 fogEmitter.draw(window);

                window.setView(window.getDefaultView());

                window.draw(fogEffect);
                window.display();
            }
        }
    }
}
