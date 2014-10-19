//
// config.cpp for ppm in /home/camill_n/pinkponymonitoring/client
//
// Made by camill_n
// Login   <camill_n@epitech.net>
//
// Started on  Sat Oct 11 15:41:48 2014 camill_n
// Last update Sun Oct 19 18:26:39 2014 camill_n
//

#include <ios>
#include <vector>
#include <iostream>
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

bool		ConfigController::getAllDataInFile(string fileName, KernelController *config)
{
  ifstream		file(fileName.data());
  string		buffer;
  vector<string>	splitLine;
  int			nbSplit;

  if (file)
    {
      while (getline(file, buffer) != NULL)
      	{
	  cout << "   -> " << buffer << endl;
	  config->script->currentScript.push_back(buffer);
      	}
      file.close();
    }
  else
    cout << "File unfound: " << fileName << endl;
  return (true);
}

void	ConfigController::SaveData(string fileName, char sep, map<string, string> *splitTab)
{
ofstream		file(fileName.data(), ios::out | ios::trunc);

  if (file)
    {
      for(std::map<string, string>::iterator it=splitTab->begin() ; it!=splitTab->end() ; ++it)
	{
	  file << it->first << sep << it->second << endl;
	}
      file.close();
    }
}

void	ConfigController::SaveData(string fileName, deque<string> *splitTab)
{
ofstream		file(fileName.data(), ios::out | ios::trunc);

  if (file)
    {
      for(std::deque<string>::iterator it=splitTab->begin() ; it!=splitTab->end() ; ++it)
	{
	  file << *it << endl;
	}
      file.close();
    }
}

bool	ConfigController::ReadConfig(KernelController *kernel)
{
  cout << "- Reading configurations..." << endl;
  cout << "  -> Reading config file (.config)..." << endl;
  this->getAllDataInFile(".config", &this->currentConfig);
  cout << "  -> Reading SCRIPTS enable file (.script)..." << endl;
  this->getAllDataInFile(".script", kernel);
  return (true);
}

ConfigController::ConfigController(KernelController *kernel)
{
  string *token;

  //Read all config for the session
  this->ReadConfig(kernel);
  if (!this->getConfig("TOKEN"))
    {
      cout << "- Token unfound... Generating new token..." << endl;
      token = kernel->network->GenerateNewToken(this->getConfig("ADD_API"));
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
