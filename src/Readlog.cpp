/*************************************************************************
                           Readlog  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Readlog> (fichier Readlog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "Readlog.h"
#include "Stats.h"
using namespace std;
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Readlog::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void Readlog::parseFile()
{
    ifstream logFile;
    logfile.open(log_filename);
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Readlog::Readlog(string log_filename, bool filtreH, int hour, bool filtreImg , string graphName)
{
    this->log_filename=log_filename;
    this->filtreH=filtreH;
    this->hour=hour;
    this->filtreImg=filtreImg;
    this->graphName=graphName;
}

Readlog::~Readlog() {}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

int main()
{
  return 0;
} 