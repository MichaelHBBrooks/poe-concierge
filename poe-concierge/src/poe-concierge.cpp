#include <iostream>
#include "src/API/Item.h"
#include "src/character/PlayerCharacter.h"

void testPlayerCharacter();
void testItem();

int main() {
  std::cout << "Hello World!\n";
  testPlayerCharacter();
  testItem();

  return 0;
}

void testPlayerCharacter() {
  PlayerCharacter me;
  me.setName("Test");
  me.setHitPoints(3000);
  std::cout << "Player name: " << me.getName() << std::endl
            << "HP: " << me.getHitPoints() << std::endl;
}

void testItem() {
  Item i;
  i.width = 2;
  i.height = 3;
  // std::cout << "Item width: " << static_cast<unsigned>(i.width) << std::endl;
  i.print();
}