//
// network.cpp for ppm in /home/camill_n/pinkponymonitoring/client
//
// Made by camill_n
// Login   <camill_n@epitech.net>
//
// Started on  Sat Oct 11 14:40:28 2014 camill_n
// Last update Sat Oct 11 16:14:47 2014 camill_n
//

#include <curl/curl.h>
#include "../../include/global.hpp"

static size_t WriteCallBack(void *contents, size_t size, size_t nmemb, void *userp)
{
  ((string*)userp)->append((char*)contents, size * nmemb);
  return size * nmemb;
}

NetworkController::NetworkController(ConfigController *config)
{
  CURL		*curl;
  CURLcode	res;
  string	readBuffer;

  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://www.google.com");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallBack);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    std::cout << readBuffer << std::endl;
  }
}
