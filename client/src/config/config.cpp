//
// config.cpp for ppm in /home/camill_n/pinkponymonitoring/client
//
// Made by camill_n
// Login   <camill_n@epitech.net>
//
// Started on  Sat Oct 11 15:41:48 2014 camill_n
// Last update Sat Oct 11 23:19:39 2014 camill_n
//

#include <iostream>
#include <ios>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "../../include/global.hpp"

using namespace std;

void 	ConfigController::SetToken(string *token)
{
  this->token = token;
}

string 	*ConfigController::GetToken()
{
  return (this->token);
}

void 	ConfigController::SetAddAPI(string *addr)
{
  this->addAPI = addr;
}

string 	*ConfigController::GetAddAPI()
{
  return (this->addAPI);
}

void 	ConfigController::SetGetAPI(string *addr)
{
  this->getAPI = addr;
}

string 	*ConfigController::GetGetAPI()
{
  return (this->getAPI);
}

void 	ConfigController::SetsetAPI(string *addr)
{
  this->setAPI = addr;
}

string 	*ConfigController::GetsetAPI()
{
  return (this->setAPI);
}

int Split(vector<string>& vecteur, string chaine, char sep)
{
  vecteur.clear();

  string::size_type stTemp = chaine.find(sep);

  while(stTemp != string::npos)
    {
      vecteur.push_back(chaine.substr(0, stTemp));
      chaine = chaine.substr(stTemp + 1);
      stTemp = chaine.find(sep);
    }

  vecteur.push_back(chaine);

  return vecteur.size();
}

string	*ConfigController::GetDataInFile(string *fileName, string *dataName)
{
  ifstream		file(fileName->data());
  string		buffer;
  vector<string>	splitLine;
  int			nbSplit;

  if (file)
    {
      while (getline(file, buffer) != NULL)
      	{
      	  nbSplit = Split(splitLine, buffer, ',');
      	  if (nbSplit >= 2 && dataName->compare(splitLine[0]) == 0)
      	    {
      	      return (new string(splitLine[1]));
      	    }
      	}
      file.close();
    }
  return (NULL);
}

void	ConfigController::SetDataInFile(string *fileName, string *dataName, string *dataValue)
{
  ofstream		file(fileName->data());

  if (file)
    {
      file << dataName->data() << "," << dataValue->data() << endl;
      file.close();
    }
}

ConfigController::ConfigController(NetworkController *network)
{
  string *token;

  token = this->GetDataInFile(new string(".token"), new string("token"));

  //TODO: CONFIG API ADDR
  this->addAPI = new string("http://77.194.204.33:11080/PPM/index.php/API/add_new_client/");
  this->getAPI = new string("http://77.194.204.33:11080/PPM/index.php/API/send_info_server/");
  if (token)
    {
      this->token = token;
    }
  else
    {
      this->token = network->GenerateNewToken(this->addAPI);
      this->SetDataInFile(new string(".token"), new string("token"), this->token);
    }

  if (!this->token)
    {
      cout << "Token server Down and any configuration in .token" << endl;
      exit(EXIT_FAILURE);
    }
  else
    cout << this->token->data() << endl;
}
