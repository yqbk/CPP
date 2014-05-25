#ifndef TEST3_H
#define TEST3_H


class Test3: public Test
{
	protected:

        int **powtorzenia;
        int max;
    	int index;

    public:

        Test3(string strNazwaTestu, Generator *wskGenerator, int iIloscLosowan);

        ~Test3();

        void testuj();

      	void print(ostream& = cout);

};

#endif