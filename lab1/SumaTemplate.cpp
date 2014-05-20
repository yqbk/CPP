/**
* \file SumaTemplate.cpp
* \authors Jakub Syrek & Katarzyna Żukowska
* \date 11.05.2014
* \version 1.0
* \brief Specjalizowany szablon funkcji
*/

// ---------------------------------------------------------
#include "SumaTemplate.h"
#include <string>

// ---------------------------------------------------------
/// \brief szablon funkcji specjalizowanej dla ciągów znakowych
/// \param elementy - tablica zawierająca elementy typu char*
/// \param iDlugosc - ilość elementów/słów

template <> double suma <char**> (char** elementy, int iDlugosc)		
{
    string wynik = "";										/*!< wynik - połączone słowa formatu string */ 

    for (int i = 0; i < iDlugosc - 1; i++)					/// \brief pętla gdzie dodajemy pojedyńcze słowa do wyniku i wypisujemy je na ekran
    {														/*!< i - iterator */
        cout << elementy[i] << " + ";
        wynik += elementy[i];								
    }

    wynik += elementy[iDlugosc - 1];
    cout << elementy[iDlugosc - 1] << " = " 
    << wynik << "(" << wynik.length() <<")" << endl;	   /// \brief wypisujemy całe zdanie oraz długość liter 
    
    return wynik.length();								   /// \return zwracamy długość ciągu znakowego
}
// ---------------------------------------------------------