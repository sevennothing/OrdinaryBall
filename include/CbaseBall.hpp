/*
 * This is a C++ class: CbaseBall
 * ������Ļ�������
 *
*/

#ifndef CBASEBALL_HPP_INCLUDED
#define CBASEBALL_HPP_INCLUDED

enum color{
	RED,
	BLUE
};

class CbaseBall{
public:
		CbaseBall();
		CbaseBall(const color icolors,const char iballID);
		~CbaseBall();
public:
		color colors;
		int ballID;

};

#endif
