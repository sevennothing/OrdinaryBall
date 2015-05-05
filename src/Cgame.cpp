

#include "Cgame.hpp"
#include <iostream>
#include <assert.h>

using namespace std;

Cgame::Cgame()
{
    name = COLOR_BALL;
    redBallNum = 33;
    blueBallNum = 16;
    choiceRedNum = 6;
    choiceBlueNum = 1;
    redBall = NULL;
    blueBall = NULL;

    redArry = new int[choiceRedNum];
    blueArry = new int[choiceBlueNum];

}

Cgame::Cgame(const Game igame)
{
    assert( (igame==COLOR_BALL) || (igame==LOTTO) || (igame==DEFINE_SELF) );
    name = igame;
    switch(name){
    case COLOR_BALL:
        redBallNum = 33;
        blueBallNum = 16;
        choiceRedNum = 6;
        choiceBlueNum = 1;
        break;
    case LOTTO:
        redBallNum = 35;
        blueBallNum = 12;
        choiceRedNum = 5;
        choiceBlueNum = 2;
        break;
    case DEFINE_SELF:
        redBallNum = 0;
        blueBallNum = 0;
        choiceRedNum = 0;
        choiceBlueNum = 0;
        break;
    default:
        break;
    }

    redBall = NULL;
    blueBall = NULL;

    redArry = new int[choiceRedNum];
    blueArry = new int[choiceBlueNum];


}

Cgame::~Cgame()
{
    delete [] redBall;
	delete [] blueBall;

	delete [] redArry;
	delete [] blueArry;

}


int Cgame::create_ball(void)
{
    redBall=new CbaseBall[redBallNum];
    blueBall=new CbaseBall[blueBallNum];

    if(!redBall || !blueBall){
		cout << "malloc erro" <<endl;
		return 0;
	}
	// creat ball group
	for(int i=0;i<redBallNum;i++){
		(redBall+i)->colors=RED;
		(redBall+i)->ballID=i+1;
	}
	for(int i=0;i<blueBallNum;i++){
		(blueBall+i)->colors=BLUE;
		(blueBall+i)->ballID=i+1;
	}

	return redBallNum + blueBallNum ;

}
