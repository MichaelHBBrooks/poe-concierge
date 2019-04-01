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

#include "curlcpp/cookie.h"
#include "curlcpp/cookie_datetime.h"
#include "curlcpp/curl_cookie.h"
#include "curlcpp/curl_easy.h"
#include "curlcpp/curl_exception.h"
#include "curlcpp/curl_form.h"
#include "curlcpp/curl_ios.h"

std::stringstream getStashItems(std::string_view url) {
  std::stringstream str;
  curl::curl_ios<std::stringstream> writer(str);

  curl::curl_easy easy(writer);

  easy.add<CURLOPT_URL>(url.data());
  easy.add<CURLOPT_FOLLOWLOCATION>(1L);

  //  Cookie
  curl::cookie cookie;
  curl::cookie_date date(curl::weekdays::MONDAY, 27, curl::months::MARCH, 2037);
  curl::cookie_time time(20, 30, 30);
  curl::cookie_datetime datetime(time, date);

  cookie.set_name("POESESSID");
  cookie.set_value("");  //  POESESSID goes here.
  cookie.set_path("/");
  cookie.set_domain(".pathofexile.com");
  cookie.set_datetime(datetime);

  //  Create a cookie object and add the previously created cookie.
  curl::curl_cookie c_obj(easy);
  c_obj.set(cookie);

  curl::curlcpp_cookies cookies;
  try {
    easy.perform();
    // cookies = c_obj.get();
    // c_obj.erase();
  } catch (curl::curl_easy_exception error) {
    std::cout << "error found\n";
    auto errors = error.get_traceback();
    error.print_traceback();
  }

  return str;
}

int main() {
  using namespace std::string_literals;

  auto url =
      "https://www.pathofexile.com/character-window/get-stash-items?league=synthesis&tabs=0&tabIndex=0&accountName=Jinieren"s;
  auto json = getStashItems(url);

  std::cout << json.str() << std::endl;

  return 0;
}
