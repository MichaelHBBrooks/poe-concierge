#pragma once

#include <string>
#include <string_view>

class Config {
 public:
  static void initialize();
  static void setAccountName(std::string_view);
  static std::string_view getAccountName();

  static void setSessionID(std::string_view);
  static std::string_view getSessionID();

 private:
  static bool initialized;
  static std::string accountName;
  static std::string sessionID;
};