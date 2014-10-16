//
// config.cpp for ppm in /home/camill_n/pinkponymonitoring/client
//
// Made by camill_n
// Login   <camill_n@epitech.net>
//
// Started on  Sat Oct 11 15:41:48 2014 camill_n
// Last update Thu Oct 16 23:05:59 2014 camill_n
//

#include <iostream>
#include <ios>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "../../include/global.hpp"
#include <map>

using namespace std;

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

bool		ConfigController::getAllDataInFile(string fileName, map<string, string> *splitTab)
{
  ifstream		file(fileName.data());
  string		buffer;
  vector<string>	splitLine;
  int			nbSplit;

  if (file)
    {
      while (getline(file, buffer) != NULL)
      	{
      	  nbSplit = Split(splitLine, buffer, '=');
      	  if (nbSplit == 2)
      	    {
	      cout << "   -> " << splitLine[0] << "= "<< splitLine[1] << endl;
	      splitTab->insert(pair<string, string>(splitLine[0],splitLine[1]));
      	    }
      	}
      file.close();
    }
  return (true);
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

bool	ConfigController::ReadConfig()
{
  cout << "- Reading configurations..." << endl;
  cout << "  -> Reading API file (.api)..." << endl;
  this->getAllDataInFile(".api", &this->currentConfig);
  cout << "  -> Reading TOKEN file (.token)..." << endl;
  this->getAllDataInFile(".token", &this->currentConfig);
  return (true);
}

ConfigController::ConfigController(NetworkController *network)
{
  string *token;

  //Read all config for the session
  this->ReadConfig();
  if (!this->getConfig("TOKEN"))
    {
      cout << "- Token unfound... Generating new token..." << endl;
      token = network->GenerateNewToken(this->getConfig("ADD_API"));
      if (token == NULL)
	{
	  cout << "Token server Down and any configuration in .token" << endl;
	  exit(EXIT_FAILURE);
	}
      cout << "  -> Generation ok !" << endl;
      this->currentConfig.insert(pair<string, string>("TOKEN", *token));
    }
}

ConfigController::~ConfigController()
{
}
