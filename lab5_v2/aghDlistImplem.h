#ifndef AGHDLISTIMPLEM_H
#define AGHDLISTIMPLEM_H
//------------------------------------------------------------------------
//------------------------------------------------------------------------

template<class T>
aghDlist<T>::aghDlist()
{
    this->ptrRoot = NULL;
    this->ptrEnd = NULL;
}

template<class T>
aghDlist<T>::aghDlist(aghContainer<T> & element)
{
    this->ptrRoot = NULL;
    this->ptrEnd = NULL;

    this->aghContainer<T>::operator =(element);
}

template<class T> 
aghDlist<T>::aghDlist(aghDlist<T> const & element) 
{
    this->ptrRoot = NULL;
    this->ptrEnd = NULL;

   this->aghContainer<T>::operator =(element);
}

template<class T>
aghDlist<T>::~aghDlist()
{
    if(!this->isEmpty())
      this->clear();

    this->ptrRoot = NULL;
    this->ptrEnd = NULL;
}

template<class T>
int aghDlist<T>::size(void) const
{    
   int ileEl = 0;

   aghDnode<T>* aktualny = ptrRoot;
   while(aktualny != NULL) 
   {    
      ileEl++;
      aktualny = aktualny->getNext();
   }
   return ileEl;
}

//------------------------------------------------------------------------
template<class T>
void aghDlist<T>::nowaLista(T const& element)
{
    aghDnode<T>* newElement = new aghDnode<T>(element);

    this->ptrEnd = new aghDnode<T>(element);
    //this->ptrEnd->setPrev(ptrRoot);
    //this->ptrRoot->setNext(ptrEnd);
}

template<class T>
void aghDlist<T>::dodajPocz(T const& element)
{

    if (ptrRoot)
        nowaLista(element);

    aghDnode<T>* newElement = new aghDnode<T>(element);

    newElement->setNext(this->ptrRoot);
    //this->ptrRoot->setPrev(newElement);
    this->ptrRoot = newElement; 

}

template<class T>
void aghDlist<T>::dodajEnd(T const& element)
{
    getNode(size() - 1)->setNext(new aghDnode<T>(element));  
    /*
                newElement->setPrev(this->ptrEnd);
            this->ptrEnd->setNext(newElement);
            this->ptrEnd = newElement;
    */

}

template<class T>
void aghDlist<T>::dodaj(T const & element, int index)
{
        aghDnode<T>* newElement = new aghDnode<T>(element);
            aghDnode<T>* aktualny = this->ptrRoot;

            for (int i = 0; i < index; i++)            
                aktualny = aktualny->getNext();            

        newElement->setPrev(aktualny->getPrev());
        newElement->setNext(aktualny);
        newElement->getPrev()->setNext(newElement);
        aktualny->setPrev(newElement);
}

template<class T>
void aghDlist<T>::usunPocz()
{
        aghDnode<T>* aktualny = this->ptrRoot;
        this->ptrRoot = aktualny->getNext();
        delete aktualny;
}

template<class T>
void aghDlist<T>::usunEnd()
{
        aghDnode<T>* aktualny = this->ptrEnd;
        this->ptrEnd = aktualny->getPrev();
        delete aktualny;
}

template<class T>
void aghDlist<T>::usun(int index)
{
        aghDnode<T>* aktualny = this->ptrRoot;

        for (int i = 0; i < index - 1; i++)        
            aktualny = aktualny->getNext();
        
        aghDnode<T>* doUsuniecia = aktualny;

        doUsuniecia = doUsuniecia->getNext();
        aktualny->setNext(doUsuniecia->getNext());
        aktualny->setPrev(doUsuniecia->getPrev());

        delete doUsuniecia;
}

template<class T> 
aghDnode<T>* aghDlist<T>::getNode(int n) const 
{

   if(n >= size() || n < 0) 
      throw aghException(0, "Niepoprawny index", __FILE__, __LINE__);

   else 
   {
        aghDnode<T>* temp = ptrRoot;

        for (int i = 0; i < n; i++)
            temp = temp->getNext();

        return temp;
   }

}
//------------------------------------------------------------------------
//------------------------------------------------------------------------




/*
 template<class T>
 bool aghDlist<T>::insert(int index, T const & element)
 {
     if (index < 0 || index > this->size())
        throw aghException(0, "Niepoprawny index", __FILE__, __LINE__);             ///Poza indexem

    else
    {
        aghDnode<T>* newElement = new aghDnode<T>(element);
        
        if (this->ptrRoot == NULL)                                                  
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




*/
template<class T> 
aghDlist<T>& aghDlist<T>::operator=(aghDlist<T> const & element) 
{
   this->aghContainer<T>::operator=(element);
   return *this;
}

#endif