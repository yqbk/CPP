/**
* \file SumaTemplate.h
* \authors Jakub Syrek & Katarzyna Żukowska
* \date 11.05.2014
* \version 1.0
* \brief Plik nagłówkowy z szablonem funkcji
*/

// ---------------------------------------------------------
#ifndef SUMA_H
#define SUMA_H

// ---------------------------------------------------------
#include <iostream>
using namespace std;

// ---------------------------------------------------------
/// \brief szablon funkcji sumującej
/// \param elementy - tablica zawierająca elementy
/// \param iDlugosc - ilość elementów

template <class T>											
double suma(T elementy, int iDlugosc)						
{															
    double wynik = 0;										/// \var wynik - suma elementów

    for (int i = 0; i < iDlugosc - 1; i++)					/// \brief dodajemy elementy tablicy w pętli
    {														/// \var i - iterator
        cout << elementy[i] << " + ";
        wynik += elementy[i];
    }

    wynik += elementy[iDlugosc - 1];						/// \brief wyświetlamy wynik
    cout << elementy[iDlugosc - 1] << " = " << wynik << endl;

    return wynik;											/// \return zwracamu sumę elementów
}

// ---------------------------------------------------------
/// \brief deklaracja funkcji specjalizowanej
			
template <> double suma<char**>(char** , int );

// ---------------------------------------------------------
#endif