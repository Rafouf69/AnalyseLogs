/*************************************************************************
                           Stats  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Stats> (fichier Stats.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <map>
#include <iostream>
#include <string> 
#include <fstream>

//------------------------------------------------------ Include personnel
#include "Stats.h" 
using namespace std;
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Stats::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void Stats::generateDot(string fileName)
{
  int size=classement.size();
  ofstream Myoutput (fileName);
	streambuf *oldCoutBuffer = cout.rdbuf ( Myoutput.rdbuf ( ) );
  cout<<"digraph {\n";
  int i=0;
  multimap<int , string>::reverse_iterator rit=classement.rbegin();
  string s;
  string tablstring[10];
  while(i<10 && rit!=classement.rend())
  {
    tablstring[i]=rit->second;
    
    s= "node" +to_string(i)+ " [label=\"" +rit->second+"\"];";
    cout<<s<<endl;
    ++rit;
    ++i;
  } 
  int nb=0;
  while(nb<10)
  {
    i=0;
    rit=classement.rbegin();
    while(i<10 && rit!=classement.rend())
    {
      if ( graphe[tablstring[nb]][tablstring[i]]!=0)
      { 
        s= "node" +to_string(nb)+ " -> " +"node" +to_string(i)+" [label=\""+to_string(graphe[tablstring[nb]][tablstring[i]])+"\"];";
        cout<<s<<endl;
      }
      ++rit;
      ++i;
    } 
    nb++;
  }
  cout<<"}";
  
  cout.rdbuf ( oldCoutBuffer );
	Myoutput.close();

} 

void Stats::generateClassement()
{
  for(map<string,int>::iterator it=nbrOcurrence.begin(); it!=nbrOcurrence.end(); ++it)
  {
    classement.insert(pair<int, string>(it->second,it->first));
  } 
  int i=0;
  multimap<int , string>::reverse_iterator rit=classement.rbegin();
  while(i<10 && rit!=classement.rend())
  {
    cout << rit->second << " (" << rit->first << " hits)"<<endl;
    ++rit;
    ++i;
  } 
}
void Stats::dataTreatment(bool dot, string dotname, bool filterImg, bool filterHour, int hour)
{
    if (dot)
    {
      generateDot(dotname);
    }
    if (filterImg)
    {
      generateDot(dotname);
    }
}

multimap<int, string>& Stats::getClassement(){
  return classement;
}

void Stats::addGraphe(string siteCible, string siteReferent)
{
  graphe[siteCible][siteReferent]+=1;  //as soon as we access with the []operator, default value are 0
}

void Stats::addOccurence(string siteCible)
{
  nbrOcurrence[siteCible]+=1; 
} 
//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur
Stats::Stats(){
  
} 

Stats::~Stats(){

}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
