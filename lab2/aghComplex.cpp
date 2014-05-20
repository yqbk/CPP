/**
* \file aghComplex.cpp
* \authors Jakub Syrek & Katarzyna Żukowska
* \date 19.05.2014
* \version 1.0
* \brief Plik z definicją klasy liczb urojonych
*/

#include "aghInclude.h"

// ---------------------------------------------------------
// ---------------------------------------------------------
aghComplex::aghComplex()
{
	re = 0;
	im = 0;
}

// ---------------------------------------------------------
aghComplex::~aghComplex()
{

}

// ---------------------------------------------------------
aghComplex::aghComplex(double real, double imaginary)
{
	re = real;
	im = imaginary;
}

// ---------------------------------------------------------
// ---------------------------------------------------------
const aghComplex aghComplex::operator+(aghComplex const & macierz)
{
	aghComplex nowa;

	nowa.re = this->re + macierz.re;
	nowa.im = this->im + macierz.im;

	return nowa;
}

// ---------------------------------------------------------
const aghComplex aghComplex::operator*(aghComplex const & macierz)
{
	aghComplex nowa;

	nowa.re = this->re * macierz.re - this->im * macierz.im;
	nowa.im = this->re * macierz.im + this->im * macierz.re;

	return nowa;
}

// ---------------------------------------------------------
aghComplex const & aghComplex::operator+=(aghComplex const & macierz)
{
	this->re = this->re + macierz.re;
	this->im = this->im + macierz.im;

	return *this;
}

// ---------------------------------------------------------
bool aghComplex::operator==(aghComplex const & macierz)
{
	return( (this->re == macierz.re) && (this->im == macierz.im) );
}

// ---------------------------------------------------------
bool aghComplex::operator!=(aghComplex const & macierz)
{
	return !( *this == macierz );
}