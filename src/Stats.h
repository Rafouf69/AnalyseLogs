/*************************************************************************
                           Stats  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Stats> (fichier Stats.h) ----------------
#if ! defined ( Stats_H )
#define Stats_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <iostream>
#include <string> 
using namespace std;
//------------------------------------------------------------- Constantes


//------------------------------------------------------------------ Types  


//------------------------------------------------------------------------
// Rôle de la classe <Stats>
//
//
//------------------------------------------------------------------------

class Stats 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void generateDot(string fileName);

    void generateClassement();

    void addGraphe(string siteCible, string siteReferent);

    void addOccurence(string siteCible);
//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    Stats();
    // Constructeur

    ~Stats();
    // Destructeur 
//------------------------------------------------------------------ PRIVE

protected:

  
  
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

    // double map permettant de stocker le graphe, la première clé est la cible, la deuxième clé est le référent
    map<string, map<string, int>> graphe;

    // map contenant les les sites et leur nombre d'occurence, la clé est la cible
    map<string, int> nbrOcurrence;

    // multimap contenant le classement des sites en fonction de leur nombre d'occurence, la clé est le nombre d'occurence
    multimap<int, string> classement;
};

//-------------------------------- Autres définitions dépendantes de <Stats>

#endif // Stats_H

