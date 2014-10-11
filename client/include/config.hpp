//
// config.hpp for ppm in /home/camill_n/pinkponymonitoring/client
//
// Made by camill_n
// Login   <camill_n@epitech.net>
//
// Started on  Sat Oct 11 14:25:22 2014 camill_n
// Last update Sat Oct 11 16:15:55 2014 camill_n
//

#ifndef CONFIG_H_
# define CONFIG_H_

#include <iostream>
#include "global.hpp"

using namespace std;

class ConfigController
{
private:
  string *addAPI;
  string *getAPI;
  string *setAPI;
public:
  void	 SetAddAPI(string *addr);
  string *GetAddAPI(string *addr);
  void	 SetGetAPI(string *addr);
  string *GetGetAPI(string *addr);
  void	 SetsetAPI(string *addr);
  string *GetsetAPI(string *addr);
};

#endif
