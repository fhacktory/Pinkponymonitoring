//
// kernel.hpp for ppm in /home/camill_n/pinkponymonitoring/client
//
// Made by camill_n
// Login   <camill_n@epitech.net>
//
// Started on  Sat Oct 11 14:36:07 2014 camill_n
// Last update Sun Oct 12 09:28:03 2014 camill_n
//

#ifndef KERNEL_H_
# define KERNEL_H_

#include "config.hpp"
#include "network.hpp"
#include <deque>
#include <string>

class ScriptController
{
public:
  deque<string> currentScript;
  void		ShowScriptEnable();
  bool		ManageRequestStack(NetworkController *network, ConfigController *config);
  bool		IsAlreadyEnable(string needle);
  bool		SaveResponse(string *saveData, string cmdName, string response);
  string	*ExecScript(NetworkController *network, ConfigController *config);
  void		ExecCmd(NetworkController *network, ConfigController *config, string *cmd);
};

class KernelController
{
public:
  NetworkController	*network;
  ConfigController	*config;
  ScriptController	*script;
};

#endif
