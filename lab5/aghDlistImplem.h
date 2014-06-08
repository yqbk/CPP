
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
        throw aghException(0, "Niepoprawny index", __FILE__, __LINE__);             ///Poza indexem

    else
    {
        aghDnode<T>* newElement = new aghDnode<T>(element);
        
        if (this->ptrRoot == NULL)                                                  ///Nowa lista
        {
            this->ptrRoot = newElement;
            this->ptrEnd = newElement;
        }

        if (index == 0)                                                             ///Dodaj na poczatku
        {
            newElement->setNext(this->ptrRoot);
            this->ptrRoot->setPrev(newElement);
            this->ptrRoot = newElement;             //??
        }
        else
        if (index == size())                                                        ///Dodaj na koncu
        {
            newElement->setPrev(this->ptrEnd);
            this->ptrEnd->setNext(newElement);
            this->ptrEnd = newElement;
        }
        else                                                                        ///Dodaj w srodku
        {
            aghDnode<T>* aktualny = this->ptrRoot;

            for (int i = 0; i < index; i++)            
                aktualny = aktualny->getNext();            

            newElement->setPrev(aktualny->getPrev());
            newElement->setNext(aktualny);
            newElement->getPrev()->setNext(newElement);
            aktualny->setPrev(newElement);
        }
        this->iSize++;
        return true;
    }

}

template<class T>
T& aghDlist<T>::at(int index) const
{
    if (index < 0 || index > this->size())
        throw aghException(0, "Niepoprawny index", __FILE__, __LINE__);

    else
    {
        aghDnode<T>* temp = this->ptrRoot;
        
        for(int i=0; i < index; i++)        
            temp = temp->getNext();
        
        return temp->getData();
    }

}

template<class T>
int aghDlist<T>::size(void) const
{
    return this->iSize;
}

template<class T>
bool aghDlist<T>::remove(int index)
{
    if (index < 0 || index >= this->size())                     ///Poza indexem   
        return false;
    
    if (index == 0)                                             ///Usun z poczatku
    {
        aghDnode<T>* aktualny = this->ptrRoot;
        this->ptrRoot = aktualny->getNext();
        delete aktualny;
    }
    else
    if (index == size())                                        ///Usun z konca
    {
        aghDnode<T>* aktualny = this->ptrEnd;
        this->ptrEnd = aktualny->getPrev();
        delete aktualny;
    }
    else                                                        ///Usun ze srodka
    {
        aghDnode<T>* aktualny = this->ptrRoot;

        for (int i = 0; i < index - 1; i++)        
            aktualny = aktualny->getNext();
        
        aghDnode<T>* doUsuniecia = aktualny;

        doUsuniecia = doUsuniecia->getNext();
        aktualny->setNext(doUsuniecia->getNext());
        aktualny->setPrev(doUsuniecia->getPrev());

        delete doUsuniecia;
        /*
        aghDnode<T>* doUsuniecia = this->ptrRoot;

        for (int i = 0; i < index; i++)        
            doUsuniecia = doUsuniecia->getNext();

        doUsuniecia->getPrev()->setNext(doUsuniecia->getNext());
        doUsuniecia->getNext()->setPrev(doUsuniecia->getPrev());

        delete doUsuniecia;
        */

    }
    this->iSize--;
    return true;
}

template<class T> 
aghDlist<T>& aghDlist<T>::operator=(aghDlist<T> const & element) 
{
   this->aghContainer<T>::operator=(element);
   return *this;
}

#endif