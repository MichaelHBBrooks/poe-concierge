#pragma once
#include <sstream>
#include <string_view>

//  JSON
#include "nlohmann/json.hpp"

class webAPI {
 public:
  static nlohmann::json getStashItems(std::string_view);

 private:
  static const std::string poeBaseUrl;
};
