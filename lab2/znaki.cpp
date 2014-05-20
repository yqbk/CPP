/**
* \file aghMatrixImplem.h
* \authors Jakub Syrek & Katarzyna Żukowska
* \date 19.05.2014
* \version 1.0
* \brief Plik cpp znaki
*/

#include "aghInclude.h"

// ---------------------------------------------------------
string dodajZnaki(const char* L, const char* P) 
{
   string strL(L);
   string strR(P);
   string strAll = strL + strR;
   string strResult;
   for(unsigned int i=0; i < strAll.length(); i++)
   {
        if(strResult.find_first_of(strAll[i]) == string::npos)
        {
            strResult += strAll[i];
        }
        strResult.c_str();
   }
   return strResult;
}

    

// ---------------------------------------------------------
string mnozZnaki(const char* L, const char* P) 
{
    string strL(L);
    string strR(P);
    string strResult;
    for(unsigned int i=0; i < strL.length(); i++)
    {
        size_t found = strR.find_first_of(strL[i]);
        if (found != string::npos && string::npos == strResult.find_first_of(strL[i]))
        {
            strResult += strL[i];
        }
    }
    return strResult;
}

// ---------------------------------------------------------
// ---------------------------------------------------------