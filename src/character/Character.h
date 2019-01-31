#pragma once

class Character {
 public:
  unsigned short int getHitPoints();
  void setHitPoints(unsigned short int);

 private:
  unsigned short int hitPoints;
};