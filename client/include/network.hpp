//
// network.hpp for network in /home/camill_n/pinkponymonitoring/client
//
// Made by camill_n
// Login   <camill_n@epitech.net>
//
// Started on  Sat Oct 11 14:22:42 2014 camill_n
// Last update Sun Oct 12 01:09:34 2014 camill_n
//

#ifndef NETWORK_H_
# define NETWORK_H_

#include <iostream>
#include <unistd.h>
#include <vector>

using namespace std;

class	NetworkController
{
public:
  NetworkController();
  string *GenerateNewToken(string *addrAPI);
  bool	 ReadAPI(string *getAPI, string *token);
  bool	 WriteAPI(string *dataToSend, string *setAPI, string *token);
  vector <string> requestStack;
  vector <string> responseStack;
};

#endif
