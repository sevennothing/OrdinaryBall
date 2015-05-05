/*
 * This is a C++ class: CbaseBall
 * ÃèÊöÇòµÄ»ù±ŸÌØÐÔ
 *
*/
#include <iostream>
#include "CsampleSpace.hpp"
#include <assert.h>


using namespace std;

int main()
{

	cout << "This is Main process for Oridinary ball Deamo!" <<endl;

/*
    Cgame game(COLOR_BALL);
    if(!game.create_ball())
        cout<<"erro"<<endl;

    for(int i=0 ;i<game.redBallNum;i++)
           cout << "ID =" << (game.redBall+i)->ballID << endl;
*/
    CsamplePace spp;
    char *path = "/home/jun/colorball.data";
    spp.get_data_from_txt(path);

    for ( list <Cgame>::iterator Iter = spp.sampleSpace.begin( ); Iter != spp.sampleSpace.end( ); Iter++ )
        cout << " " << Iter->gameID;
    cout << endl;

    cout<< "==== end ======"<<endl;
	return 0;
}

