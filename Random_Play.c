#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<time.h>
#define SWAP(x, y, t) { (t) = (x) ; (x) = (y) ; (y) = (t);}
/*
    How to use : Need a arry[] to put in this function and data structure is "Music".
                 Need arry length to put in this function.
    ex: FunctionRandomSong( arry  ,  length);
*/
// typedef struct Song{
//     char Name[20];
//     char Singer[20];
//     int Time;
// }Music;

void FunctionRandomSong(Music arry[] , int length );
//void PrintData(Music show , int no);


void FunctionRandomSong(Music arry[] , int length )
{
    Music Doarry[length], temp;
    printf("Now it's random time\n");
    int i,Max=length,randnum ,Count=0;
    srand(time(NULL));
    for(i=0;i<Max;i++)
    {
        Doarry[i]=arry[i];
    }

    //printf("No                  Song                Singer              Time\n");//  ??
    for(;Max>0;Max--)
    {
        //printf("Max = %d \n",Max);
        Count++;
        randnum = rand() % Max ;   
        //PrintData(Doarry[randnum] , Count); // ???
        if((Max!=1) && (randnum != (Max-1)))
        {
            SWAP(Doarry[randnum],Doarry[Max-1],temp);
        }       
    }
    Print_csv(Doarry,0 , length);
    system("pause");
}
// void PrintData(Music show , int no)
// {
//     printf("%-20d%-20s%-20s%-20d \n",no,show.Name,show.Singer,show.Time); // ??
// }

