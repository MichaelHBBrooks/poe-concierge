#include "config/Config.h"
#include <stdlib.h>     //getenv_s
#include <cassert>      //assert
#include <exception>    //runtime_error
#include <filesystem>   //path, exists
#include <fstream>      //ofstream
#include <iostream>     //cout
#include <string>       //string
#include <string_view>  //string_view

std::string getEnv(const char* const);
void firstTimeSetup(const std::filesystem::path&);

bool Config::initialized = false;
std::string Config::accountName = "";
std::string Config::sessionID = "";

void Config::initialize() {
  assert(!Config::initialized);
  Config::initialized = true;

  // Temporary
  Config::setAccountName("");
  Config::setSessionID("");
  std::cout << "Account Name: " << Config::getAccountName() << std::endl;

  const std::string dbInstallDir = "";
  const std::string dbBin = dbInstallDir + "\\bin";

  const std::filesystem::path homePath = getEnv("USERPROFILE");
  if (!std::filesystem::exists(homePath)) {
    throw std::runtime_error("Unable to locate home directory");
  }
  const std::filesystem::path userDataPath = homePath / ".poe-concierge";
  if (std::filesystem::exists(userDataPath)) {
    std::cout << "Found user data.";
  } else {
    firstTimeSetup(userDataPath);
  }
}

void firstTimeSetup(const std::filesystem::path& dataDir) {
  std::cout << "Storing data in: " << dataDir << std::endl;
  std::filesystem::create_directory(dataDir);
  std::filesystem::path filePath = dataDir / "config";
  std::ofstream fileStream;
  int width = 30;
  fileStream.open(filePath);
  fileStream << "#User Data\n";
  fileStream << std::left << std::setw(width) << "accountName"
             << Config::getAccountName() << std::endl;
  fileStream << std::left << std::setw(width) << "sessionID"
             << Config::getSessionID() << std::endl;
  fileStream.close();
}

std::string getEnv(const char* const name) {
  size_t requiredSize;
  getenv_s(&requiredSize, nullptr, 0, name);
  if (requiredSize == 0) {
    throw std::runtime_error(std::string() +
                             "Environment variable is undefined: " + name);
  }
  std::string envVar;
  envVar.resize(requiredSize);
  getenv_s(&requiredSize, envVar.data(), requiredSize, name);
  //  Since getenv_s deposits the data as a char, the null terminator needs to
  //  be removed.
  envVar.erase(std::find(envVar.begin(), envVar.end(), '\0'), envVar.end());
  return envVar;
}

void Config::setAccountName(std::string_view name) {
  Config::accountName = name;
}

std::string_view Config::getAccountName() { return Config::accountName; }

void Config::setSessionID(std::string_view newID) { Config::sessionID = newID; }

std::string_view Config::getSessionID() { return Config::sessionID; }
