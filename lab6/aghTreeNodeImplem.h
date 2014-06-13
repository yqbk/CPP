#ifndef AGHTREENODEIMPLEM_H
#define AGHTREENODEIMPLEM_H

template<class T>
aghTreeNode<T>::aghTreeNode()
{
    this->wskPoprzedni = NULL;
    this->wskPrawy = NULL;
    this->wskLewy = NULL;
}

template<class T>
aghTreeNode<T>::~aghTreeNode()
{
    //dtor
}

template<class T>
void aghTreeNode<T>::setDane(T dane)
{
    this->dane = dane;
}

template<class T>
void aghTreeNode<T>::setPrawy(aghTreeNode<T>* wskPrawy)
{
    this->wskPrawy = wskPrawy;
}

template<class T>
void aghTreeNode<T>::setLewy(aghTreeNode<T>* wskLewy)
{
    this->wskLewy = wskLewy;
}

template<class T>
void aghTreeNode<T>::setPoprzedni(aghTreeNode<T>* wskPoprzedni)
{
    this->wskPoprzedni = wskPoprzedni;
}

template<class T>
aghTreeNode<T>* aghTreeNode<T>::getPrawy()
{
    return this->wskPrawy;
}

template<class T>
aghTreeNode<T>* aghTreeNode<T>::getLewy()
{
    return this->wskLewy;
}

template<class T>
aghTreeNode<T>* aghTreeNode<T>::getPoprzedni()
{
    return this->wskPoprzedni;
}

template<class T>
T aghTreeNode<T>::getDane()
{
    return this->dane;
}



#endif // AGHTREENODEIMPLEM_H

