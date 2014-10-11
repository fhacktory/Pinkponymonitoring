//
// script.cpp for ppm in /home/camill_n/pinkponymonitoring/client
//
// Made by camill_n
// Login   <camill_n@epitech.net>
//
// Started on  Sat Oct 11 22:08:25 2014 camill_n
// Last update Sat Oct 11 23:07:11 2014 camill_n
//

#include "../../include/global.hpp"
#include <stdlib.h>
#include <algorithm>
#include <string>

bool		ScriptController::ManageRequestStack(NetworkController *network)
{
  vector<string>	currentRequest;
  string		request;
  int			nbRequest = 0;
  std::vector<string>::iterator it2;

  for (std::vector<string>::iterator it = network->requestStack.begin(); it != network->requestStack.end(); ++it)
    {
      request = *it;
      nbRequest = Split(currentRequest, request, ' ');
      if (nbRequest >= 2)
	{
	  // ADD COMMAND
	  if (currentRequest[0].compare("add") == 0)
	    {
	      if (this->IsAlreadyEnable(currentRequest[1]) == false)
		this->currentScript.push_back(string(currentRequest[1].data()));
	    }
	}
    }
  return (true);
}

void	ScriptController::ShowScriptEnable()
{
  cout << "Script Enable:" << endl;

  for (std::vector<string>::iterator it = this->currentScript.begin(); it != this->currentScript.end(); ++it)
    {
      cout << *it << endl;
    }
}

bool	ScriptController::IsAlreadyEnable(string needle)
{
  string str;

  cout << "Script Enable:" << endl;

  for (std::vector<string>::iterator it = this->currentScript.begin(); it != this->currentScript.end(); ++it)
    {
      str = *it;
      if (str.compare(needle) == 0)
	return (true);
    }
  return (false);
}

string *ScriptController::ExecScript()
{
  string *formatLine;
  string scriptName;

  for (std::vector<string>::iterator it = this->currentScript.begin(); it != this->currentScript.end(); ++it)
    {
      formatLine = new string("./scripts/");
      scriptName = *it;
      formatLine->append(scriptName);
      formatLine->append(" >> test");
      system(formatLine->data());
      ifstream file ("test");
      if (file)
	{
	  
	}
      free(formatLine);
    }
}
