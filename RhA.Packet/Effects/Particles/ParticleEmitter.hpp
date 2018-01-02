#ifndef PARTICLEEMITTER_HPP_INCLUDED
#define PARTICLEEMITTER_HPP_INCLUDED

#include "System/LibrariesIncluding.hpp"
#include "System/Helpful.hpp"
#include "ParticlesManager.hpp"

namespace RhA{
    class CParticleEmitter{
        public:
         virtual void update(float dt)=0;
         virtual void draw(sf::RenderTarget& target)=0;

         inline int getAmount(){return pAmount;}
         inline int getCurrAmount(){return vParticles.size();}

         inline bool checkAmount(){
            if(vParticles.size() < pAmount)
                return true;
            else return false;
         }

        protected:
         sf::Texture texture;
         int pAmount = 0;

         std::vector<RhA::CParticle>vParticles;
    };
}

#endif // PARTICLEEMITTER_HPP_INCLUDED
