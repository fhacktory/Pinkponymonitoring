//
// network.cpp for ppm in /home/camill_n/pinkponymonitoring/client
//
// Made by camill_n
// Login   <camill_n@epitech.net>
//
// Started on  Sat Oct 11 14:40:28 2014 camill_n
// Last update Sat Oct 11 18:49:29 2014 camill_n
//

#include <curl/curl.h>
#include "../../include/network.hpp"
#include "../../include/config.hpp"
#include "../../include/global.hpp"

static size_t WriteCallBack(void *contents, size_t size, size_t nmemb, void *userp)
{
  ((string*)userp)->append((char*)contents, size * nmemb);
  return size * nmemb;
}

string *NetworkController::GenerateNewToken(string *addrAPI)
{
  CURL		*curl;
  CURLcode	res;
  string	readBuffer;

  curl = curl_easy_init();
  if (curl)
    {
      curl_easy_setopt(curl, CURLOPT_URL, addrAPI);
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallBack);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
      res = curl_easy_perform(curl);
      curl_easy_cleanup(curl);
      return (new string(readBuffer.data()));
    }
  return (NULL);
}

NetworkController::NetworkController()
{
}
