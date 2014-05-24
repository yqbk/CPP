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


class Generator
{
    protected:

        int iPoczatek;
        int iKoniec; 
        int seed;
        string strNazwaGeneratora;
        int iWylosowana;  


    public:

        Generator();

        Generator(int iPoczatek, int iKoniec, string strNazwaGeneratora);

        virtual ~Generator();



        virtual void losuj() = 0;  //czysto wirtualna metoda

        //virtual void generate();

        //virtual void setSeed(int);



        void setPoczatek(int iPoczatek);

        void setKoniec(int iKoniec);

        void setNazwa(string strNazwaGeneratora);

        int getPoczatek();

        int getKoniec();

        int getSeed();

        int getWylosowana();

        string getNazwa();





        void nazwa(ostream & = cout) const;

        void print(ostream & = cout);

        


};

// ---------------------------------------------------------
#endif
