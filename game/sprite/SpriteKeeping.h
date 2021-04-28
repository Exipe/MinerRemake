//
// Created by Ludwig on 2017-06-22.
//

#ifndef MINER_SPRITEKEEPING_H
#define MINER_SPRITEKEEPING_H


#include <map>
#include <string>

class Sprite;

class SpriteKeeping {

private:
    std::map<std::string, Sprite*> m_sprites;
    std::string m_root;

public:
    SpriteKeeping(std::string root);

    ~SpriteKeeping();

    Sprite &get(std::string path);

};


#endif //MINER_SPRITEKEEPING_H
