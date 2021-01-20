/*************************************************************************
                           Analog  -  description
                             -------------------
    début                : 08/02/2021
    copyright            : (C) 2019 par Raphael vignon et Louis LOMBARD
*************************************************************************/

//---------- Réalisation du module <Analog> (fichier Analog.cpp) ------------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;
//------------------------------------------------------ Include personnel

/* A rahuter ReadLog.h et Graph.h */
//------------------------------------------------------------- Constantes
#define EXIT_SUCCESS 0
#define MISSING_LOG_ARG 1
#define BAD_ARG_LOG_NOT_FOUND 2
#define BAD_ARG_HOUR 3
#define NO_ARG_HOUR 7
#define INVALID_COMMAND 100
//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
bool nextArgCorrect(int index, int size, char** args, string extension = "")
{
    if(index+1 < size-1)
    {
        if(args[index+1][0] != '-')
        {
            string s = args[index+1];
            if(s.find(extension) != string::npos)
                return true;
        }
    }
    return false;
}//-------Fin de nextArgCorrect

int main(int argc, char* argv[])
{  
        string log_fileName =  "";
        bool makegraph=false;
        int filtreH=99;
        bool filtreImg=false;
        string graphName="";

       /*  ReadLog mainreader; */

        

    for(int i = 1; i < argc; i++)
    {
        if(argv[i][0] == '-')
        {
            switch (argv[i][1])
            {
                case 'g':
                    makegraph = true;
                    if(nextArgCorrect(i, argc, argv, ".dot"))
                    {
                        graphName = argv[++i]; //nom correct
                    }
                    else
                    {
                        if(nextArgCorrect(i, argc, argv))
                        {
                            graphName = string(argv[++i]) + ".dot"; //Rajouter extension
                        }
                        else
                        {
                            graphName = "out.dot"; //nom par defaut
                        }
                    }
                    cout << "- Generate Dot-file of the graph : " << graphName << endl;
                    break;

                case 'e':
                    filtreImg = true;
                    cout << "- Do not considere css, js, jpeg" << endl;
                    break;

                case 't':
                    if(nextArgCorrect(i, argc, argv))
                    {
                        int tmp = atoi(argv[++i]);
                        if (tmp >= 0 && tmp < 24)
                        {
                            filtreH = tmp;
                        }
                        else
                        {
                            cerr << "Error : Hour must be an integer between 0 and 23" << endl;
                            return BAD_ARG_HOUR;
                        }
                    }
                    else{
                        cerr << "Error : No hour specified" << endl;
                        return NO_ARG_HOUR;
                    }
                    cout << "- Filtering log between " << filtreH << "h and " << filtreH + 1 << "h" << endl;
                    break;
                default:
                    cerr << "Error : Invalid command" << endl;
                    cout << "- Use ./analog -h for help" << endl;
                    return INVALID_COMMAND;
                    break;
                    
            }
        }
        else
        {
            log_fileName = argv[i];
            ifstream file(log_fileName.c_str());
            if(!file.is_open())
            {
                cerr << "Error : Log file " << log_fileName << " not found" << endl;
                return BAD_ARG_LOG_NOT_FOUND;
            }
        }
    }
    
    if(log_fileName == "")
    {
        cerr << "Error : Missing file to analyze" << endl;
        return MISSING_LOG_ARG;
    }

    cout<<log_fileName<< endl <<filtreH<< endl<<filtreImg<< endl<<graphName<< endl;
    /* Readlog(log_fileName,filtreH,filtreImg,Mygraph), */ // a decommenter en temps voulu





    return 0;
}//-------Fin de main
