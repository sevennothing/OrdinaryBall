#ifndef CANALYSE_HPP_INCLUDED
#define CANALYSE_HPP_INCLUDED

#include "CsampleSpace.h"

const char termMax=10;

class Canalyse{
public:
        Canalyse();
        ~Canalyse();


public:
       CsampleSpace *sampleSpace;

        int lifelen; //how many length by analyse
        int allNum;  //
        int termchoice;
        int *numbers[termMax];
        int *choiceterm[termchoice];

public:
        void build_model(void);

private:
        void calc_Pa(); //calculate probability for every number


};


#endif // CANALYSE_HPP_INCLUDED
