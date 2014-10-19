//
// main.cpp for ppm in /home/camill_n/pinkponymonitoring/client
//
// Made by camill_n
// Login   <camill_n@epitech.net>
//
// Started on  Sat Oct 11 13:41:31 2014 camill_n
// Last update Sun Oct 19 18:28:09 2014 camill_n
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string>
#include "../../include/global.hpp"

using namespace std;

KernelController kernel;

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

void	catchSig(int sig)
{
  kernel.config->SaveData(".config", '=', &kernel.config->currentConfig);
  kernel.config->SaveData(".script", &kernel.script->currentScript);
  exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
  NetworkController network;
  ConfigController *config;
  ScriptController script;

  kernel.network = &network;
  kernel.script = &script;
  kernel.config = new ConfigController(&kernel);
  signal(SIGINT, catchSig);
  daemon(&kernel);
  return (0);
}
