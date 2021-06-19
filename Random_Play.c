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

void FunctionRandomSong(Music arry[] , int length );

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

    for(;Max>0;Max--)
    {
        //printf("Max = %d \n",Max);
        Count++;
        randnum = rand() % Max ;   
        if((Max!=1) && (randnum != (Max-1)))
        {
            SWAP(Doarry[randnum],Doarry[Max-1],temp);
        }       
    }
    Print_csv(Doarry, length, length);
    printf("以上就是隨機播放列表!\nSo these are random playlists!\n");
    system("pause");
}
