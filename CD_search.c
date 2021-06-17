#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Read_csv.c"

// Music MusicS[10000];                // Global var. Using to save songs' information in array type.  
// int Song_num;                       // The number of songs in csv.

int Search(char*);
void Print_csv(Music*, int);
void Print_csv_row(int);

// Query the input of the singer in total which songs will be printed after sorting the songs.
int Search(char *Singer)
{
    Music Target[10000];
    int ii = 0, now = 0;
    for(ii = 0; ii < Song_num; ii++)
    {
        if(strcmp(Singer, MusicS[ii].Singer) == 0)
        {
            Target[now] = MusicS[ii];
            now++;
        }
    }
    if(now != 0)
    {
        printf("%20s的歌曲有:\n",Singer);
        Print_csv(Target, now);
    }
    return now;
}

// print csv
void Print_csv(Music *Tar, int len)
{
    if(len == 0)    return ;
    int ii = 0;
    printf("╔");
    Print_csv_row(5);
    printf("╦");
    Print_csv_row(20);
    printf("╦");
    Print_csv_row(20);
    printf("╦");
    Print_csv_row(20);
    printf("╗\n");
    for(ii = 0; ii < (len-1); ii++)
    {
        printf("║%5d║%20s║%20s║%20d║\n", ii, Tar[ii].Name, Tar[ii].Singer, Tar[ii].Time);
        printf("╠");
        Print_csv_row(5);
        printf("╬");
        Print_csv_row(20);
        printf("╬");
        Print_csv_row(20);
        printf("╬");
        Print_csv_row(20);
        printf("╣\n");
    }
    printf("║%5d║%20s║%20s║%20d║\n", ii, Tar[ii].Name, Tar[ii].Singer, Tar[ii].Time);
    printf("╚");
    Print_csv_row(5);
    printf("╩");
    Print_csv_row(20);
    printf("╩");
    Print_csv_row(20);
    printf("╩");
    Print_csv_row(20);
    printf("╝\n");
}
// ╔ ═ ╦ ═ ╗
// ║   ║   ║
// ╠ ═ ╬ ═ ╣
// ║   ║   ║
// ╚ ═ ╩ ═ ╝

// print ═ (csv row)
void Print_csv_row(int len)
{
    int ii = 0;
    for(ii = 0; ii < len; ii++)
        printf("═");
}

int main()
{
    Song_num = Read_csv(MusicS);
    char songwriter[40];
    printf("请输入想要搜索的歌曲作者\nPlease enter the songwriter you want to search for!\n");
    scanf("%s",songwriter);
    // printf("19:%d\n",Song_num);
    // printf("20:%s,%s,%d\n", MusicS[0].Name, MusicS[0].Singer, MusicS[0].Time);
    if(Search(songwriter)==0)       printf("Sorry! The author's repertoire was not found in the library!\n");
}