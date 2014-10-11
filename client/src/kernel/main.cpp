//
// main.cpp for ppm in /home/camill_n/pinkponymonitoring/client
//
// Made by camill_n
// Login   <camill_n@epitech.net>
//
// Started on  Sat Oct 11 13:41:31 2014 camill_n
// Last update Sat Oct 11 18:22:49 2014 camill_n
//

#include <iostream>
#include "../../include/global.hpp"

using namespace std;

void	init_components(KernelController *kernel)
{
  kernel->network = new NetworkController();
  kernel->config = new ConfigController(kernel->network);
  //kernel->config->SetAddAPI(new string("http://77.194.204.33:11080/PPM/index.php/API/add_new_client/"));
  //kernel->network = new NetworkController(kernel->config);
}

int	main(int ac, char **av)
{
  KernelController *kernel;

  kernel = new KernelController();
  init_components(kernel);
  return (0);
}
