#ifndef AGHDNODEIMPELM_H
#define AGHDNODEIMPELM_H

template<class T>
aghDnode<T>::aghDnode()
{
    this->ptrNext = NULL;
    this->ptrPrev = NULL;
}

template<class T>
aghDnode<T>::aghDnode(T data)
{
    this->data = data;
    this->ptrNext = NULL;
    this->ptrPrev = NULL;
}

template<class T>
aghDnode<T>::~aghDnode()
{

}

template<class T>
aghDnode<T>* aghDnode<T>::getNext() const
{
     return this->ptrNext;
}

template<class T>
aghDnode<T>* aghDnode<T>::getPrev() const
{
    return this->ptrPrev;
}

template<class T>
void aghDnode<T>::setNext(aghDnode<T>* ptrNext)
{
    this->ptrNext = ptrNext;
}

template<class T>
void aghDnode<T>::setPrev(aghDnode<T>* ptrPrev)
{
    this->ptrPrev = ptrPrev;
}

#endif