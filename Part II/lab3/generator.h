/**
* \file aghMatrix.h
* \authors Jakub Syrek & Katarzyna Żukowska
* \date 19.05.2014
* \version 1.0
* \brief Plik nagłówkowy z deklarajcą klasy abstrakcyjnej generatora
*/

#ifndef GENERATOR_H
#define GENERATOR_H

// ---------------------------------------------------------
// ---------------------------------------------------------
/**
* \class aghMatrix
* \authors Jakub Syrek & Katarzyna Żukowska
* \date 25.05.2014
* \brief Klasa abstrakcyjna generatora
*/


class generator
{
    protected:

        int count;
        int seed;   //ziarno -> początkowa wartość
        int name;

        int los;    //losowa liczba


    public:

        generator();

        generator(int , int , string);

        virtual ~generator();



        virtual void generate();

        virtual void setSeed(int);


        void nazwa(ostream & = cout) const;

        void print(ostream & = cout) const;

        


};

// ---------------------------------------------------------
#endif


