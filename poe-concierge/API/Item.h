#pragma once

#include <string>
#include "lib/Attribute.h"
#include "lib/SocketColor.h"

struct SocketType {
  SocketType(unsigned char, Attribute, SocketColor);
  unsigned char group;
  Attribute attribute;
  SocketColor color;
};

struct Item {
  bool verified;
  unsigned char width;
  unsigned char height;
  unsigned char itemLevel;
  std::string icon;
  std::string league;
  std::string id;
  bool elder;
  bool shaper;
  SocketType* sockets;

  void print();
};
