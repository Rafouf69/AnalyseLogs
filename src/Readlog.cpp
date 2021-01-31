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
    Stats myStats;
    ifstream logFile;
    logFile.open(log_filename);
    string line;
    regex words_regex("\"([^\"]*)\"");
    regex patternDEST("( /([^ ]+)?)"); //paternderecherchedeDestination
    while(getline(logFile,line)){

 
        
        auto words_begin = sregex_iterator(line.begin(), line.end(), words_regex);
        auto words_end = sregex_iterator();
        // cout << "Found " << distance(words_begin, words_end) << " words:\n"; //Prouver 3 mot entre paretnhese à chaque fois
 
        //traitement de la destination
        sregex_iterator i = words_begin;                                                
        string dest = (*i).str(); 
        dest.replace(dest.length()-1,dest.length(),"");
        dest.replace(0,1,"");
        smatch match;
        regex_search(dest, match, patternDEST);
        dest=match[0];
        dest.replace(0,1,"");
        dest= "http://intranet-if.insa-lyon.fr"+dest; //forme finale de la dest


      


        i++;
        //traitement de la source 
        string src = (*i).str(); 
        src.replace(src.length()-1,src.length(),"");
        src.replace(0,1,""); //forme finale de la source
        myStats.addGraphe(dest,src);
        myStats.addOccurence(dest);

        //cout<<dest<<endl; // a commenter
        //cout<<src<<endl; 
    }
    myStats.generateClassement();
        
       
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
