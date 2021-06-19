#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct music Music;
//typedef struct randomSongList RSL;
char* INPUT_FILE;

//  Data struct of song(with Name, Singer's name and its Time).
typedef struct music
{
    char Name[60];
    char Singer[30];
    int Time;
}Music;

//  Recommended for random playlists(because of its linklist type).
// typedef struct randomSongList
// {
//     Music *Cur;
//     RSL *Next;
// }RSL;