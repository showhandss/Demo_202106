#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct music Music;
typedef struct SingerList SL;
char* INPUT_FILE;

//  Data struct of song(with Name, Singer's name and its Time).
typedef struct music
{
    char Name[60];
    char Singer[30];
    int Time;
}Music;
