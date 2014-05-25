#ifndef TEST1_H
#define TEST1_H


class Test1: public Test
{
    protected:							//ZIARNO LOSOWANIA, DO POPRAWY!!!!

        int iIloscParzystych;
        int iIloscNieparzystych;

    public:

        Test1(string strNazwaTestu, Generator *wskGenerator, int iIloscLosowan);

        ~Test1();

        void testuj();

        void print(ostream& = cout);

};

#endif
