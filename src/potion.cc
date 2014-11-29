#include "potion.h"
using namespace std;

Potion::Potion(Tile *tile, const string typeIdentifier): Player(tile, 0, 0, 0, SYMBOL_POTION, typeIdentifier) {
    tile->setEntity(this);
    symbol = SYMBOL_POTION;
}

// Player methods
void Potion::move(Cell *cell) {
    player->move(cell);
}

void Potion::pickUp(Cell *cell) {
    player = Player::getInstance();
    Player::setInstance(this);
    player->pickUp(cell);
}

void Potion::killedBy(Character *other) {
    player->killedBy(other);
}

// Character methods
void Potion::attack(Character *other) {
    player->attack(other);
}

bool Potion::attackedBy(Character *other) {
    return player->attackedBy(other);
}

bool Potion::isDead() {
    return player->isDead();
}

int Potion::getHP() {
    return player->getHP();
}

int Potion::getAtk() {
    return player->getAtk();
}

int Potion::getDef() {
    return player->getDef();
}

int Potion::getGold() {
    return player->getGold();
}

void Potion::setHP(int hp) {
    player->setHP(hp);
}

void Potion::setAtk(int atk) {
    player->setAtk(atk);
}

void Potion::setDef(int def) {
    player->setDef(def);
}

void Potion::setGold(int gold) {
    player->setGold(gold);
}

Cell *Potion::getCell() {
    return player->getCell();
}

Player *Potion::getBarePlayer() {

}