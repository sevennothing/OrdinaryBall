/*
 * This is a C++ class: CsampleSpace
 * ÃèÊöÑù±¾¿Õ¼ä
 *
*/

#include "CsampleSpace.hpp"
#include <iostream>
#include <fstream>
#include <string.h>
#include <assert.h>
using namespace std;


CsamplePace::CsamplePace()
{

}

CsamplePace::~CsamplePace()
{

}

char * get_data_filed(const char *indata,char *outdata,int section)
{
    assert(section < 4 && section > 0);

    char *str1 = NULL;
    char *str2 = NULL;

    //find ':'
    str1=(char *) strstr(indata," : ");
    if(section == 1){
            strncpy(outdata,indata,str1-indata);
            return outdata;
    }
    str2=(char *) strstr(str1 + 1," : ");
    if(section == 2){
            strncpy(outdata,str1,str2-str1);
            return outdata;
    }
    if(section == 3){
            strcpy(outdata,str2+1);
            return outdata;
    }

    return NULL;
}

int get_number(const char *str,int *num)
{
    char *strp = (char *)str;
    int i=0;
    char endflag=0;

    while(*(strp++)!='\0'){
        if(*strp >= '0' && *strp <='9'){
            if(endflag==0){
                *(num+i)=*strp-'0';
                endflag = 1;
            }else{
                *(num+i)=(*(num+i)*10 ) + *strp-'0';
                i++;
                endflag=0;
            }

        }else{
            if(endflag)
                i++;
            endflag = 0;
        }
    }
    return i;
}


int data_valid(const char *data)
{
    if (*data == '#'){
        //it's note,ignore
        cout << "it's note " << data << endl;
        return 0;
    }
    int count=0;
    char redcount=-1;
    char bluecount=-1;
    char redcountok=-1;

    for(int i=0;*(data+i)!='\0';i++){
        if(*(data+i) == ':'){
            count++;
            if(count==1){
                redcount=0;
            }
            if(count==2){
                bluecount=0;
                redcountok=1;
            }
        }
        if(redcount>=0 && redcountok!=1){
            if((*(data+i)>='0')&&(*(data+i)<='9') && (*(data+i+1)== ' '))
                redcount++;
        }
        if(bluecount>=0){
            if((*(data+i)>='0')&&(*(data+i)<='9') && (*(data+i-1)== ' '))
                bluecount++;
        }
    }
    if(count!=2 || (bluecount + redcount)!=7){
        cout << "format erro" <<endl;
        return 0;
    }

    if(redcount==5 &&  bluecount==2)
        return LOTTO;
     if(redcount==6 &&  bluecount==1)
        return COLOR_BALL;

    return 0;
}


int CsamplePace::get_data_from_txt(const char *path)
{
    assert(path!=NULL);
    ifstream fin(path,ios::in);

    if(!fin.is_open()){
        cout << "Open " << path <<" erro" <<endl;
        return 0;
    }
    char buf[1024];
    char segment[50];
    int num[7];
    while(fin.good() && !fin.eof()){
        memset(buf,0,1024);
        memset(segment,0,50);
        fin.getline(buf,1024);
        int ret=data_valid(buf);
        if(ret){

            Cgame tmpgame((Game)ret);
            get_data_filed(buf,segment,ID_SEGMENT);
            strncpy(tmpgame.gameID,segment,10);

            memset(segment,0,50);
            get_data_filed(buf,segment,RED_BALL_SEGMENT);
            int i = get_number(segment,num);
            for(int j=0;j<i;j++)
                *(tmpgame.redArry+j)=num[j];

            memset(segment,0,50);
            get_data_filed(buf,segment,BLUE_BALL_SEGMENT);
            i = get_number(segment,num);
            for(int j=0;j<i;j++)
                *(tmpgame.blueArry+j)=num[j];

            list <Cgame>::iterator Iter;
            Iter = sampleSpace.begin();
            sampleSpace.push_back(tmpgame);

        }
    }

    return 1;
}
