#include<stdio.h>
#include<stdlib.h>
typedef struct music Music;
typedef struct randomSongList RSL;

//  Data struct of song(with Name, Singer's name and its Time).
typedef struct music
{
    char Name[20];
    char Singer[20];
    int Time;
}Music;

//  Recommended for random playlists(because of its linklist type).
typedef struct randomSongList
{
    Music Cur;
    RSL *Next;
}RSL;

int Search(char*);
int Read_csv(Music*);
int Song_num;                       // The number of songs in csv.
Music MusicS[1000];                // Global var. Using to save songs' information in array type.  

// Query the input of the singer in total which songs will be printed after sorting the songs.
int Search(char *Singer)
{
    char buffer[1024];
}

// import the exact csv(return the number of songs  Or fail by -1)
int Read_csv(Music *ALL)
{
                 
    FILE* fp = NULL;                // import File

    printf("%p\n",ALL);
    if ((fp = fopen("歌單.csv", "r")) != NULL)
    {
        int Current = 0;            // current number
        while(fscanf(fp, "%s,%s,%d", ALL[Current].Name, ALL[Current].Singer, ALL[Current].Time)!=EOF)
        {
            Current++;              // which means the info was imported successfully.
        }
		fclose(fp);
		fp = NULL;
        return Current;
    }
    else
    {
        //printf("fp:%s\n",fp);
        printf("Cannot find the List of Songs!\nPlease find out the exact file.\n");
        return 0;
    }
}

int main()
{
    FILE* IN;
    IN = fopen("歌單.csv", "r+");
    printf("IN:%s\n",IN);
    Song_num = Read_csv(MusicS);
    printf('%d\n',Song_num);
    //printf('%d\n%s,%s,%d\n',Song_num, MusicS[0].Name, MusicS[0].Singer, MusicS[0].Time);
    fclose(IN);
}