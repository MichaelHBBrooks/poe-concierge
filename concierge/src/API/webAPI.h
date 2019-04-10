#pragma once
#include <sstream>
#include <string_view>

class webAPI {
 public:
  static std::stringstream getStashItems(std::string_view);
};
