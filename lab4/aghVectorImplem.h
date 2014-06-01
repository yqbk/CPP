#ifndef AGHVECTORIMPLEM_H
#define AGHVECTORIMPLEM_H

//------------------------------------------------------------------------
//------------------------------------------------------------------------
template<class T>
aghVector<T>::aghVector(aghVector<T> const & other) 
{
    this->iRozmiar = 0;
    this->iMaxRozmiar = iRozmiar;
    //this->vector = new T[other.iMaxRozmiar];

   this->aghContainer<T>::operator =(other);
}

template<class T>
aghVector<T>::aghVector(aghContainer<T> const & other) 
{
    this->iRozmiar = 0;
    this->iMaxRozmiar = iRozmiar;
    //this->vector = new T[other.iMaxRozmiar];

   this->aghContainer<T>::operator =(other);
}

template<class T>
aghVector<T>::~aghVector()
{
    if (this->vector != NULL)
    {
        delete []this->vector;
    }
    this->vector = NULL;
}

template<class T>
aghVector<T>::aghVector()
{
    this->iRozmiar = 0;
    this->iMaxRozmiar = 0;
    this->vector = NULL;
}


//------------------------------------------------------------------------
template<class T>
void aghVector<T>::setMemoryStep(int _memoryStep) {
   if(_memoryStep < 1) {
      throw aghException(11, "Incorrect value", __FILE__, __LINE__);
   } else {
      memoryStep = _memoryStep;
   }
}

template<class T>
int aghVector<T>::getMemoryStep() const {
   return memoryStep;
}

template<class T>
int aghVector<T>::getMemorySize() const {
   return memorySize;
}

template<class T>
int aghVector<T>::getFreeMemorySize() const {
   return memorySize - size();
}


//------------------------------------------------------------------------
template<class T>
int aghVector<T>::size() const
{
   return this->iRozmiar;
}

template<class T>
T& aghVector<T>::at(int index) const
{
    if (index >= 0 && index < this->iRozmiar)
    {
        return this->vector[index];
    }

}

template<class T>
void aghVector<T>::resize(unsigned int iRozmiar)
{
    this->iMaxRozmiar = iRozmiar;
    T *vector2 = new T[iRozmiar];

    memcpy(vector2, this->vector, this->iRozmiar*sizeof(T));  //mozna realloc zrobic
    delete []this->vector;
    this->vector = vector2;
}


template<class T>
bool aghVector<T>::insert(int index, T const& element)
{


    if (index < 0)
    {
        return false;
    }

    if (index >= this->iMaxRozmiar)
    {
        resize(index + 1);

    }

    this->vector[index] = element;

    if (index >= this->iRozmiar)    // <----- zle
    {
        this->iRozmiar++;
    }


    return true;
}

/*
template<class T>
bool aghVector<T>::insert(int _index, T const & _object) {
   int flag = false;

   if((_index >= 0) && (_index <= size())) {
      if(getFreeMemorySize() == 0) { // check if vector is not full
         enlargeMemory();
      }

      // move elements after _index
      for(int i = elementsCount; i > _index; i--) {
         memory[i] = memory[i - 1];
      }

      memory[_index] = _object;
      elementsCount++;

      flag = true;
   }

   return flag;
}


template<class T>
T& aghVector<T>::at(int _index) const {
   if((_index < 0) || (_index >= size())) {
      throw aghException(12, "Index out of range", __FILE__, __LINE__);
   } else {
      return memory[_index];
   }
}


*/
template<class T>
bool aghVector<T>::remove(int _index) 
{
   int flag = false;

   if((_index >= 0) && (_index <= size())) 
   {
      if(size() > 0) 
      {
   
         for(int i = _index; i < size() - 1; i++) 
         {
            vector[i] = vector[i + 1];
         }
         vector[size() - 1].~T();
         iMaxRozmiar--;

         
        }

         flag = true;

   }
   return flag;
}

//------------------------------------------------------------------------
template<class T>
aghVector<T> const & aghVector<T>::operator=(aghVector<T> const & other) 
{
   this->aghContainer<T>::operator =(other);
   return *this;
}



#endif