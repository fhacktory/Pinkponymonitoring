//
// main.cpp for ppm in /home/camill_n/pinkponymonitoring/client
//
// Made by camill_n
// Login   <camill_n@epitech.net>
//
// Started on  Sat Oct 11 13:41:31 2014 camill_n
// Last update Thu Oct 16 22:49:32 2014 camill_n
//

#include <iostream>
#include <stdio.h>
#include <string>
#include "../../include/global.hpp"

using namespace std;

void	daemon(KernelController *kernel)
{
  int	i = 0;
  int	lastnb = 0;

  cout << "Pink Pony Monitoring (PPM) starting daemon" << endl;
  while (1)
    {
      cout << "Frame: " << i << endl;
      kernel->network->ReadAPI(kernel->config->getConfig("GET_API"), kernel->config->getConfig("TOKEN"));
      kernel->script->ManageRequestStack(kernel->network, kernel->config);
      //kernel->script->ShowScriptEnable();
      kernel->script->ExecScript(kernel->network, kernel->config);
      usleep(20000);
      ++i;
    }
}

int	main(int ac, char **av)
{
  KernelController *kernel;
  NetworkController network;
  ConfigController config(&network);
  ScriptController script;

  kernel = new KernelController();
  kernel->network = &network;
  kernel->config = &config;
  kernel->script = &script;
  daemon(kernel);
  return (0);
}
