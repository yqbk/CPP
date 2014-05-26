#include "aghInclude.h"

// ---------------------------------------------------------
// ---------------------------------------------------------
int Generator3::i = 0;


// ---------------------------------------------------------
Generator3::Generator3() : Generator(0,1,0, "Generator Fibonacciego") 
{
   size = 0;
   step = 0;
   wynikiGen = NULL;
}


Generator3::Generator3(int iPoczatek, int iKoniec, int size, int step, int seed, string strNazwa) 
{  
   wynikiGen = NULL;
   resetGenerator(iPoczatek, iKoniec, size, step, seed);
   setNazwa("Generator Fibonacciego");
}


Generator3::~Generator3() 
{

   if(wynikiGen != NULL)
      delete[] wynikiGen;

   wynikiGen = NULL;
}


// ---------------------------------------------------------
void Generator3::setGenerator() 
{
   if(size <= 1)
      throw aghException(0, "Niepoprawne dane wejscowe", __FILE__, __LINE__);
   
   else 
   {
      if(wynikiGen != NULL)
         delete[] wynikiGen;

      wynikiGen = new int[size];

      srand(seed);

      for(int i = 0; i < size; i++)
         wynikiGen[i] = rand() % (getKoniec() - getPoczatek() + 1) + iPoczatek;
   }
}


void Generator3::resetGenerator(int iPoczatek, int iKoniec, int size, int step, int seed) 
{ 
   if(step >= size)
      throw aghException(0, "Niepoprawne dane wejscowe", __FILE__, __LINE__);
   
   else 
   {
      setSize(size);
      setStep(step);

      setPoczatek(iPoczatek);
      setKoniec(iKoniec);

      setSeed(seed);
      setGenerator();
   }
   
}


void Generator3::losuj() 
{
   wynikiGen[i] = ((wynikiGen[(size + i - step) % size] ^ wynikiGen[i]) % (getKoniec() - getPoczatek() + 1) ) + iPoczatek;
   iWylosowana = wynikiGen[i];
   i = (i + 1) % size;
}


// ---------------------------------------------------------
int Generator3::getSize()  
{
   return size;
}


void Generator3::setSize(int size) 
{
   if(size <= 1) 
      throw aghException(0, "Niepoprawne dane wejscowe", __FILE__, __LINE__);

   else 
   {
      this->size = size;
      setGenerator();     
   }

}


int Generator3::getStep()  
{
   return step;
}


// ---------------------------------------------------------
void Generator3::setStep(int step) 
{
   if(step <= 0 || step > size) 
      throw aghException(0, "Niepoprawne dane wejscowe", __FILE__, __LINE__);
   
   else 
      step = step;     
  
}


void Generator3::setSeed(int seed) 
{
   if(seed < 0)
      throw aghException(0, "Niepoprawne dane wejscowe", __FILE__, __LINE__);
   
   else 
   {
      seed = seed;
      setGenerator();
      
   }
}


// ---------------------------------------------------------
// ---------------------------------------------------------