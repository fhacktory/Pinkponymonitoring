//
// config.hpp for ppm in /home/camill_n/pinkponymonitoring/client
//
// Made by camill_n
// Login   <camill_n@epitech.net>
//
// Started on  Sat Oct 11 14:25:22 2014 camill_n
// Last update Sat Oct 11 21:44:55 2014 camill_n
//

#ifndef CONFIG_H_
# define CONFIG_H_

#include <iostream>
#include "network.hpp"

using namespace std;

class ConfigController
{
private:
  string *addAPI;
  string *getAPI;
  string *setAPI;
  string *token;

public:
  ConfigController(NetworkController *network);
  void	 SetToken(string *addr);
  string *GetToken();
  void	 SetAddAPI(string *addr);
  string *GetAddAPI();
  void	 SetGetAPI(string *addr);
  string *GetGetAPI();
  void	 SetsetAPI(string *addr);
  string *GetsetAPI();
  string *GetDataInFile(string *fileName, string *dataName);
  void	 SetDataInFile(string *fileName, string *dataName, string *dataValue);
};

int	Split(vector<string>&vecteur, string buffer, char sep);

#endif
