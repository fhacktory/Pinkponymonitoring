//
// kernel.hpp for ppm in /home/camill_n/pinkponymonitoring/client
//
// Made by camill_n
// Login   <camill_n@epitech.net>
//
// Started on  Sat Oct 11 14:36:07 2014 camill_n
// Last update Sat Oct 11 15:59:49 2014 camill_n
//

#ifndef KERNEL_H_
# define KERNEL_H_

#include "global.hpp"

class KernelController
{
public:
  NetworkController	*network;
  ConfigController	*config;
};

#endif
