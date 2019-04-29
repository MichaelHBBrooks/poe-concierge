#include "API/webAPI.h"
#include <iostream>
#include <map>
#include <ostream>
#include <string>
#include <string_view>
#include "config/Config.h"

//  CurlCPP
#include "curlcpp/cookie.h"
#include "curlcpp/cookie_datetime.h"
#include "curlcpp/curl_cookie.h"
#include "curlcpp/curl_easy.h"
#include "curlcpp/curl_exception.h"
#include "curlcpp/curl_form.h"
#include "curlcpp/curl_ios.h"

//  JSON
#include "nlohmann/json.hpp"

nlohmann::json webAPI::getStashItems(std::string_view url) {
  const std::string api = "get-stash-items";
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
  // TODO: Fix messy string_view copy.
  cookie.set_value(std::string(Config::getSessionID()).data());
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

  return nlohmann::json::parse(str);
}

const std::string webAPI::poeBaseUrl =
    "https://www.pathofexile.com/character-window/";
