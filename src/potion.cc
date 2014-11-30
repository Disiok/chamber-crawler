#include "potion.h"
#include "game.h"
#include "drow.h"
#include <iostream>
#include <sstream>
using namespace std;

Potion::Potion(Tile *tile, const string typeName): Player(tile, 0, 0, 0, SYMBOL_POTION, typeName) {
    tile->setEntity(this);
    symbol = SYMBOL_POTION;
    player = NULL;
    multiplier = 1;
}

bool Potion::choosePickUp(bool revealed) {
    while (true) {
        cout << "Pick up ";
        if (revealed) {
            cout << typeName << " potion";
        } else {
            cout << "Unknown potion";
        }
        cout << "? (y/n)" << endl;

        string choice;
        cin >> choice;
        if (choice == "y") {
            return true;
        } else if (choice == "n") {
            return false;
        }
    }
}

void Potion::addPickupAction() {
    ostringstream oss;
    oss << "Drank a " << typeName << " potion. ";
    Game::getInstance()->addAction(oss.str());
}

// Entity methods
bool Potion::pickedUpBy(Character *character) {
    // Clearing tile
    cell->clearEntity();

    // Wrapping player with this potion
    if (dynamic_cast<Potion *>(Player::getInstance())) {
        player = dynamic_cast<Potion *>(Player::getInstance());
    } else {
        player = Player::getInstance();
    }
    Player::setInstance(this);

    // Show pickup message
    addPickupAction();
    return true;
}

bool Potion::pickedUpBy(Drow *drow) {}

// Player methods
void Potion::move(Cell *cell) {
    player->move(cell);
}

void Potion::killedBy(Character *other) {
    player->killedBy(other);
}

void Potion::pickUp(Cell *cell) {
    player->pickUp(cell);
}

// Character methods
void Potion::attack(Character *other) {
    player->attack(other);
}

bool Potion::attackedBy(Character *other) {
    if (player) {
        return player->attackedBy(other);
    }
    return false;
}

void Potion::invokeAbility() {
    player->invokeAbility();
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

char Potion::getSymbol() {
    if (player) {
        return player->getSymbol();
    }
    return symbol;
}

Player *Potion::getBarePlayer() {
    return player->getBarePlayer();
}

string Potion::getTypeName() {
    return player->getTypeName();
}