#include "HUD.hpp"

RhA::CHud::CHud(sf::Vector2u windowSize){
    hpIcon.setTexture(RhA::CLoaderResources::get().getTexture("gui/hp_icon1"));
    hpIcon.setPosition(windowSize.x - (hpIcon.getLocalBounds()).width, windowSize.y - (hpIcon.getLocalBounds()).height);

    hpIcon.setColor(sf::Color(minIntensity, maxIntensity, 100));
    //...
}

void RhA::CHud::colorizeHpIcon(int currentHP, int maxHP){
    int newIntensity = (maxIntensity - minIntensity) * currentHP / maxHP;

    hpIcon.setColor(sf::Color(maxIntensity - newIntensity, minIntensity + newIntensity, 100));
}

void RhA::CHud::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(hpIcon);
}
