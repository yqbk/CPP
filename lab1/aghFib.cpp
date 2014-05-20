/**
* \file aghFib.cpp
* \authors Jakub Syrek & Katarzyna Żukowska
* \date 11.05.2014
* \version 1.0
* \brief Plik z opisem klasy i przeciążonym operatorem
*/

// ---------------------------------------------------------
#include "aghFib.h"
#include <iostream>
using namespace std;

// ---------------------------------------------------------
aghFib::aghFib()                        /// \brief Konstruktor bezparametrowy - definicja
{
    
}

// ---------------------------------------------------------
aghFib::~aghFib()                       /// \brief Destruktor - definicja
{
 
}

// ---------------------------------------------------------
/// \brief Przeciążony operator "[]" - definicja
/// \param n - który to element z kolei

double aghFib::operator[](const int n)  
{
    int* fibTab = new int[n+1];         /// \var fibTab - tablica zawierająca elementy ciągu fibbonaciego

    if (n < 2)
    {
        return n;                       /// \return Dla początkowych wyrazów ciągu zwracamy je same
    }
    
    fibTab[0] = 0;                      /// \brief  2 początkowe wartości
    fibTab[1] = 1;

    for (int i = 2; i < n + 1; i++)     /// \brief pętla iteracyjnego ciągu fibbonacciego
    {                                   /*!< i - iterator */
       fibTab[i] = fibTab[i - 1] + fibTab[i - 2];
    }

    int wynik = fibTab[n];              /*!< wynik - szukany element ciągu */ 

    delete []fibTab;                    /// \brief  zwalniana pamięć 
    return wynik;                       /// \return zwracany wynik
}   

// ---------------------------------------------------------