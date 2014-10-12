//
// network.cpp for ppm in /home/camill_n/pinkponymonitoring/client
//
// Made by camill_n
// Login   <camill_n@epitech.net>
//
// Started on  Sat Oct 11 14:40:28 2014 camill_n
// Last update Sun Oct 12 07:53:12 2014 camill_n
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

static const std::string base64_chars =
               "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
               "abcdefghijklmnopqrstuvwxyz"
  "0123456789+/";


std::string base64_encode(unsigned char const* bytes_to_encode, unsigned int in_len) {
  std::string ret;
  int i = 0;
  int j = 0;
  unsigned char char_array_3[3];
  unsigned char char_array_4[4];

  while (in_len--) {
    char_array_3[i++] = *(bytes_to_encode++);
    if (i == 3) {
      char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
      char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
      char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
      char_array_4[3] = char_array_3[2] & 0x3f;

      for(i = 0; (i <4) ; i++)
	ret += base64_chars[char_array_4[i]];
      i = 0;
    }
  }

  if (i)
    {
      for(j = i; j < 3; j++)
	char_array_3[j] = '\0';

      char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
      char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
      char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
      char_array_4[3] = char_array_3[2] & 0x3f;

      for (j = 0; (j < i + 1); j++)
	ret += base64_chars[char_array_4[j]];

      while((i++ < 3))
	ret += '=';

    }

  return ret;

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
      return (new string(readBuffer.data()));
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
      //      *dataToSend = base64_encode((const unsigned char *)dataToSend->data(), dataToSend->size());
      //   dataToSend = new string(curl_easy_escape(curl, dataToSend->data(), dataToSend->size()));
      Split(stack, *dataToSend, '/');
      dataToSend = new string("");
      for (int i = 0; i < stack.size(); i++)
	{
	  dataToSend->append(stack.at(i));
	  if (i + 1 != stack.size())
	    dataToSend->append("#");
	}
      formatedAddr.append(*dataToSend);
      //cout << "ENVOIE: " << formatedAddr << endl;
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
