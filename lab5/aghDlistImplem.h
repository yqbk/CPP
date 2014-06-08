
#ifndef AGHDLISTIMPLEM_H
#define AGHDLISTIMPLEM_H

template<class T>
aghDlist<T>::aghDlist()
{
    this->iSize = 0;
    this->ptrRoot = NULL;
    this->ptrEnd = NULL;
}
template<class T>
aghDlist<T>::aghDlist(aghContainer<T> & element)
{
    this->iSize = 0;
    this->ptrRoot = NULL;
    this->ptrEnd = NULL;

    this->aghContainer<T>::operator =(element);
}

template<class T>
aghDlist<T>::~aghDlist()
{
   if(!this->isEmpty())
      this->clear();

    this->iSize = 0;
    this->ptrRoot = NULL;
    this->ptrEnd = NULL;

}

 template<class T>
 bool aghDlist<T>::insert(int index, T const & element)
 {
     if (index < 0 || index > this->size())
     {
         return false;
     }
     aghDnode<T>* newElement = new aghDnode<T>(element);
     if (this->ptrRoot == NULL)
     {
        this->ptrRoot = newElement;
        this->ptrEnd = newElement;
     }
     if (index == 0)
     {
         newElement->setNext(this->ptrRoot);
         this->ptrRoot->setPrev(newElement);
         this->ptrRoot = newElement;
     }
     else
     if (index == size())
     {
         newElement->setPrev(this->ptrEnd);
         this->ptrEnd->setNext(newElement);
         this->ptrEnd = newElement;
     }
     else
     {
         aghDnode<T>* aktualny = this->ptrRoot;
         for (int i = 0; i < index; i++)
         {
             aktualny = aktualny->getNext();
         }
         newElement->setPrev(aktualny->getPrev());
         newElement->setNext(aktualny);
         newElement->getPrev()->setNext(newElement);
         aktualny->setPrev(newElement);
     }
     this->iSize++;
     return true;
}


template<class T>
T& aghDlist<T>::at(int index) const
{
    if(index < 0 || index >= this->size())
    {
        throw aghException(0, "out of range", __FILE__, __LINE__);
    }

    aghDnode<T>* tmp = this->ptrRoot;
    for(int i=0; i < index; i++)
    {
        tmp = tmp->getNext();
    }
    return tmp->getData();
}

template<class T>
int aghDlist<T>::size(void) const
{
    return this->iSize;
}

template<class T>
bool aghDlist<T>::remove(int index)
{
    if (index < 0 || index >= this->size())
    {
        return false;
    }
    if (index == 0)
    {
        aghDnode<T>* aktualny = this->ptrRoot;
        this->ptrRoot = aktualny->getNext();
        delete aktualny;
    }
    else
    {
        aghDnode<T>* aktualny = this->ptrRoot;
        for (int i = 0; i < index - 1; i++)
        {
            aktualny = aktualny->getNext();
        }
        aghDnode<T>* doUsuniecia = aktualny;
        doUsuniecia = doUsuniecia->getNext();
        aktualny->setNext(doUsuniecia->getNext());
        aktualny->setPrev(doUsuniecia->getPrev());
        delete doUsuniecia;
    }
    this->iSize--;
    return true;
}

template<class T> aghDlist<T>& aghDlist<T>::operator=(aghDlist<T> const & right) {
   this->aghContainer<T>::operator=(right);
   return *this;
}

#endif