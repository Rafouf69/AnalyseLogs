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
#include <fstream> 
#include <regex>
//------------------------------------------------------ Include personnel
#include "Readlog.h"
#include "Stats.h"
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------- Fonctions
string findwrd(string const &s, regex const &r) { 
    smatch match;
    regex_search(s, match, r);
    return match[0];
}

void differenceCaractere(string line, int pos, const string carac)
{
    int diff=0;
    while(line.substr(pos+diff, 1)!=carac);

} 
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
    logFile.open(log_filename);
    string line;
    regex patternDEST("( /([^ ]+)?)"); //paternderecherchedeDestination
    regex patternSRC("(\"http://intranet-if.insa-lyon.fr([^ ]+)?)");//paternderecherchedeorigine
    while(getline(logFile,line)){
        
        string dest=findwrd(line, patternDEST);
        dest.replace(0,1,""); //enlever l'espace présent au début
        
        string sec=findwrd(line, patternSRC); 
        sec.replace(0,32,""); //enlever les 32 premier caractère (lié à la longueuur du patternSRC)
        sec.replace(sec.length()-1,sec.length(),""); // enlever la dernière parenthese
        
        cout<<dest<<endl; // a commenter
        cout<<sec<<endl;
    }
        
       
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

Readlog::~Readlog() {

  
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
