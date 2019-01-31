#include "./Item.h"
#include <iostream>

SocketType::SocketType(unsigned char, Attribute, SocketColor) {}

void Item::print() {
  std::cout << "Size: " << static_cast<unsigned>(Item::height) << ", "
            << static_cast<unsigned>(Item::width) << std::endl;
}
