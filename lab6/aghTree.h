#ifndef AGHTREE_H
#define AGHTREE_H

template<class T>
class aghTree : public aghContainer<T>
{
    public:
        aghTree();
        aghTree(aghContainer<T> & kopia);
        ~aghTree();
        void setKorzen(aghTreeNode<T>* wskKorzen);
        aghTreeNode<T>* getKorzen();
        void przejdz(aghTreeNode<T>* node); //nadaje indexy
        void setRozmiar(unsigned int iRozmiar);
        /**
       * @brief Metoda virtualna która "wklada" element do pojemnika
       * @param index - index
       * @param element - wrzucany element
       * @return Wartosc logiczna
       */
        bool insert(int index, T const & element);

       /**
       * @brief Metoda virtualna która pobiera element z pojemnika
       * @param index - index
       * @return Pobrany element
       */
      	T& at(int) const;

       /**
       * @brief Metoda virtualna która zwraca ilosc elementow
       * @return Liczba elementow
       */
       int size(void) const;

       /**
       * @brief Metoda virtualna która usuwa element
       * @param index - index
       * @return Wartosc logiczna
       */
       bool remove(int index);
    protected:
    private:
        aghTreeNode<T>* wskKorzen;
        unsigned int iRozmiar;

};

#endif // AGHTREE_H
