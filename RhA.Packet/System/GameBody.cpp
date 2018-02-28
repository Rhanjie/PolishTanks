#include "GameManager.hpp"

void RhA::CGameManager::bodyMenu(){
    gameplayType = GAME;

    ///TODO: Add menu
}

void RhA::CGameManager::bodyGameplay(){
    const int TEXTURE_SIZE = 128;

    RhA::CTerrain terrain;
    terrain.generate(window, sf::Vector2i(30, 30), TEXTURE_SIZE);

    ///TODO: Add shop with tank modules
    sf::Texture body = RhA::CLoaderResources::get().getTexture("tankBody1");
    sf::Texture turret = RhA::CLoaderResources::get().getTexture("tankTurret1");

    sf::Vector2f spawnPosition = sf::Vector2f(terrain.getSize().x*TEXTURE_SIZE/2, terrain.getSize().y*TEXTURE_SIZE/2);

    RhA::CPlayer player;
    player.create(spawnPosition, 200.0f, 60.0f, body, turret);

    RhA::CHud hud(window.getSize());

    ///TODO: Add weather system
    sf::RectangleShape fogEffect = sf::RectangleShape((sf::Vector2f)window.getSize());
    fogEffect.setFillColor(sf::Color(255, 255, 255, 75));

    sf::Vector2f fogSpawnPos = sf::Vector2f(0.0F, 0.0F);
    ///TODO: Improve fog system when camera_scale > 1.0
    RhA::CFogEmitter fogEmitter = RhA::CFogEmitter(RhA::CLoaderResources::get().getTexture("fog1"), 60);
    const float scale = 1.5;
    camera.zoom(scale);

    sf::Vector2f mousePosition;
    while(gameplayType == GAME){
        timeManager.update(window.getSize());

        while(window.pollEvent(event)){
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape){
                gameplayType = CLOSE;

                return;
            }
        }

        ///TODO: "Mission failed"
        if(player.getStatus(HEALTH) <= 0){
            gameplayType = CLOSE;

            return;
        }

        hud.colorizeHpIcon(player.getStatus(HEALTH), player.getStatus(MAXHEALTH));

        window.setView(camera);{
            mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            terrain.update(window, timeManager.getDeltaTime());

            if(fogEmitter.checkAmount()){
                fogSpawnPos = sf::Vector2f(
                    player.getPosition().x + (rand()%(int)((window.getView()).getSize().x * 2)) - (window.getView()).getSize().x,
                    player.getPosition().y + (rand()%(int)((window.getView()).getSize().x * 2)) - (window.getView()).getSize().y
                );

                fogEmitter.addParticle(fogSpawnPos, scale);
            }

            terrain.checkCollision(player);
        } window.setView(window.getDefaultView());

        player.update(mousePosition, timeManager.getDeltaTime());
        camera.setCenter(player.getPosition());
        fogEmitter.update(timeManager.getDeltaTime());

        { /**Draw all objects**/
            window.clear();
            window.setView(camera);

            window.draw(terrain);
            window.draw(player);

            terrain.drawObjects(window);
            fogEmitter.draw(window);

            window.setView(window.getDefaultView());

            window.draw(fogEffect);
            window.draw(hud);
            window.draw(timeManager);

            window.display();
        }

        timeManager.restart();
    }
}
