#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "Init.c"
//#include "Read_csv.c"
#define SWAP(x, y, t) { (t) = (x) ; (x) = (y) ; (y) = (t);}


extern Music MusicS[10000];                // Global var. Using to save songs' information in array type.  
extern int Song_num;                       // The number of songs in csv.

int Search(char*);
void Print_csv(Music*, int, int);
void Print_csv_row(int);
void Show_all();

// Query the input of the singer in total which songs will be printed after sorting the songs.
int Search(char *Sin)
{
    Music Target[10000];
    int ii = 0, now = 0;
    for(ii = 0; ii < Song_num; ii++)
    {
        if(strcmp(Sin, MusicS[ii].Singer) == 0)
        {
            Target[now] = MusicS[ii];
            now++;
        }
    }
    if(now != 0)
    {
        printf("%s�ĸ�����:\n",Sin);
        Print_csv(Target, now, now);
    }
    else
    {
        printf("������˼�� �����ڲ�����������ߵ���Ŀ��\n");
        printf("Sorry! The author's repertoire was not found in the library!\n");
    }
    system("pause");
    return now;
}

// Show songs which are the head of lists.
void Show_head(int num)
{
    Print_csv(MusicS, num, num);
    system("pause");
}

void Show_tail(int num)
{
    Print_csv(MusicS,  num, Song_num);
    system("pause");
}

// Show all songs.
void Show_all()
{
    //Print_csv(MusicS, Song_num);
    Music SHOW[10000],temp;
    // Sort this.
    for(int i=0;i<Song_num;i++)
    {
        SHOW[i]=MusicS[i];
    }
    int ii,jj;
    // bubble sort
    for(ii = 0; ii < Song_num;ii++)
    {
        for(jj = ii + 1;jj < Song_num;jj++)
        {
            if(strcmp(SHOW[ii].Singer , SHOW[jj].Singer) > 0)   // if the char in string is larger (Z>A) 
                SWAP(SHOW[ii],SHOW[jj],temp);                   // SWAP
        }
    }
    Print_csv(SHOW, Song_num, Song_num);
    system("pause");
}

// print csv
void Print_csv(Music *Tar,int len, int End)
{
    if(len == 0)    return ;
    int ii = 0;
    printf("�X");
    Print_csv_row(5);
    printf("�j");
    Print_csv_row(60);
    printf("�j");
    Print_csv_row(30);
    printf("�j");
    Print_csv_row(10);
    printf("�[\n");
    printf("�U%5s�U%60s�U%30s�U%10s�U\n", "No.", "Song", "Singer", "Time");
    printf("�d");
    Print_csv_row(5);
    printf("�p");
    Print_csv_row(60);
    printf("�p");
    Print_csv_row(30);
    printf("�p");
    Print_csv_row(10);
    printf("�g\n");
    for(ii = End - len; ii < (End-1); ii++)
    {
        printf("�U%5d�U%60s�U%30s�U%10d�U\n", ii+1, Tar[ii].Name, Tar[ii].Singer, Tar[ii].Time);
        printf("�d");
        Print_csv_row(5);
        printf("�p");
        Print_csv_row(60);
        printf("�p");
        Print_csv_row(30);
        printf("�p");
        Print_csv_row(10);
        printf("�g\n");
    }
    printf("�U%5d�U%60s�U%30s�U%10d�U\n", ii+1, Tar[ii].Name, Tar[ii].Singer, Tar[ii].Time);
    printf("�^");
    Print_csv_row(5);
    printf("�m");
    Print_csv_row(60);
    printf("�m");
    Print_csv_row(30);
    printf("�m");
    Print_csv_row(10);
    printf("�a\n");
    printf("\n");           // do not delete this.Or it will make something wrong.
}
// �X �T �j �T �[
// �U   �U   �U
// �d �T �p �T �g
// �U   �U   �U
// �^ �T �m �T �a

// print �T (csv row)
void Print_csv_row(int len)
{
    int ii = 0;
    for(ii = 0; ii < len; ii++)
        printf("�T");
}

// int main()
// {
//     Song_num = Read_csv(MusicS);
//     char Sin[30];
//     printf("��������Ҫ�����ĸ�������\nPlease enter the songwriter you want to search for!\n");
//     scanf("%[^\n]",&Sin);
//     fflush(stdin); // ���ݔ�뾏�n�^
//     printf("20:%s\n",Sin);
//     Search(Sin);     
//     //Show_all();
//     //printf("%s, %s, %d, %d, %d, %d\n","����", MusicS[86].Singer, "����", MusicS[86].Singer, strcmp("����", MusicS[86].Singer), wcscmp("����", MusicS[86].Singer));
// }