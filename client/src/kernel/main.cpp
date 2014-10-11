//
// main.cpp for ppm in /home/camill_n/pinkponymonitoring/client
//
// Made by camill_n
// Login   <camill_n@epitech.net>
//
// Started on  Sat Oct 11 13:41:31 2014 camill_n
// Last update Sat Oct 11 21:57:44 2014 camill_n
//

#include <iostream>
#include <stdio.h>
#include <string>
#include "../../include/global.hpp"

using namespace std;

void	daemon(KernelController *kernel)
{
  int	i = 0;
  string request;

  cout << "Pink Pony Monitoring (PPM) start" << endl;
  while (1)
    {
      cout << "Frame: " << i << endl;
      kernel->network->ReadAPI(kernel->config->GetGetAPI(), kernel->config->GetToken());
      for (std::vector<string>::iterator it = kernel->network->requestStack.begin(); it != kernel->network->requestStack.end(); ++it)
	cout << *it << endl;
      usleep(1000000);
      ++i;
    }
}

void	init_components(KernelController *kernel)
{
  kernel->network = new NetworkController();
  kernel->config = new ConfigController(kernel->network);
}

int	main(int ac, char **av)
{
  KernelController *kernel;

  kernel = new KernelController();
  init_components(kernel);
  daemon(kernel);
  return (0);
}
