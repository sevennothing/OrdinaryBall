#ifndef CGAME_HPP_INCLUDED
#define CGAME_HPP_INCLUDED

#include "CbaseBall.hpp"

const char ID_SEGMENT=1;
const char RED_BALL_SEGMENT=2;
const char BLUE_BALL_SEGMENT=3;

enum Game{
    COLOR_BALL=1,
    LOTTO,
    DEFINE_SELF
};

class Cgame{
public:
        Cgame();
        Cgame(const Game igame);
        ~Cgame();

public:
        Game name;
        char gameID[10];
        int redBallNum;
        int blueBallNum;
        int choiceRedNum;
        int choiceBlueNum;

        int *redArry;
        int *blueArry;

        /* all balls*/
        CbaseBall *redBall;
		CbaseBall *blueBall;

public:
        int create_ball(void);

};

#endif // CGAME_HPP_INCLUDED
