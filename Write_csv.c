#include<stdio.h>
#include<stdlib.h>
#include<string.h>

extern Music MusicS[10000];               
extern int Song_num;                     

void Write_csv(Music *);

//Write array to csv file
void Write_csv(Music *ALL)
{
	int ii,jj;
	FILE* fp=NULL;
	fp=fopen(INPUT_FILE,"w+");//File's name to be saved
	 
	for(ALL=MusicS;ALL<MusicS+Song_num;ALL++)
	{
		int t1=0,t2=0;
		char douhao=',';
		
		char buff1[60]={0};
		for(ii=0;ii<strlen(ALL->Name);ii++)
		{
			if(ALL->Name[ii]==douhao)		//Determine whether ',' in the string
				t1=1;
		}
		if(t1==1){		// If there are,The beginning and end of the string should be added to " ".
			buff1[0]='\"';
			for(ii=0;ii<strlen(ALL->Name);ii++)
			{
				buff1[ii+1]=ALL->Name[ii];
			}
			buff1[strlen(ALL->Name)+1]='\"';
			buff1[strlen(ALL->Name)+2]=',';
		}else{
			strcpy(buff1,ALL->Name);
			buff1[strlen(buff1)]=',';
		}
		fprintf(fp,buff1);
		
		char buff2[30]={0};
		for(ii=0;ii<strlen(ALL->Singer);ii++)
		{
			if(ALL->Singer[ii]==douhao)
				t2=1;
		}
		if(t2==1){
			buff2[0]='\"';
			for(ii=0;ii<strlen(ALL->Singer);ii++)
			{
				buff2[ii+1]=ALL->Singer[ii];
			}
			buff2[strlen(ALL->Singer)+1]='\"';
			buff2[strlen(ALL->Singer)+2]=',';
		}else{
			strcpy(buff2,ALL->Singer);
			buff2[strlen(buff2)]=',';
		}
		fprintf(fp,buff2);
	
		int time=ALL->Time;
		char buff3[20]={0};
    	itoa(time,buff3,10);	//A is written into buff in decimal form
    	buff3[strlen(buff3)]=',';
		fprintf(fp,buff3);
		
		fprintf(fp,"\n");
	}
	
	fclose(fp);
}
