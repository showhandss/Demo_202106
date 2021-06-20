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
	printf("請鍵入您想要更改的歌曲信息\nPlease enter the song information to be modified:\n");
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
			printf("請輸入要修改的欄位|The part that needs to be modified is(song or singer or time):");
			scanf("%s",part);
			fflush(stdin);
			if(strcmp(part,"song")==0){
				printf("將改成|To be changed to:");
				scanf("%s",changed);
				fflush(stdin);
				strcpy(MusicS[ii].Name,changed);	
				printf("修改成功!\nModified successfully!\n");
			}else if(strcmp(part,"singer")==0){
				printf("將改成|To be changed to:");
				scanf("%s",changed);
				fflush(stdin);
				strcpy(MusicS[ii].Singer,changed);	
				printf("修改成功!\nModified successfully!\n");
			}else if(strcmp(part,"time")==0){
				int time2;
				printf("將改成|To be changed to:");
				scanf("%d",&time2);
				fflush(stdin);
				MusicS[ii].Time=time2;
				printf("修改成功!\nModified successfully!\n");
			}else{
				printf("您未輸入指定的欄位|You did't enter the specified part!\n");
			}
			point++;
			break;
		}	
	} 

	if(point == 0)
	{
		printf("無法在數據庫中找到符合的歌曲\nThe info you entered cannot match any song in this database.\n");
	}
	
	Write_csv(MusicS);
	system("pause");
}
