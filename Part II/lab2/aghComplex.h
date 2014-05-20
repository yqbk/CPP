/**
* \file aghComplex.h
* \authors Jakub Syrek & Katarzyna Żukowska
* \date 19.05.2014
* \version 1.0
* \brief Plik nagłówkowy z deklaracją klasy liczb urojonych
*/

#ifndef AGHCOMPLEX_H
#define AGHCOMPLEX_H

// ---------------------------------------------------------
// ---------------------------------------------------------
/**
* \class aghComplex
* \authors Jakub Syrek & Katarzyna Żukowska
* \date 19.05.2014
* \brief Klasa liczb urojonych
*/

class aghComplex
{

    private:
            
        double re;
        double im;

     public:

        /**
         * @brief Konstruktor bezparametrowy
         */
        aghComplex();

        /**
         * @brief Konstruktor parametrowy
         * @param re - część rzeczywista liczby
         * @param im - część urojona liczby
         */
        aghComplex(double re, double im);

        /**
         * @brief Destruktor
         */
        virtual ~aghComplex();

// ---------------------------------------------------------

        /**
         * @brief Przeciążony operator dodawania
         * @param macierz - macierz którą dodajemy
         */
        const aghComplex operator+(aghComplex const & macierz);

        /**
         * @brief Przeciążony operator mnożenia
         * @param macierz - macierz którą mnożymy
         */
        const aghComplex operator*(aghComplex const & macierz);

        /**
         * @brief Przeciążony operator +=
         * @param macierz - macierz o którą powiększamy
         */
        aghComplex const & operator+=(aghComplex const & macierz);

        /**
         * @brief Przeciążony operator przyrównania
         * @param macierz - macierz którą porównujemy
         */
        bool operator==(aghComplex const & macierz);

        /**
         * @brief Przeciążony operator !=
         * @param macierz - macierz do której sprawdzamy podobnieństwo
         */
        bool operator!=(aghComplex const & macierz);


};

// ---------------------------------------------------------
// ---------------------------------------------------------
#endif