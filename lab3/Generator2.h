#ifndef GENERATOR2_H
#define GENERATOR2_H


class Generator2 : public Generator
{

	private:

		int seed;
		int mnoznik;
		int modul;
		int add;


    public:

        Generator2(int iPoczatek, int iKoniec, int seed, int mnoznik, int add, string strNazwaGeneratora);

        void losuj();

};

#endif // GENERATOR2_H
