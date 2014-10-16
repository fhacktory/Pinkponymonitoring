//
// network.cpp for ppm in /home/camill_n/pinkponymonitoring/client
//
// Made by camill_n
// Login   <camill_n@epitech.net>
//
// Started on  Sat Oct 11 14:40:28 2014 camill_n
// Last update Thu Oct 16 23:04:16 2014 camill_n
//

#include <curl/curl.h>
#include <stdlib.h>
#include "../../include/network.hpp"
#include "../../include/config.hpp"

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
      curl_easy_setopt(curl, CURLOPT_URL, addrAPI->data());
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallBack);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
      res = curl_easy_perform(curl);
      curl_easy_cleanup(curl);
      return (new string(readBuffer));
    }
  return (NULL);
}

bool	NetworkController::ReadAPI(string *getAPI, string *token)
{
  CURL		*curl;
  CURLcode	res;
  string	readBuffer;
  string	*formatedAddr;

  curl = curl_easy_init();
  if (curl)
    {
      // Get response from Get API
      formatedAddr = new string(getAPI->data());
      formatedAddr->append(token->data());
      curl_easy_setopt(curl, CURLOPT_URL, formatedAddr->data());
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallBack);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
      res = curl_easy_perform(curl);
      curl_easy_cleanup(curl);

      // Put each requests in requestStack
      Split(this->requestStack, readBuffer, ';');
      free(formatedAddr);
      return (true);
    }
  return (false);
}

bool	NetworkController::WriteAPI(string *dataToSend, string *setAPI, string *token)
{
  CURL		*curl;
  CURLcode	res;
  string	readBuffer;
  string	formatedAddr;
  vector<string> stack;

  curl = curl_easy_init();
  if (curl)
    {
      // Get response from Get API
      formatedAddr.append(*setAPI);
      formatedAddr.append(*token);
      formatedAddr.append("/");
      Split(stack, *dataToSend, '/');
      dataToSend = new string("");
      for (int i = 0; i < stack.size(); i++)
	{
	  dataToSend->append(stack.at(i));
	  if (i + 1 != stack.size())
	    dataToSend->append("#");
	}
      formatedAddr.append(*dataToSend);
      cout << "Sending datas: " << formatedAddr << endl;
      curl_easy_setopt(curl, CURLOPT_URL, formatedAddr.data());
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallBack);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
      res = curl_easy_perform(curl);
      curl_easy_cleanup(curl);
      return (true);
    }
  return (false);
}

NetworkController::NetworkController()
{
}
