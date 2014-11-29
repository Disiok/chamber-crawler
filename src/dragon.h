#ifndef ___DRAGON_H___
#define ___DRAGON_H___
#include "enemy.h"
#include <string>

class Character;
class Tile;

class Dragon: public Enemy {
    public:
        static const std::string TYPE_NAME;
        static const char TYPE_ID = 'R';
        static const int HP = 150;
        static const int ATK = 20;
        static const int DEF = 20;
        Dragon(Tile *tile);

        void move();
};

#endif