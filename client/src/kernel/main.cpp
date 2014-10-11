//
// main.cpp for ppm in /home/camill_n/pinkponymonitoring/client
//
// Made by camill_n
// Login   <camill_n@epitech.net>
//
// Started on  Sat Oct 11 13:41:31 2014 camill_n
// Last update Sat Oct 11 23:01:51 2014 camill_n
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

  cout << "Pink Pony Monitoring (PPM) start" << endl;
  while (1)
    {
      cout << "Frame: " << i << endl;
      kernel->network->ReadAPI(kernel->config->GetGetAPI(), kernel->config->GetToken());
      kernel->script->ManageRequestStack(kernel->network);
      kernel->script->ShowScriptEnable();
      kernel->script->ExecScript();
      usleep(1000000);
      ++i;
    }
}

void	init_components(KernelController *kernel)
{
  kernel->network = new NetworkController();
  kernel->config = new ConfigController(kernel->network);
  kernel->script = new ScriptController();
}

int	main(int ac, char **av)
{
  KernelController *kernel;

  kernel = new KernelController();
  init_components(kernel);
  daemon(kernel);
  return (0);
}
