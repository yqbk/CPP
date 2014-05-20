/**
* \file aghMatrix.h
* \authors Jakub Syrek & Katarzyna Żukowska
* \date 19.05.2014
* \version 1.0
* \brief Plik nagłówkowy z deklarajcą klasy macierzy
*/

#ifndef AGHMATRIX_H
#define AGHMATRIX_H

// ---------------------------------------------------------
// ---------------------------------------------------------
/**
* \class aghMatrix
* \authors Jakub Syrek & Katarzyna Żukowska
* \date 19.05.2014
* \brief Klasa macierzy
*/

template <class T> 
class aghMatrix
{

  private:

	int rows;
	int cols;
	T **values;

    /**
     * @brief Metoda zmieniająca wymiary macierzy
     * @param r - wiersze [rows]
     * @param c - kolumny [cols]
     */
	void resize(int r, int c);

	/**
     * @brief Metoda usuwająca daną macierz
     */
	void empty();


  public: 

    /**
     * @brief Konstruktor bezparametrowy
     */
 	aghMatrix();

    /**
     * @brief Konstruktor parametrowy
     * @param r - wiersze [rows]
     * @param c - kolumny [cols]
     */
	aghMatrix(int r, int c);

    /**
     * @brief Konstruktor parametrowy
     * @param kopia - obiekt klasy macierzowej
     */
	aghMatrix(aghMatrix<T> const & kopia);

    /**
     * @brief Destuktor
     */
	virtual ~aghMatrix();

// ---------------------------------------------------------
    /**
     * @brief Metoda służąca do zmiany warości danego elementu
     * @param r - wiersze [rows]
     * @param c - kolumny [cols]
     * @param value - wartość
     */
	void setItem(int r, int c, T value);

    /**
     * @brief Metoda służąca do zmiany warości wszystkich elementów z tablicy
     * @param tablica - nowe wartości dla macierzy
     */
	void setItems(T* tablica);

    /**
     * @brief Metoda służąca do zmiany warości danej liczby elementów
     * @param r - wiersze [rows]
     * @param c - kolumny [cols]
     */
	void setItems(int r, int c, ...);

// ---------------------------------------------------------
	/**
     * @brief Przeciążony operator podstawienia
     * @param macierz - macierz którą podstawiamy
     */
	aghMatrix const & operator=(aghMatrix<T> const & macierz);

	/**
     * @brief Przeciążony operator dodawania
     * @param macierz - macierz którą dodajemy
     */
	const aghMatrix<T> operator+(aghMatrix<T> const & macierz);

	/**
     * @brief Przeciążony operator mnożenia
     * @param macierz - macierz przez którą przemnażamy
     */
	const aghMatrix operator*(aghMatrix<T> const & macierz);

	/**
     * @brief Przeciążony operator przyrównania
     * @param macierz - macierz którą porównujemy
     */
	bool operator==(aghMatrix<T> const & macierz) const; // <---

	/**
     * @brief Przeciążony operator !=
     * @param macierz - macierz którą sprawdzamy
     */
	bool operator!=(aghMatrix<T> const & macierz) const; // <---

	/**
     * @brief Przeciążony operator ()
     * @param r - wiersze [rows]
     * @param c - kolumny [cols]
     */
	T operator()(int r, int c) const;

};

// ---------------------------------------------------------

template <> void aghMatrix<char>::setItems(int r, int c, ...);

template <> aghMatrix<char*> const & aghMatrix<char*>::operator=(aghMatrix<char*> const & macierz);

template <> const aghMatrix<char*> aghMatrix<char*>::operator+(aghMatrix<char*> const & macierz);

template <> const aghMatrix<char*> aghMatrix<char*>::operator*(aghMatrix<char*> const & macierz);

template <> bool aghMatrix<char*>::operator==(aghMatrix<char*> const & macierz) const;

template <> bool aghMatrix<char*>::operator==(aghMatrix<char*> const & macierz) const;

// ---------------------------------------------------------
#endif


