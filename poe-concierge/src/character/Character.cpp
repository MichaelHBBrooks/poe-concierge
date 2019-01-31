#include "./Character.h";

void Character::setHitPoints(unsigned short int newHitPoints) {
  Character::hitPoints = newHitPoints;
}

unsigned short int Character::getHitPoints() { return Character::hitPoints; }