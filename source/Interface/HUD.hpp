#ifndef HUD_HPP_INCLUDED
#define HUD_HPP_INCLUDED

#include "../System/LibrariesIncluding.hpp"
#include "../System/LoaderTextures.hpp"

namespace RhA{
    class CHud: public sf::Drawable{
        public:
         CHud(sf::Vector2u windowSize);

         void colorizeHpIcon(int currentHP, int maxHP);

        private:
         virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

         sf::Sprite hpIcon;

         int maxIntensity = 200;
         int minIntensity = 100;
    };
}

#endif // HUD_HPP_INCLUDED
