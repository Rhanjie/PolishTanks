#include "LoaderTextures.hpp"


bool RhA::CLoaderResources::loadResources(){
    std::string prefix = "media/";
    /*file.open("data/texturesInfo.RhAf");

    if(!file.is_open()){
        std::cout << "[!] Can't open file with resources list!\n";

        return false;
    }

    while(!file.eof()){
        std::string textLine;
        size_t separatorPos;

        file.getline(textLine);

        for(int i=0; i < 2; ++i){
            if((separatorPos = textLine.find(":")) == std::string::npos){
                //...

                return false;
            }
        }

        prefix += textLine.
    }*/

    mTexturesNames["error"] = 1; // todo - load data from file
    mTexturesNames["tankBody"] = 1;
    mTexturesNames["tankTurret"] = 1;
    mTexturesNames["terrain/grass"] = 7;
    mTexturesNames["terrain/objects/tree"] = 3;
    mTexturesNames["fog"] = 1;
    mTexturesNames["bullet"] = 1;
    mTexturesNames["gui/hp_icon"] = 1;


    for(auto &it : mTexturesNames){
        for(int i = 1; i <= it.second; ++i){
            std::string helper = RhA::toString(i);

            std::cout << " - " << prefix << it.first << helper << ".png" << std::endl;

            if(!mTextures[it.first + helper].loadFromFile(prefix + it.first + helper + ".png")){
                return loaded; //false
            }
        }
    }

    loaded = true;
    return loaded;
}
