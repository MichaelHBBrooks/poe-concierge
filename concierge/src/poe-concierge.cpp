#include <filesystem>
#include <iostream>  // cerr
#include "config/Config.h"
//#include <curl/curl.h>
//#include <nlohmann/json.hpp>
//#include <string>
//#include "API/Item.h"
//#include "character/PlayerCharacter.h"
//#include "API/webAPI.h"

// void testPlayerCharacter();
// void testItem();
// void testJSON();
// void testCURL();
// void testAPI();

int main() {
  try {
    Config::initialize();
  } catch (const std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
    exit(EXIT_FAILURE);
  }

  // testPlayerCharacter();
  // testItem();
  // testJSON();
  // testCURL();
  // testAPI();  // iostream, string, webAPI.h
  return 0;
}

// void testPlayerCharacter() {
//  PlayerCharacter me;
//  me.setName("Test");
//  me.setHitPoints(3000);
//  std::cout << "Player name: " << me.getName() << std::endl
//            << "HP: " << me.getHitPoints() << std::endl;
//}
//
// void testItem() {
//  Item i;
//  i.width = 2;
//  i.height = 3;
//  // std::cout << "Item width: " << static_cast<unsigned>(i.width) <<
//  std::endl; i.print();
//}
//
// void testJSON() {
//  nlohmann::json j;
//  j["pi"] = 3.141;
//  j["happy"] = true;
//  std::cout << j.dump(4) << std::endl;
//}
//
// void testCURL() {
//    CURL *curl;
//    CURLcode res;
//
//    CURLU *urlp;
//    CURLUcode uc;
//
//    /* get a curl handle */
//    curl = curl_easy_init();
//
//    /* init Curl URL */
//    urlp = curl_url();
//    uc = curl_url_set(urlp, CURLUPART_URL,
//    "http://example.com/path/index.html",
//                      0);
//
//    if (uc) {
//      fprintf(stderr, "curl_url_set() failed: %in", uc);
//      goto cleanup;
//    }
//
//    if (curl) {
//      /* set urlp to use as working URL */
//      curl_easy_setopt(curl, CURLOPT_CURLU, urlp);
//      curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
//
//      res = curl_easy_perform(curl);
//      /* Check for errors */
//      if (res != CURLE_OK)
//        fprintf(stderr, "curl_easy_perform() failed: %s\n",
//                curl_easy_strerror(res));
//
//      goto cleanup;
//    }
//
//   cleanup:
//    curl_url_cleanup(urlp);
//    curl_easy_cleanup(curl);
//}

// void testAPI() {
//  using namespace std::string_literals;
//
//  std::string url =
//      "https://www.pathofexile.com/character-window/"
//      "get-stash-items?league=synthesis&tabs=0&tabIndex=0&accountName=Jinieren";
//  auto j = webAPI::getStashItems(url);
//
//  std::string s = j.dump();
//  std::cout << s;
//}
