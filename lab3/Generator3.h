#ifndef GENERATOR3_H
#define GENERATOR3_H


class Generator3 : public Generator
{
	private:

      int size; ///size of array
      int step; ///step
      int* state; ///array with generator state

      static int i; ///counter

      void initializeGenerator(void);

    public:

    	Generator3();

        Generator3(int, int, int, int, int );

        ~Generator3();

        void resetGenerator(int, int, int, int, int );

        void losuj();



        int getSize();

        int getStep();

        int getSeed();



      	void setSize(int);

      	void setStep(int);

      	void setSeed(int);

};

#endif

