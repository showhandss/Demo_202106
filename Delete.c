#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include"Write_csv.c"

extern Music MusicS[10000];                
extern int Song_num;    

void Delete(); 

// Delete songs in the system 
void Delete()
{
	int c=0;
	char name[60],singer[30];
	int time,point,ii,jj;
	printf("Ո�I������Ҫ�h���ĸ�����Ϣ\nPlease enter the song information to be deleted:\n");
	printf("Name:");
	scanf("%[^\n]",name);
	fflush(stdin);
	
	printf("Singer:");
	scanf("%[^\n]",singer);
	fflush(stdin);
	  
	printf("Time:");
	scanf("%d",&time);		//Input song information(song??name??time)
	fflush(stdin);
	
	for(ii=0;ii<Song_num;ii++)		//Find the corresponding information in the array
	{
		if( strcmp(MusicS[ii].Name,name)==0 && strcmp(MusicS[ii].Singer,singer)==0 && MusicS[ii].Time==time)
		{
			for(jj=ii;jj<Song_num;jj++)
			{
				strcpy(MusicS[jj].Name,MusicS[jj+1].Name);	
				strcpy(MusicS[jj].Singer,MusicS[jj+1].Singer);
				MusicS[jj].Time=MusicS[jj+1].Time;					
			}
			printf("�h���ɹ�!\nDeleted successfully!\n");
			Song_num--;
			c++;
			Write_csv(MusicS);
			break;
		}		
	}
	if(c==0)
		printf("�o���ڔ��������ҵ����ϵĸ���\nThe info you entered cannot match any song in this database.\n");
	
	
	system("pause");
}
