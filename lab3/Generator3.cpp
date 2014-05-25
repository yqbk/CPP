#include "aghInclude.h"


int Generator3::i = 0;

Generator3::Generator3() : Generator(0,1,0, "Generator Fibonacciego") 
{
   size = 0;
   step = 0;
   state = NULL;
}

Generator3::Generator3(int iPoczatek, int iKoniec, int _size, int _step, int _seed, string strNazwa) 
{  
   state = NULL;
   resetGenerator(iPoczatek, iKoniec, _size, _step, _seed);
   setNazwa("Generator Fibonacciego");
}

Generator3::~Generator3() 
{
   if(state != NULL)
      delete[] state;

   state = NULL;
}

void Generator3::initializeGenerator() 
{
   if(size <= 1)
      throw aghException(0, "Wrong values given", __FILE__, __LINE__);
   
   else 
   {
      if(state != NULL)
         delete[] state;

      state = new int[size];

      srand(seed);

      for(int i = 0; i < size; i++)
         state[i] = rand() % (getKoniec() - getPoczatek() + 1) + iPoczatek;
   }
}

void Generator3::losuj() 
{
   state[i] = ((state[(size + i - step) % size] ^ state[i]) % (getKoniec() - getPoczatek() + 1) ) + iPoczatek;
   iWylosowana = state[i];
   i = (i + 1) % size;
}

int Generator3::getSize()  
{
   return size;
}

void Generator3::setSize(int _size) 
{
   if(_size <= 1) 
      throw aghException(0, "Wrong values given", __FILE__, __LINE__);

   else 
   {
      size = _size;
      initializeGenerator();     
   }

}

int Generator3::getStep()  
{
   return step;
}


void Generator3::setStep(int _step) 
{
   if(_step <= 0 || _step > size) 
      throw aghException(0, "Wrong values given", __FILE__, __LINE__);
   
   else 
      step = _step;     
  
}

void Generator3::setSeed(int _seed) 
{
   if(_seed < 0)
      throw aghException(0, "Wrong values given", __FILE__, __LINE__);
   
   else 
   {
      seed = _seed;
      initializeGenerator();
      
   }
}

void Generator3::resetGenerator(int iPoczatek, int iKoniec, int _size, int _step, int _seed) 
{ 
   if(_step >= _size)
      throw aghException(0, "Wrong values given", __FILE__, __LINE__);
   
   else 
   {
      setSize(_size);
      setStep(_step);

      //setRange(_beg, iKoniec);
      setPoczatek(iPoczatek);
      setKoniec(iKoniec);

      setSeed(_seed);
      initializeGenerator();
   }
   
}
