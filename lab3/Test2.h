#ifndef TEST2_H
#define TEST2_H

class Test2 : public Test
{

	protected:

        int iIloscPierwszych;

    public:

        Test2(string strNazwaTestu, int iIloscLosowan, Generator *wskGenerator);
        ~Test2();
        void testuj();



};

#endif
