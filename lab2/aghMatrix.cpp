#include "aghInclude.h"

// ---------------------------------------------------------
//                        char
// ---------------------------------------------------------
template<>
void aghMatrix<char>::setItems(int r, int c, ...) 
{
	if (values != NULL)
		empty();

	if( (r < 0) || (c < 0) )
		throw aghException(0, "Niepoprawny index!", __FILE__, __LINE__);

	resize(r, c);

	va_list wartosci;

	va_start(wartosci, c);

	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			values[i][j] = va_arg(wartosci, int);
    
	va_end(wartosci);

}

// ---------------------------------------------------------
template<>
aghMatrix<char> const aghMatrix<char>::operator+(aghMatrix<char> const & macierz)
{
    if ( (rows != macierz.rows) || (cols != macierz.cols) )  						
        throw aghException(2, "Rozne wymiary tablic!", __FILE__, __LINE__);    

    aghMatrix<char> wynik(rows, cols);

    for (int i = 0; i < wynik.rows; ++i)   
        for (int j = 0; j < wynik.cols; ++j)     
            wynik.values[i][j] = ( (values[i][j] + macierz.values[i][j] - 2 * 'a') % 26 )+ 'a';       
   
    return wynik;
}

// ---------------------------------------------------------
template <>
aghMatrix<char> const aghMatrix<char>::operator*(aghMatrix<char> const & macierz)
{
    if (cols != macierz.rows)
		throw aghException(2, "Rozne wymiary tablic!", __FILE__, __LINE__); 

    aghMatrix<char> wynik(rows, macierz.cols);

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < wynik.cols; ++j)
        {
            for (int k = 0; k < cols; ++k)            
               wynik.values[i][j] += ( (values[i][k] - 97) * (macierz.values[k][j] - 97) ) % 26;             

            wynik.values[i][j] = wynik.values[i][j] % 26 + 'a';     
        }
    }

    return wynik;  
}

// ---------------------------------------------------------
//                        char*
// ---------------------------------------------------------
template<> aghMatrix<char*>::~aghMatrix()
{

	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)		
			delete [] values[i][j];

	empty();
}

// ---------------------------------------------------------
template <> void aghMatrix<char*>::setItem(int r, int c, char* value)
{
	if( (r < 0) || (c < 0) || (r >= rows) || (c >= cols))	
		throw aghException(0, "Niepoprawny index!", __FILE__, __LINE__);	

	else
	{
		  if(values[r][c] != NULL)
			   delete [] values[r][c];

		  if(value != NULL)
		  {
			    values[r][c] = new char[strlen(value) + 1];
          strcpy(values[r][c], value);
      }
	}

}

// ---------------------------------------------------------
template <> void aghMatrix<char*>::setItems(char** tablica)
{
	if (tablica == NULL)
		throw aghException(1, "Brak takiej tablicy!", __FILE__, __LINE__);	

	else
	{
		  for (int i = 0; i < rows; ++i)
		  {
			   for (int j = 0; j < cols; ++j)
			   {
				    if(values[i][j] != NULL)
					     delete [] values[i][j];
				
				    values[i][j] = new char[strlen(*tablica) + 1];
            strcpy(values[i][j], *tablica);
            tablica += 1;
			   }
		  }
	}

}

// ---------------------------------------------------------
template <> void aghMatrix<char*>::setItems(int r, int c, ...)
{
	if (values != NULL)
		empty();

	if( (r < 0) || (c < 0) )	
		throw aghException(0, "Niepoprawny index!", __FILE__, __LINE__);


	resize(r, c);

	va_list wartosci;

	va_start(wartosci, c);


	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)		
			values[i][j] = new char[strlen(va_arg(wartosci, char*)) + 1];	

	va_start(wartosci, c);
	
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)		
			strcpy(values[i][j], va_arg(wartosci, char*) );	

	va_end(wartosci);
}

// ---------------------------------------------------------
template<>
aghMatrix<char*> const & aghMatrix<char*>::operator=(aghMatrix<char*> const & macierz)
{
   if(&macierz != this) 
   {
      if(values != NULL) 
      {
         for(int i = 0; i < rows; i++) 
            for(int j = 0; j < cols; j++) 
               delete[] values[i][j];        

          empty();
      }  

      resize(macierz.rows, macierz.cols);

      for(int i = 0; i < rows; i++) 
         for(int j = 0; j < cols; j++) 
         {
            values[i][j] = new char[strlen(macierz.values[i][j]) + 1];      
            strcpy(values[i][j], macierz.values[i][j]);
         }
      
   }
   return *this;
}

// ---------------------------------------------------------
template<>
const aghMatrix<char*> aghMatrix<char*>::operator+(aghMatrix<char*> const & macierz)
{   
   aghMatrix wynik;

   if((cols != macierz.cols) || (rows != macierz.rows)) 
      throw aghException(2, "Rozne wymiary tablic!", __FILE__, __LINE__);

   else 
   {
      wynik.resize(rows, cols);

      for(int i = 0; i < rows; i++) 
         for(int j = 0; j < cols; j++) 
         {
            string strResult = dodajZnaki(this->values[i][j], macierz.values[i][j]);
            wynik.values[i][j] = new char[strResult.length() + 1]; 
            strcpy(wynik.values[i][j], strResult.c_str());
         }    
   }

   return wynik;
}

// --------------------------------------------------------- 
template<>
const aghMatrix<char*> aghMatrix<char*>::operator*(aghMatrix<char*> const & macierz) 
{
    aghMatrix wynik;

    if(cols != macierz.rows) 
      throw aghException(2, "Rozne wymiary tablic!", __FILE__, __LINE__);
  
    else 
    {      
      wynik.resize(rows, macierz.cols);
      
      for(int i = 0; i < rows; i++) 
         for(int j = 0; j < macierz.cols; j++)          
         {
            string strResult;
            for (int k = 0; k < this->cols; k++)
            {
                strResult = dodajZnaki(strResult.c_str(),(mnozZnaki(this->values[i][k], macierz.values[k][j])).c_str());
            }
            wynik.values[i][j] = new char[strResult.length() + 1];
            strcpy(wynik.values[i][j], strResult.c_str()); 
        }
    }
    return wynik;
}

// ---------------------------------------------------------
template<>
bool aghMatrix<char*>::operator==(aghMatrix<char*> const & macierz) const
{
    if (this->rows != macierz.rows || this->cols != macierz.cols)
    {
        return false;
    }

    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            if (strcmp(this->values[i][j], macierz.values[i][j]))
            {
                return false;
            }
        }
    }
    return true;
}

// ---------------------------------------------------------
template<>
bool aghMatrix<char*>::operator!=(aghMatrix<char*> const & macierz) const
{
  bool similar = true;

  similar = !( *this == macierz );

  return similar;
}

// ---------------------------------------------------------
// ---------------------------------------------------------
