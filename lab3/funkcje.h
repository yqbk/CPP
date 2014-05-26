/**
* \file funkcje.h
* \authors Jakub Syrek & Katarzyna Żukowska
* \date 25.05.2014
* \version 1.0
* \brief Plik nagłówkowy z deklarajcą funkcji pomocniczych
*/


#ifndef FUNKCJE_H
#define FUNKCJE_H

// ---------------------------------------------------------
// ---------------------------------------------------------

#include "Generator.h"		

/**
* @brief Funkcja przeprowadzajaca wszystkie testy
* @param wskGenerator - wskaznik na generator
* @param plik - plik zapisu wynikow
* @return Nic nie zwraca
*/
void multiTesty(Generator *wskGenerator, ostream & plik);

/**
* @brief Funkcja prezentująca generator
* @param wskGenerator - wskaznik na generator
* @param plik - plik zapisu wynikow
* @return Nic nie zwraca
*/
void prezentacjaGeneratora(Generator *wskGenerator, ostream & plik);

/**
* @brief Funkcja ciag fibonacciego
* @return wartosc ntego elementu ciagu
*/
int fib(int); 

// ---------------------------------------------------------
// ---------------------------------------------------------
#endif