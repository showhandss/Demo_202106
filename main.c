#include <stdio.h>
#include <stdlib.h>
#include "Init.c"
#include "Read_csv.c"
#include "CD_search.c"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int Menu(char *buf)
{
	//char buf[25];
	char singer[100];
	char songName[100];
	int sLong;
	int count = 0;
//	size_t n �T sizeof buf; /* Take the size not the length. */
//	size_t n2 �T sizeof singer; /* Take the size not the length. */
//	size_t n3 �T sizeof songName; /* Take the size not the length. */
//	size_t n4 �T sizeof count; /* Take the size not the length. */
//	memset(buf, '\0', n);
//	memset(singer, '\0', n2);
//	memset(songName, '\0', n3);
	//memset(count, '\0', n4);
	
	/*puts("�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�gӭ��������������퓨T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T");
	printf("                 ���ܽ�B                   \n");
	printf("Add            ������������  ��ʽ(�ݳ���,����,�����L��)\n");
	printf("Delete         ������������  ��ʽ(�ݳ���,����,�����L��)\n");
	printf("Modify         ������������  ��ʽ(�ݳ���,����,�����L��)\n");
	printf("Search         ������������  ��ʽ(�ݳ���,����,�����L��)\n");
	printf("Show all songs ������������  ��ʽ(�ݳ���,����,�����L��)\n");
	printf("Random Play    ������������  ��ʽ(�ݳ���,����,�����L��)\n");
	puts("�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T");*/
	
//	printf("Ոݔ���������¼�");
	//system("chcp 936");
	system("cls");
	Song_num = Read_csv(MusicS);
	printf("���x���� %s ����\n",buf);
	
	if(stricmp(buf, "Add") == 0)																//Add
	{
		count++;
		printf("add check\n");
		fflush(stdin); // ���ݔ�뾏�n�^
		puts("Ո��(,)��ָ�ݔ��(�ݳ��ߡ������������L��) ex.( Butter, BTS, 222 )");
		scanf("%[^,],%[^,],%d",singer,songName,&sLong);
		printf("singer�T %s, songName�T %s, sLong�T %d  ��ֵ�yԇ\n",singer,songName,sLong);		//test scanf value
		//Add(singer,songName,sLong);			//�A���ӿ� 
		Song_num = Read_csv(MusicS);			//����ͬ�����
		return 1;
	}
	else if(stricmp(buf, "Delete") == 0)														//Delete
	{
		printf("delete check\n");
		fflush(stdin); // ���ݔ�뾏�n�^
		puts("Ո��(,)��ָ�ݔ��(�ݳ��ߡ������������L��) ex.( Butter, BTS, 222 )");
		scanf("%[^,],%[^,],%d",singer,songName,&sLong);
		printf("singer�T %s, songName�T %s, sLong�T %d  ��ֵ�yԇ\n",singer,songName,sLong);		//test scanf value
		//Delete(singer,songName,sLong);			//�A���ӿ� 
		Song_num = Read_csv(MusicS);			//����ͬ�����
		return 2;
	}
	else if(stricmp(buf, "Modify") == 0)														//Modify
	{
		printf("Modify check\n");
		fflush(stdin);
		puts("Ո��(,)��ָ�ݔ��(�ݳ��ߡ������������L��) ex.( Butter , BTS, 222 )");
		scanf("%[^,],%[^,],%d",singer,songName,&sLong);
		printf("singer�T %s, songName�T %s, sLong�T %d  ��ֵ�yԇ\n",singer,songName,sLong);		//test scanf value
		//Modify(singer,songName,sLong);			//�A���ӿ� 
		Song_num = Read_csv(MusicS);			//����ͬ�����
		return 3;
	}
	else if(stricmp(buf, "Search") == 0)														//Search
	{
		//printf("Search check\n");
		puts("Please enter Singer's name! ex.( Butter )");
		scanf("%[^\n]",singer);
		fflush(stdin);
		//printf("singer�T %s  ��ֵ�yԇ\n",singer);		//test scanf value
		Search(singer);							//�A���ӿ� 
		return 4;
	}
	else if(stricmp(buf, "Show all songs") == 0)											//Show all songs
	{
		//Song_num = Read_csv(MusicS);
		//printf("Show all songs check\n");
		fflush(stdin);
		Show_all();							//�A���ӿ� 
		return 5;
	}
	else if(stricmp(buf, "Random Play") == 0)												//Random Play
	{
		printf("Random Play check\n");
		fflush(stdin);
		//RandomPlay();								//�A���ӿ� 
		return 6;
	}
	else if(stricmp(buf, "Show Head") == 0)			// Hidden function
	{
		//printf("Exit check\n");
		int NUM;
		printf("Please enter the number of songs to display at the top:");
		scanf("%d",&NUM);
		Show_head(NUM);							//�A���ӿ� 
		return 7;
	}
	else if(stricmp(buf, "Exit") == 0)														//Exit
	{
		//printf("Exit check\n");
		printf("Byebye\n");
		return 0;
	}
	else																						//Null
	{
		system("cls");
		printf("�]����ݔ��� %s ����\nՈ����ݔ��\n",buf);
		fflush(stdin); // ���ݔ�뾏�n�^
		return -1;
	}
}

int main(){
	system("chcp 936");
	
	
	while(1){
		char act[25];
		system("cls");
		puts(  "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�gӭ��������������퓨T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[");
		printf("�U ݔ��(��С���o�e)�������������������ܽ�B����������������ʽҪ�󡡡������������U\n");
		printf("�U ����䡡���������������������������������ܡ���ʽ���ݳ���,����,�����L�ȣ������U\n");
		printf("�U �ģ�����塡�����������������h���������ܡ���ʽ���ݳ���,����,�����L�ȣ������U\n");
		printf("�U �ͣ������������������������޸ĸ������ܡ���ʽ���ݳ���,����,�����L�ȣ������U\n");
		printf("�U �ӣ����衡�����������������ь��������ܡ���ʽ���ݳ���,����,�����L�ȣ������U\n");
		printf("�U �ӣ��������졡�ӣ�����@ʾ�����б����������������������������������U\n");
		printf("�U �ң������У������������S�C�ܷš��������������������������������������U\n");
		printf("�U �ţ���������������������������x�_��ʽ���������������������������������������U\n");
		puts(  "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a");
		printf("Ոݔ������е��¼�\n");
		scanf("%[^\n]",act);
		fflush(stdin);
		if(Menu(act)==0)		break;
	}	

	return 0;
}
