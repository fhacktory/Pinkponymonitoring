//
// config.cpp for ppm in /home/camill_n/pinkponymonitoring/client
//
// Made by camill_n
// Login   <camill_n@epitech.net>
//
// Started on  Sat Oct 11 15:41:48 2014 camill_n
// Last update Sat Oct 11 16:16:43 2014 camill_n
//

#include <iostream>
#include "../../include/global.hpp"

void 	ConfigController::SetAddAPI(string *addr)
{
  this->addAPI = addr;
}

string 	*ConfigController::GetAddAPI(string *addr)
{
  return (this->addAPI);
}

void 	ConfigController::SetGetAPI(string *addr)
{
  this->getAPI = addr;
}

string 	*ConfigController::GetGetAPI(string *addr)
{
  return (this->getAPI);
}

void 	ConfigController::SetsetAPI(string *addr)
{
  this->setAPI = addr;
}

string 	*ConfigController::GetsetAPI(string *addr)
{
  return (this->setAPI);
}
