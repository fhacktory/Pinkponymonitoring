//
// kernel.hpp for ppm in /home/camill_n/pinkponymonitoring/client
//
// Made by camill_n
// Login   <camill_n@epitech.net>
//
// Started on  Sat Oct 11 14:36:07 2014 camill_n
// Last update Sat Oct 11 23:04:10 2014 camill_n
//

#ifndef KERNEL_H_
# define KERNEL_H_

#include "config.hpp"
#include "network.hpp"
#include <string>

class ScriptController
{
public:
  vector<string> currentScript;
  void		ShowScriptEnable();
  bool		ManageRequestStack(NetworkController *network);
  bool		IsAlreadyEnable(string needle);
  string	*ExecScript();
};

class KernelController
{
public:
  NetworkController	*network;
  ConfigController	*config;
  ScriptController	*script;
};

#endif
