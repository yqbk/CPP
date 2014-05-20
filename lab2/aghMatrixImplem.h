/**
* \file aghMatrixImplem.h
* \authors Jakub Syrek & Katarzyna Żukowska
* \date 19.05.2014
* \version 1.0
* \brief Plik nagłówkowy z implementacją klasy (z pliku aghMatrix.h)
*/

#ifndef AGHMATRIXIMPLEM_H
#define AGHMATRIXIMPLEM_H

// ---------------------------------------------------------
template <class M>
aghMatrix<M>::aghMatrix()
{
	values = NULL;
	cols = 0;
	rows = 0;
}

// ---------------------------------------------------------
template <class M>
aghMatrix<M>::aghMatrix(int r, int c)
{
	values = NULL;
	resize(r, c);

}

// ---------------------------------------------------------
template<class M>
aghMatrix<M>::aghMatrix(aghMatrix<M> const & kopia) 
{
   *this = kopia;
}

// ---------------------------------------------------------
template <class M>
aghMatrix<M>::~aghMatrix()
{		
	empty();
}

// ---------------------------------------------------------
//						resize & empty
// ---------------------------------------------------------
template <class M>
void aghMatrix<M>::resize(int r, int c)
{
	if( (r < 0) || (c < 0) )	
		throw aghException(0, "Niepoprawny index!", __FILE__, __LINE__);	

	else if(values != NULL)	
		throw aghException(1, "Macierz juz utworzona!", __FILE__, __LINE__);	

	else
	{
		rows = r;
		cols = c;

		values = new M*[rows];	

      	for(int i = 0; i < rows; ++i) 
      	{
         	values[i] = new M[cols];

         	for(int j = 0; j < cols; ++j) 
         	{
            	values[i][j] = M();
            }

        }
	}
}

// ---------------------------------------------------------
template <class M>
void aghMatrix<M>::empty()
{
	for(int i = 0; i < rows; ++i)
		 delete [] values[i];	

	delete [] values;

	rows = 0;
	cols = 0;
	values = NULL;

}

// ---------------------------------------------------------
//						setItem
// ---------------------------------------------------------
template <class M>
void aghMatrix<M>::setItem(int r, int c, M value)
{
	if( (r < 0) || (c < 0) || (r >= rows) || (c >= cols))
		throw aghException(0, "Niepoprawny index!", __FILE__, __LINE__);	

	else
		values[r][c] = value;
}

// ---------------------------------------------------------
template <class M>
void aghMatrix<M>::setItems(M *tablica)
{		
	if (tablica == NULL)	
		throw aghException(1, "Brak takiej tablicy!", __FILE__, __LINE__);	

	else
	{
		for(int i = 0; i < rows; ++i)
			for(int j = 0; j < cols; ++j)
				values[i][j] = *(tablica++);
	}

}

// ---------------------------------------------------------
template <class M>
void aghMatrix<M>::setItems(int r, int c, ...)
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
			values[i][j] = va_arg(wartosci, M);	

	va_end(wartosci);
}

// ---------------------------------------------------------
//						operatory
// ---------------------------------------------------------
template <class T>
aghMatrix<T> const & aghMatrix<T>::operator=(aghMatrix<T> const & macierz)
{
	if (&macierz != this)
	{
		if (values != NULL)		
			empty();

		resize(macierz.rows, macierz.cols);

		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < cols; ++j)
				values[i][j] = macierz.values[i][j];		
	}

	return *this;
}

// ---------------------------------------------------------
template <class M>
bool aghMatrix<M>::operator==(aghMatrix<M> const & macierz) const
{
	bool similar = true;

	if ( (macierz.cols == cols) && (macierz.rows == rows)) 
		for (int i = 0; i < rows && similar; ++i)
			for (int j = 0; j < cols && similar; ++j)
				similar = (values[i][j] == macierz.values[i][j]);	

	else
		similar = false;

	return similar;
}

// ---------------------------------------------------------
template <class M>
bool aghMatrix<M>::operator!=(aghMatrix<M> const & macierz) const
{
	bool similar = true;

	similar = !( *this == macierz );

	return similar;
}

// ---------------------------------------------------------
template <class M>
const aghMatrix<M> aghMatrix<M>::operator+(aghMatrix<M> const & macierz)
{
	aghMatrix<M> suma;
 
	if ( (rows != macierz.rows) || (cols != macierz.cols) ) 
		throw aghException(2, "Rozne wymiary tablic!", __FILE__, __LINE__);	

	else
	{
		suma.resize(rows, cols);

		for (int i = 0; i < rows; ++i)	
			for (int j = 0; j < cols; ++j)	
				suma.setItem(i, j, values[i][j] + macierz.values[i][j]);
	}

	return suma;
}

// ---------------------------------------------------------
template <class M>
const aghMatrix<M> aghMatrix<M>::operator*(aghMatrix<M> const & macierz)
{
	aghMatrix<M> iloczyn;

	if (cols != macierz.rows)	
		throw aghException(2, "Rozne wymiary tablic!", __FILE__, __LINE__);	

	else
	{
		iloczyn.resize(rows, macierz.cols);

		for (int i = 0; i < rows; ++i)	
			for (int j = 0; j < macierz.cols; ++j)	
			{		
            	iloczyn.values[i][j] = M();  // <--
            	
            	for(int k = 0; k < cols; ++k) 
               		iloczyn.values[i][j] += values[i][k] * macierz.values[k][j];
            }
	}

	return iloczyn;
}

// ---------------------------------------------------------
template <class M>
M aghMatrix<M>::operator()(int r, int c) const
{
	if( (r < 0) || (c < 0) || (r >= rows) || (c >= cols))	
		throw aghException(0, "Niepoprawny index!", __FILE__, __LINE__);

    return values[r][c];
}

// ---------------------------------------------------------
// ---------------------------------------------------------
#endif