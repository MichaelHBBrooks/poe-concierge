#include "config/Config.h"
#include <stdlib.h>  //getenv_s
#include <exception>
#include <iostream>  //cout
#include <mutex>     //call_once
#include <string>
#include <string_view>

std::string getEnv(const char* const);

std::once_flag Config::initialized;
std::string Config::accountName = "";
std::string Config::sessionID = "";

void Config::initialize() {
  std::call_once(Config::initialized, []() {
    // Temporary
    Config::setAccountName("");
    Config::setSessionID("");
    std::cout << "Account Name: " << Config::getAccountName() << std::endl;

    const std::string dbInstallDir = "";
    const std::string dbBin = dbInstallDir + "\\bin";

    // const std::filesystem::path home = getenv_s("USERPROFILE");

    const std::string asdf = getEnv("USERPROFILE");
  });
}

std::string getEnv(const char* const name) {
  size_t requiredSize;
  char* envVar;
  getenv_s(&requiredSize, NULL, 0, name);
  if (requiredSize == 0) {
    std::cout << name << " does not exist.\n";
  } else {
    envVar = (char*)malloc(requiredSize * sizeof(char));
    if (envVar) {
      getenv_s(&requiredSize, envVar, requiredSize, name);
      const std::string envVarStr = envVar;
      free(envVar);
      std::cout << name << " is: " << envVarStr << std::endl;
      return envVarStr;

    } else {
      std::cout << "Failed to allocate memory.\n";
    }
  }
  return "";
}

void Config::setAccountName(std::string_view name) {
  Config::accountName = name;
}

std::string_view Config::getAccountName() { return Config::accountName; }

void Config::setSessionID(std::string_view newID) { Config::sessionID = newID; }

std::string_view Config::getSessionID() { return Config::sessionID; }
