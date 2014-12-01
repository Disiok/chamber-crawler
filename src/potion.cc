#include "potion.h"
#include "game.h"
#include "drow.h"
#include "cell.h"
#include "tile.h"
#include <iostream>
#include <sstream>
using namespace std;


// Constructor & destructor
Potion::Potion(Tile *tile): Player(tile, 0, 0, 0) {
    player = NULL;
    multiplier = 1;
}

Potion::~Potion() {}

// Protected potion methods
bool Potion::choosePickUp(bool revealed) {
    while (true) {
        cout << "Pick up ";
        if (revealed) {
            cout << getName() << " potion";
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
    oss << "Drank a " << getName() << " potion. ";
    Game::getInstance()->addAction(oss.str());
}

// Public potion methods
bool Potion::pickedUpBy(Character *) {
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

bool Potion::pickedUpBy(Drow *) {
	return true;
}

// Player methods
void Potion::killedBy(Character *other) {
    player->killedBy(other);
}

bool Potion::pickUp(Cell *cell) {
    return player->pickUp(cell);
}

bool Potion::engage(Cell *cell) {
	return player->engage(cell);
}

void Potion::equip(Sword *sword) {
	player->equip(sword);
}
void Potion::equip(Armor *armor) {
	player->equip(armor);
}

bool Potion::useInventory(int index) {
	return player->useInventory(index);
}

void Potion::addInventory(Inventory *item) {
	player->addInventory(item);
}


Player *Potion::getBarePlayer() {
	return player->getBarePlayer();
}

int Potion::getScore() {
	return player->getScore();
}

Inventory *Potion::getInventoryAt(int index) {
	return player->getInventoryAt(index);
}

Sword *Potion::getSword() {
	return player->getSword();
}

Armor *Potion::getArmor() {
	return player->getArmor();
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

bool Potion::isDead() {
    return player->isDead();
}


bool Potion::move(Cell *cell) {
    return player->move(cell);
}

void Potion::invokeAbility() {
    player->invokeAbility();
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

// Entity methods
Cell *Potion::getCell() {
    return player->getCell();
}

char Potion::getSymbol() {
    if (player) {
        return player->getSymbol();
    }
    return SYMBOL_POTION;
}

