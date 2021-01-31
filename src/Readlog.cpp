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
    regex extension("^.*\\.(jpg|JPG|gif|png|GIF|js|css|ico)$");
    regex hourtype("\\[(.*)\\]");;;
    regex patternDEST("( /([^ ]+)?)"); //paternderecherchedeDestination
    while(getline(logFile,line)){
        auto words_begin = sregex_iterator(line.begin(), line.end(), words_regex);
        auto words_end = sregex_iterator();
        //cout << "Found " << distance(words_begin, words_end) << " words:\n"; //Prouver 3 mot entre paretnhese à chaque fois
        auto hour_begin = sregex_iterator(line.begin(), line.end(), hourtype);
        auto hour_end = sregex_iterator();
        //cout << "Found " << distance(words_begin, words_end) << " words:\n"; //Prouver 1 seul heure entre crochet à chaque fois
        
        //traitement heure
        if(filtreH)
        {
           sregex_iterator o = hour_begin; 
           string hourcompare = (*o).str(); 
           hourcompare.replace(0,13,"");
           hourcompare.replace(2,hourcompare.length(),"");
           int hourtocompare= stoi(hourcompare);
           //cout<<hourcompare<<endl;
           if (hourtocompare!=hour)
           {
               continue;
           }
        }
        //traitement de la destination
        
        sregex_iterator i = words_begin;                                                
        string dest = (*i).str(); 
        dest.replace(dest.length()-1,dest.length(),"");
        dest.replace(0,1,"");
        smatch match;
        regex_search(dest, match, patternDEST);
        dest=match[0];
        dest.replace(0,1,"");
        //cout<<"dest="<<dest<<endl;
        dest= "http://intranet-if.insa-lyon.fr"+dest;//forme finale de la dest (à améliorer dynamiqument)
        
        if(filtreImg)
        {
            if(regex_match(dest, extension))
            {
                // cout<<"non pris en compte"<<endl;
                continue;
            }
        }
        
       
        i++;
        

        //traitement de la source 
        string src = (*i).str(); 
        src.replace(src.length()-1,src.length(),"");
        src.replace(0,1,""); //forme finale de la source
        
        int count=0;
        int n = src.length();
        char char_array[n + 1];

        for (int i = 0; i < n+1; i++)
        {
            if (src[i]=='/')
            {
                count++;
            }
           
            if (count==3)
            {
                break;
            }
            //cout<<src[i]<<endl;
            char_array[i] = src[i];
            //cout<<char_array[i]<<endl;
           
        }
        string sfinal(char_array);
       
        //cout<<"sfinal "<<sfinal<<endl;
        //dest=sfinal+dest;
        //cout<<dest<<endl<<src<<endl;
        myStats.addGraphe(dest,src);
        myStats.addOccurence(dest);


        //cout<<dest<<endl; // a commenter
        //cout<<src<<endl; 
    }
    myStats.generateClassement();
    if (graph)
    {
        myStats.generateDot(graphName);
    }
        
       
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Readlog::Readlog(string log_filename, bool filtreH, int hour, bool filtreImg ,bool graph, string graphName)
{
    this->log_filename=log_filename;
    this->filtreH=filtreH;
    this->hour=hour;
    this->filtreImg=filtreImg;
    this->graphName=graphName;
    this->graph=graph;
}

Readlog::~Readlog() {

  
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
