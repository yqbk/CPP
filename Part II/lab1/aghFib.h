/**
* \file aghFib.h
* \authors Jakub Syrek & Katarzyna Żukowska
* \date 11.05.2014
* \version 1.0
* \brief Plik nagłównkowy zawierający klasę 
*/
// ---------------------------------------------------------
#ifndef AGHFIB_H
#define AGHFIB_H

// ---------------------------------------------------------
/**
* \class aghFib
* \author Jakub Syrek & Katarzyna Żukowska
* \date 11.05.2014
* \brief Klasa ciąg fibbonaciego z przeciążonym operatorem potrzebnym, by urzyć obiektu w szablonie funkcji
*/
class aghFib
{
    public:
        aghFib();			 			/// \brief Konstruktor domyślny klasy - deklaracja
        ~aghFib();   					/// \brief Destruktor klasy - deklaracja         //<---??
        double operator[](const int);	/// \brief Przeciążony operator "[]" - deklaracja //<----??

    protected:
    
    private:
};

// ---------------------------------------------------------
#endif