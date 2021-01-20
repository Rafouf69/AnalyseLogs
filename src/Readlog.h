/*************************************************************************
                           ${file_base}  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <${file_base}> (fichier ${file_name}) ------
#if !defined(READLOG_H)
#define READLOG_H

//--------------------------------------------------- Interfaces utilis�es
#include <iostream>
#include <string>
#include "Stats.h" 
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <${file_base}>
//
//
//------------------------------------------------------------------------

class Readlog
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- M�thodes publiques
    void parseFile();

    //------------------------------------------------- Surcharge d'op�rateurs

    //-------------------------------------------- Constructeurs - destructeur

    Readlog(string log_filename, bool filtreH, int hour, bool filtreImg, string graphName);
    // Mode d'emploi :
    //Seul et unique constructeur de Readlog
    // Contrat :
    //

    virtual ~Readlog();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- M�thodes prot�g�es

    //-------------------------------------------------------Attributs protégés
    string log_filename;
    bool filtreH;
    int hour;
    bool filtreImg;
    Stats nosStats;
    string graphName;
};

#endif // READLOG_H
