#pragma once
#include <nlohmann/json.hpp>
#include <sstream>
#include <string_view>

class webAPI {
 public:
  static nlohmann::json getStashItems(std::string_view);
};
