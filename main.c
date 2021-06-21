#include <stdio.h>
#include <stdlib.h>
#include "Init.c"
#include "Read_csv.c"
#include "CD_search.c"
#include "Random_Play.c"
#include "Write_csv.c"
#include "Add.c"
#include "Delete.c"
#include "Modify.c"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int Menu(char *buf)
{
	char singer[100];
	char songName[100];
	int sLong;
	int count = 0;

	//system("chcp 936");
	system("cls");
	printf("���x���� %s ����\n",buf);
	
	if(stricmp(buf, "Add") == 0)																//Add
	{
		Song_num = Read_csv(MusicS);
		//printf("add check\n");
		fflush(stdin); // ���ݔ�뾏�n�^
		Add();			//�A���ӿ� 
		Song_num = Read_csv(MusicS);			//����ͬ�����
		return 1;
	}
	else if(stricmp(buf, "Delete") == 0)														//Delete
	{
		Song_num = Read_csv(MusicS);
		//printf("delete check\n");
		fflush(stdin); // ���ݔ�뾏�n�^
		Delete();			//�A���ӿ� 
		Song_num = Read_csv(MusicS);			//����ͬ�����
		return 2;
	}
	else if(stricmp(buf, "Modify") == 0)														//Modify
	{
		Song_num = Read_csv(MusicS);
		//printf("Modify check\n");
		fflush(stdin);
		Modify();			//�A���ӿ� 
		Song_num = Read_csv(MusicS);			//����ͬ�����
		return 3;
	}
	else if(stricmp(buf, "Search") == 0)														//Search
	{
		Song_num = Read_csv(MusicS);
		char singer[30];
		//printf("Search check\n");
		puts("��������ֵ����֣�|Please enter Singer's name! (ex. Taylor Swift )");
		scanf("%[^\n]",singer);
		fflush(stdin);
		Search(singer);							//�A���ӿ� 
		return 4;
	}
	else if(stricmp(buf, "Show all songs") == 0)											//Show all songs
	{
		Song_num = Read_csv(MusicS);
		//printf("Show all songs check\n");
		fflush(stdin);
		Show_all();								//�A���ӿ� 
		return 5;
	}
	else if(stricmp(buf, "Random Play") == 0)												//Random Play
	{
		Song_num = Read_csv(MusicS);
		//printf("Random Play check\n");
		fflush(stdin);
		FunctionRandomSong(MusicS, Song_num);	//�A���ӿ� 
		return 6;
	}
	else if(stricmp(buf, "Show Head") == 0)			// Hidden function
	{
		Song_num = Read_csv(MusicS);
		//printf("Exit check\n");
		int NUM;
		printf("Ո�I����Ҫ�@ʾ��픶˸�������\nPlease enter the number of songs to display at the top:");
		scanf("%d",&NUM);
		fflush(stdin);
		Show_head(NUM);							//�A���ӿ� 
		return 7;
	}
	else if(stricmp(buf, "Show tail") == 0)			// Hidden function
	{
		Song_num = Read_csv(MusicS);
		//printf("Exit check\n");
		int NUM;
		printf("Ո�I����Ҫ�@ʾ�ĵ׶˸�������\nPlease enter the number of songs to display at the below:");
		scanf("%d",&NUM);
		fflush(stdin);
		Show_tail(NUM);							//�A���ӿ� 
		return 8;
	}
	else if(stricmp(buf, "Exit") == 0)														//Exit
	{
		//printf("Exit check\n");
		printf("�gӭ�´�ʹ��\nByebye\n");
		return 0;							//?^��0���� 
	}
	else																						//Null
	{
		
		printf("�]����ݔ��� %s ����\nՈ����ݔ��\n",buf);
		system("pause");
		system("cls");
		fflush(stdin); // ���ݔ�뾏�n�^
		return -1;
	}
}

int main(int argc, char* argv[]){
	system("chcp 936");			// using gbk
	
	if(argc>1)
	{
		INPUT_FILE = argv[1];
	}
	else
	{
		INPUT_FILE = "MUSIC.csv";
	}
	
	while(1){
		char act[25];
		system("cls");
		puts(  "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�gӭ��������������퓨T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[");
		printf("�U ݔ��(��С���o�e)�������������������ܽ�B������������������������������ʽҪ�󡡡������������U\n");
		printf("�U ����䡡���������������������������������ܡ�����������������ʽ���ݳ���,����,�����L�ȣ������U\n");
		printf("�U �ģ�����塡�����������������h���������ܡ�����������������ʽ���ݳ���,����,�����L�ȣ������U\n");
		printf("�U �ͣ������������������������޸ĸ������ܡ�����������������ʽ���ݳ���,����,�����L�ȣ������U\n");
		printf("�U �ӣ����衡�����������������ь��������ܡ�����������������ʽ���ݳ���,����,�����L�ȣ������U\n");
		printf("�U �ӣ��������졡�ӣ�����@ʾ�����б������������������������������������������������U\n");
		printf("�U �ӣ���������䡡�����������@ʾ�ͷ�ļ�����������������������ʽ��������Ŀ�������������U\n");
		printf("�U �ӣ����������졡�����������@ʾ��ĩβ�ļ�����������������������ʽ��������Ŀ�������������U\n");
		printf("�U �ң������У������������S�C�ܷš����������������������������������������������������U\n");
		printf("�U �ţ���������������������������x�_��ʽ�����������������������������������������������������U\n");
		puts(  "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a");
		printf("Ոݔ������е��¼�\n");
		scanf("%[^\n]",act);
		fflush(stdin);
		if(Menu(act)==0)		break;
	}	

	return 0;
}
