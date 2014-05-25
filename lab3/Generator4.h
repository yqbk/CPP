#ifndef GENERATOR2_H
#define GENERATOR2_H


class Generator2 : public Generator
{

	private:

		unsigned long long seed;
		unsigned long long mnoznik;
		unsigned long long modul;
		unsigned long long add;

    public:

        Generator2(int iPoczatek, int iKoniec, unsigned long long seed, unsigned long long mnoznik, unsigned long long add, unsigned long long modul, string strNazwaGeneratora);

        ~Generator2();

        void losuj();

};

#endif
