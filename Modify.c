#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include"Write_csv.c"

extern Music MusicS[10000];                
extern int Song_num;    

void Modify();

// Modify songs in the system
void Modify()
{
	char name[60],singer[30],part[20];
	int time,point = 0,ii,jj;
	printf("Ո�I������Ҫ���ĵĸ�����Ϣ\nPlease enter the song information to be modified:\n");
	printf("Name:");
	scanf("%[^\n]",name);
	fflush(stdin);
	
	printf("Singer:");
	scanf("%[^\n]",singer);
	fflush(stdin);
	  
	printf("Time:");
	scanf("%d",&time);		//Input song information(song or name or time)
	fflush(stdin);
	
	for(ii=0;ii<Song_num;ii++)		//Find the corresponding information in the array
	{
		if( strcmp(MusicS[ii].Name,name)==0 && strcmp(MusicS[ii].Singer,singer)==0 && MusicS[ii].Time==time)
		{
			char changed[60];
			printf("Ոݔ��Ҫ�޸ĵę�λ|The part that needs to be modified is(song or singer or time):");
			scanf("%s",part);
			fflush(stdin);
			if(strcmp(part,"song")==0){
				printf("���ĳ�|To be changed to:");
				scanf("%s",changed);
				fflush(stdin);
				strcpy(MusicS[ii].Name,changed);	
				printf("�޸ĳɹ�!\nModified successfully!\n");
			}else if(strcmp(part,"singer")==0){
				printf("���ĳ�|To be changed to:");
				scanf("%s",changed);
				fflush(stdin);
				strcpy(MusicS[ii].Singer,changed);	
				printf("�޸ĳɹ�!\nModified successfully!\n");
			}else if(strcmp(part,"time")==0){
				int time2;
				printf("���ĳ�|To be changed to:");
				scanf("%d",&time2);
				fflush(stdin);
				MusicS[ii].Time=time2;
				printf("�޸ĳɹ�!\nModified successfully!\n");
			}else{
				printf("��δݔ��ָ���ę�λ|You did't enter the specified part!\n");
			}
			point++;
			break;
		}	
	} 

	if(point == 0)
	{
		printf("�o���ڔ��������ҵ����ϵĸ���\nThe info you entered cannot match any song in this database.\n");
	}
	
	Write_csv(MusicS);
	system("pause");
}
