/*
 * This is a C++ class: CsampleSpace
 * 描述样本空间
 * 双色球有33个红球，16个蓝球，共49个
 * 大乐透有35个红球，12个蓝球，共47个

 * data file format:
 * xxxx yy yy yy .. yy : zz zz     ##
*/

#ifndef CSAMPLESPACE_HPP_INCLUDED
#define CSAMPLESPACE_HPP_INCLUDED

#include "CbaseBall.hpp"
#include "Cgame.hpp"
#include <list>
using namespace std;


class CsamplePace{
public:
        CsamplePace();
        ~CsamplePace();

public:
        list <Cgame> sampleSpace;

       // FILE *fp;   //histoy data file


public:
        int get_data_from_txt(const char *path);
        int create_data_file(void);
      //  FILE *get_data_file(char *path);
};

#endif
