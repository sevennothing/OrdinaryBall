/*
 * This is a C++ class: CbaseBall
 * 描述球的基本特性
 *
*/
#include <iostream>
#include "CbaseBall.hpp"
#include <assert.h>
using namespace std;

CbaseBall::CbaseBall()
{
	colors=RED;
	ballID=1;

}

CbaseBall::CbaseBall(const color icolors,const char iballID)
{
	assert((icolors==RED) || (icolors==BLUE));
	colors=icolors;
	ballID=iballID;
}


CbaseBall::~CbaseBall()
{

}
