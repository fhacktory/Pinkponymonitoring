//
// config.hpp for ppm in /home/camill_n/pinkponymonitoring/client
//
// Made by camill_n
// Login   <camill_n@epitech.net>
//
// Started on  Sat Oct 11 14:25:22 2014 camill_n
// Last update Wed Oct 15 22:56:53 2014 camill_n
//

#ifndef CONFIG_H_
# define CONFIG_H_

#include <iostream>
#include <map>
#include "network.hpp"

using namespace std;

class ConfigController
{
private:
  map<string, string> currentConfig;

public:
  ConfigController(NetworkController *network);
  virtual ~ConfigController();
  string *getConfig(string configName);
  string *GetDataInFile(string *fileName, string *dataName);
  void	 SetDataInFile(string *fileName, string *dataName, string *dataValue);
  bool	ReadConfig();
  bool	getAllDataInFile(string fileName, map<string, string> *splitTab);
};

int	Split(vector<string>&vecteur, string buffer, char sep);

#endif
