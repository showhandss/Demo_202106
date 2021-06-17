#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Read_csv.c"

// Music MusicS[10000];                // Global var. Using to save songs' information in array type.  
// int Song_num;                       // The number of songs in csv.

int Search();
void Print_csv(Music*, int);
void Print_csv_row(int);
void Show_all();

// Query the input of the singer in total which songs will be printed after sorting the songs.
int Search()
{
    char Sin[30];
    printf("请输入想要搜索的歌曲作者\nPlease enter the songwriter you want to search for!\n");
    scanf("%[^\n]",Sin);
    printf("20:%s\n",Sin);
    Music Target[10000];
    int ii = 0, now = 0;
    for(ii = 0; ii < Song_num; ii++)
    {
        if(ii == 86)
        {
            printf("%s, %s, %d, %d, %d\n",Sin,MusicS[ii].Singer,Sin,MusicS[ii].Singer,strcmp(Sin, MusicS[ii].Singer));
        }
        if(strcmp(Sin, MusicS[ii].Singer) == 0)
        {
            Target[now] = MusicS[ii];
            now++;
        }
    }
    if(now != 0)
    {
        printf("%-20s的歌曲有:\n",Sin);
        Print_csv(Target, now);
    }
    else
    {
        printf("不好意思！ 曲库内不存在这个作者的曲目。\n");
        printf("Sorry! The author's repertoire was not found in the library!\n");
    }
    return now;
}

// Show all songs.
void Show_all()
{
    //Print_csv(MusicS, Song_num);
    Print_csv(MusicS, 300);
}

// print csv
void Print_csv(Music *Tar, int len)
{
    if(len == 0)    return ;
    int ii = 0;
    printf("╔");
    Print_csv_row(5);
    printf("╦");
    Print_csv_row(60);
    printf("╦");
    Print_csv_row(30);
    printf("╦");
    Print_csv_row(10);
    printf("╗\n");
    printf("║%5s║%60s║%30s║%10s║\n", "No.", "Song", "Singer", "Time");
    printf("╠");
    Print_csv_row(5);
    printf("╬");
    Print_csv_row(60);
    printf("╬");
    Print_csv_row(30);
    printf("╬");
    Print_csv_row(10);
    printf("╣\n");
    for(ii = 0; ii < (len-1); ii++)
    {
        if(Tar[ii].Singer[0] < 0)               // Chinese Singers
        {
            printf("║%5d║%60s║", ii+1, Tar[ii].Name);
            if(strlen(Tar[ii].Singer)  == 9)
                printf("%33s║%10d║\n", Tar[ii].Singer, Tar[ii].Time);
            else if(strlen(Tar[ii].Singer)  == 6)
                printf("%32s║%10d║\n", Tar[ii].Singer, Tar[ii].Time);
        }
        else                                    // English Singers
            printf("║%5d║%60s║%30s║%10d║\n", ii+1, Tar[ii].Name, Tar[ii].Singer, Tar[ii].Time);
        printf("╠");
        Print_csv_row(5);
        printf("╬");
        Print_csv_row(60);
        printf("╬");
        Print_csv_row(30);
        printf("╬");
        Print_csv_row(10);
        printf("╣\n");
    }
    printf("║%5d║%60s║%30s║%10d║\n", ii+1, Tar[ii].Name, Tar[ii].Singer, Tar[ii].Time);
    printf("╚");
    Print_csv_row(5);
    printf("╩");
    Print_csv_row(60);
    printf("╩");
    Print_csv_row(30);
    printf("╩");
    Print_csv_row(10);
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
    // printf("19:%d\n",Song_num);
    // printf("20:%s,%s,%d\n", MusicS[0].Name, MusicS[0].Singer, MusicS[0].Time);
    Search();     
    //Show_all();
    //printf("%s, %s, %d, %d, %d, %d\n","黎明", MusicS[86].Singer, "黎明", MusicS[86].Singer, strcmp("黎明", MusicS[86].Singer), wcscmp("黎明", MusicS[86].Singer));
}