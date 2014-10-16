#include "../../include/global.hpp"

string 	*ConfigController::getConfig(string configName)
{
  if (this->currentConfig.find(configName) != this->currentConfig.end())
    return (new string(this->currentConfig[configName]));
  else
    return (NULL);
}
