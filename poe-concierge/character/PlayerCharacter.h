#pragma once

#include <string>
#include "Character.h"

class PlayerCharacter : public Character {
 public:
  std::string getName();
  void setName(std::string);

 private:
  std::string name;
};
