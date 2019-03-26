//#include <curl/curl.h>
//#include <iostream>
//#include <nlohmann/json.hpp>
//#include <string>
//#include "API/Item.h"
//#include "character/PlayerCharacter.h"
//
// void testPlayerCharacter();
// void testItem();
// void testJSON();
// void testCURL();
//
// int main() {
//  std::cout << "Hello World!\n";
//  testPlayerCharacter();
//  testItem();
//
//  testJSON();
//  testCURL();
//  return 0;
//}
//
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

#include <iostream>
#include <map>
#include <ostream>
#include <string>
#include <string_view>

#include "curl_easy.h"
#include "curl_exception.h"
#include "curl_form.h"
#include "curl_ios.h"

std::stringstream get_response(std::string_view url) {
  std::stringstream str;
  curl::curl_ios<std::stringstream> writer(str);

  curl::curl_easy easy(writer);

  easy.add<CURLOPT_URL>(url.data());
  easy.add<CURLOPT_FOLLOWLOCATION>(1L);
  try {
    easy.perform();
  } catch (curl::curl_easy_exception error) {
    auto errors = error.get_traceback();
    error.print_traceback();
  }

  return str;
}

int main() {
  using namespace std::string_literals;

  auto appid = "...key..."s;
  auto location = "Timisoara"s;
  auto url = "https://api.openweathermap.org/data/2.5/weather?q=" + location +
             "&appid=" + appid;

  auto json = get_response(url);

  std::cout << json.str() << std::endl;

  return 0;
}