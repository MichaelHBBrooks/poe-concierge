#include "PlayerCharacter.h"
#include <string>

std::string PlayerCharacter::getName() { return PlayerCharacter::name; }

void PlayerCharacter::setName(std::string newName) {
  PlayerCharacter::name = newName;
}
