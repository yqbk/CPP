#ifndef AGHTREEIMPLEM_H
#define AGHTREEIMPLEM_H

template<class T>
aghTree<T>::aghTree()
{
    this->wskKorzen = NULL;
    this->iRozmiar = 0;
}

template<class T>
aghTree<T>::aghTree(aghContainer<T> & kopia)
{
    this->wskKorzen = NULL;
    this->iRozmiar = 0;
    //aghContainer<T>* kopia = new
}

template<class T>
aghTree<T>::~aghTree()
{
    //dtor
}

template<class T>
void aghTree<T>::setKorzen(aghTreeNode<T>* wskKorzen)
{
    this->wskKorzen = wskKorzen;
}

template<class T>
void aghTree<T>::setRozmiar(unsigned int iRozmiar)
{
    this->iRozmiar = iRozmiar;
}

template<class T>
aghTreeNode<T>* aghTree<T>::getKorzen()
{
    return this->wskKorzen;
}

template<class T>
bool aghTree<T>::insert(int index, T const & element)
{
    if (this->wskKorzen == NULL)
    {
        aghTreeNode<T>* nowy = new aghTreeNode<T>;
        nowy->setDane(element);
        this->setKorzen(nowy);
    }
    else
    {
        aghTreeNode<T>* przejscie = this->wskKorzen;
        bool czyZnaleziono = false;
        while (!czyZnaleziono)
        {
            if (przejscie->getDane() <= element)
            {
                if (przejscie->getLewy() != NULL)
                {
                    przejscie = przejscie->getLewy();
                }
                else
                {
                    aghTreeNode<T>* nowy = new aghTreeNode<T>;
                    nowy->setDane(element);
                    przejscie->setLewy(nowy);
                    nowy->setPoprzedni(przejscie);
                    czyZnaleziono = true;
                }
            }
            else
            {
                if (przejscie->getPrawy() != NULL)
                {
                    przejscie = przejscie->getPrawy();
                }
                else
                {
                    aghTreeNode<T>* nowy = new aghTreeNode<T>;
                    nowy->setDane(element);
                    przejscie->setPrawy(nowy);
                    nowy->setPoprzedni(przejscie);
                    czyZnaleziono = true;
                }
            }

        }
    }
}

template<class T>
void aghTree<T>::przejdz(aghTreeNode<T>* node)
{
    if (node != NULL)
    {
        if (node->getLewy() != NULL)
        {
            przejdz(node->getLewy());
        }
        cout << node->getDane() << endl;
        if (node->getPrawy() != NULL)
        {
            przejdz(node->getPrawy());
        }
    }
}

template<class T>
T& aghTree<T>::at(int) const
{

}



template<class T>
int aghTree<T>::size(void) const
{
    return this->iRozmiar;
}

template<class T>
bool aghTree<T>::remove(int index)
{

}

#endif // AGHTREEIMPLEM_H


