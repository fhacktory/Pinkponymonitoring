//
// network.hpp for network in /home/camill_n/pinkponymonitoring/client
//
// Made by camill_n
// Login   <camill_n@epitech.net>
//
// Started on  Sat Oct 11 14:22:42 2014 camill_n
// Last update Sat Oct 11 16:14:26 2014 camill_n
//

#ifndef NETWORK_H_
# define NETWORK_H_

#include <iostream>
#include "global.hpp"

using namespace std;

class	NetworkController
{
public:
  NetworkController(ConfigController *config);
  
private:
  string *token;
};

#endif
