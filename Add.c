#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include"Write_csv.c"

extern Music MusicS[10000];                
extern int Song_num;                      

void Add();

// Add songs in the system
void Add()
{
	char name[60],singer[30];
	int time;
	printf("Ո�I������Ҫ��ӵĸ�����Ϣ\nPlease enter the song information to be added:\n");
	printf("Name:");
	scanf("%[^\n]",name);	
	fflush(stdin); 
	
	printf("Singer:");
	scanf("%[^\n]",singer);
	fflush(stdin);
	  
	printf("Time:");
	scanf("%d",&time);		//Input song information(song??name??time)
	fflush(stdin);
	
	strcpy(MusicS[Song_num].Name,name);	
	strcpy(MusicS[Song_num].Singer,singer);
	MusicS[Song_num].Time=time;			//Assign value to array

	//Judge whether to add success or not
	if(strcmp(MusicS[Song_num].Name,name)==0 && strcmp(MusicS[Song_num].Singer,singer)==0 && MusicS[Song_num].Time==time)
	{
		printf("��ӳɹ�!|Added successfully!\n");		
		Song_num++;	
		Write_csv(MusicS);	
	}else{
		printf("���ʧ��!|Add failed!\n");
	} 

	system("pause");
}
