/**
* \file aghSnode.h
* \authors Jakub Syrek & Katarzyna Zukowska
* \date 09.06.2014
* \version 1.0
* \brief Plik naglowkowy z deklarajca szablonu klasy aghSnode
*/

#ifndef AGHSNODE_H
#define AGHSNODE_H

/**
* \class aghSnode
* \authors Jakub Syrek & Katarzyna Zukowska
* \date 09.06.2014
* \brief Szablon klasy aghSnode 
*/
template<class T>
class aghSnode
{

    private:

       aghSnode<T>* ptrNext;    ///< Wskaznik na nastepny element

    protected:

        T data;                 ///< dane / zawartosc elementu

    public:

       /**
       * @brief Konstruktor
       **/
       aghSnode();

       /**
       * @brief Konstruktor parametrowy
       * @param data
       */
        aghSnode(T data, aghSnode* = NULL);

        /**
        * @brief Destruktor
        **/
        ~aghSnode();

       /**
       * @brief Metoda pobierajaca wartosc zmiennej data
       * @return zwraca zmienna data
       */
       T& getData();

        /**
       * @brief Metoda ustawiajaca zmienna data
       * @param data
       * @return nic nie zwraca
       */
        void setData(T data);

       /**
       * @brief Metoda zwracaj¹ca wartosc wskaznika ptrNext
       * @return wartosc wskaznika ptrNext
       */
       aghSnode<T>* getNext() const;

       /**
       * @brief Metoda zwracajaca wartosc wskaznika ptrNext
       * @return wartosc wskaznika ptrNext
       */
       void setNext(aghSnode<T>* ptrNext);

};


#endif
