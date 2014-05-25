#ifndef GENERATOR1_H
#define GENERATOR1_H


class Generator1 : public Generator
{
    public:

        Generator1(int iPoczatek, int iKoniec, int seed, string strNazwaGeneratora);

        ~Generator1();

        void losuj();

};

#endif