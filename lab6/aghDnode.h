/**
* \file aghDnode.h
* \authors Jakub Syrek & Katarzyna Zukowska
* \date 09.06.2014
* \version 1.0
* \brief Plik naglowkowy z deklarajca klasy aghDnode diedziczacej po klasie aghSnode
*/
#ifndef AGHDNODE_H
#define AGHDNODE_H

/**
* \class aghDnode
* \authors Jakub Syrek & Katarzyna ¯ukowska
* \date 09.06.2014
* \brief Szablon klasa aghDnode dziedzicz¹cej po klasie aghSnode
*/
template<class T>
class aghDnode : public aghSnode<T>
{
    private:

       aghDnode<T>* ptrNext;  ///< Nastepny element
       aghDnode<T>* ptrPrev;  ///< Poprzedni element

    public:

        /**
        * @brief Konstruktor
        **/
        aghDnode();

       /**
       * @brief Konstruktor parametrowy
       * @param data
       * @param poprzedni - poprzedni
       * @param nastepny - nastepny
       */
        aghDnode(T data, aghDnode* = NULL, aghDnode* = NULL );

        /**
        * @brief Destruktor
        **/
        ~aghDnode();

        /**
        * @brief Wskaznik na nastepny element listy
        * @return Nastepny element
        */
        aghDnode<T>* getNext() const;  
        /**
        * @brief Wskaznik na poprzedni element listy
        * @return Poprzedni element
        */
        aghDnode<T>* getPrev() const;

       /**
       * @brief Metoda ustawiajaca wskaznik ptrNext
       * @param ptrNext
       * @return Nic nie zwraca
       */
        void setNext(aghDnode<T>* ptrNext);

       /**
       * @brief Metoda ustawiajaca wskaznik ptrPrev
       * @param ptrPrev
       * @return Nic nie zwraca
       */
        void setPrev(aghDnode<T>* ptrPrev);

};

#endif