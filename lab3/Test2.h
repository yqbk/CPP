#ifndef TEST2_H
#define TEST2_H


class Test2: public Test
{
	protected:

        int iIloscPierwszych;

    public:

        Test2(string strNazwaTestu, Generator *wskGenerator, int iIloscLosowan);

        ~Test2();

        void testuj();

        void print(ostream& = cout);

};

#endif
