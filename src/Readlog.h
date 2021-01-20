/*************************************************************************
                           ${file_base}  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <${file_base}> (fichier ${file_name}) ------
#if ! defined ( READLOG_H )
#define READLOG_H


//--------------------------------------------------- Interfaces utilis�es
#include <iostream>
#include <string>

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


//------------------------------------------------- Surcharge d'op�rateurs
 

//-------------------------------------------- Constructeurs - destructeur
 
    Readlog (string log_filename,bool filtreH, int hour,bool filtreImg,string graphname );
    // Mode d'emploi :
    //Seul et unique constructeur de Readlog
    // Contrat :
    //

    virtual ~Readlog ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- M�thodes prot�g�es
    string log_filename;
    bool filtreH;
    int hour;
    bool filtreImg;
    string graphname;
//-------------------------------------------------------Attributs protégés   
};

#endif // READLOG_H
