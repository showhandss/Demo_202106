#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Read_csv.c"

int Search(char*);
int Song_num;                       // The number of songs in csv.
Music MusicS[1000];                // Global var. Using to save songs' information in array type.  

// Query the input of the singer in total which songs will be printed after sorting the songs.
int Search(char *Singer)
{
    char buffer[1024];
}

int main()
{
    Song_num = Read_csv(MusicS);
    printf("%d\n",Song_num);
    printf('%d\n%s,%s,%d\n',Song_num, MusicS[0].Name, MusicS[0].Singer, MusicS[0].Time);
}