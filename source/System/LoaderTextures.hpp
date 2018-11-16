#ifndef LOADERTEXTURES_HPP_INCLUDED
#define LOADERTEXTURES_HPP_INCLUDED

#include "LibrariesIncluding.hpp"
#include "Helpful.hpp"

namespace RhA{
    class CLoaderResources{
        public:
         inline bool isLoaded(){return loaded;}

         static CLoaderResources &get(){
            static CLoaderResources loaderResources;

            return loaderResources;
         }

         sf::Texture &getTexture(std::string id){
            std::map<std::string, sf::Texture>::iterator it = mTextures.find(id);

            if(it != mTextures.end())
             return it->second;

            return mTextures["error"];
         }

        private:
         CLoaderResources(){loadResources();}
         CLoaderResources(const CLoaderResources&);
         ~CLoaderResources(){file.close();}

         bool loadResources();


         std::map<std::string, sf::Texture>mTextures;
         std::map<std::string, unsigned short>mTexturesNames;

         std::fstream file;
         bool loaded = false;
    };
}

#endif // LOADERTEXTURES_HPP_INCLUDED
