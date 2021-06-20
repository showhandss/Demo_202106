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
	//char buf[25];
	char singer[100];
	char songName[100];
	int sLong;
	int count = 0;

	//system("chcp 936");
	system("cls");
	Song_num = Read_csv(MusicS);
	printf("您選擇了 %s 功能\n",buf);
	
	if(stricmp(buf, "Add") == 0)																//Add
	{
		count++;
		//printf("add check\n");
		fflush(stdin); // 清除輸入緩衝區
		Add();			//預留接口 
		Song_num = Read_csv(MusicS);			//更新同步表格
		return 1;
	}
	else if(stricmp(buf, "Delete") == 0)														//Delete
	{
		//printf("delete check\n");
		fflush(stdin); // 清除輸入緩衝區
		Delete();			//預留接口 
		Song_num = Read_csv(MusicS);			//更新同步表格
		return 2;
	}
	else if(stricmp(buf, "Modify") == 0)														//Modify
	{
		//printf("Modify check\n");
		fflush(stdin);
		Modify();			//預留接口 
		Song_num = Read_csv(MusicS);			//更新同步表格
		return 3;
	}
	else if(stricmp(buf, "Search") == 0)														//Search
	{
		char singer[30];
		//printf("Search check\n");
		puts("请输入歌手的名字！|Please enter Singer's name! (ex. Taylor Swift )");
		scanf("%[^\n]",singer);
		fflush(stdin);
		//printf("singer═ %s  數值測試\n",singer);		//test scanf value
		Search(singer);							//預留接口 
		return 4;
	}
	else if(stricmp(buf, "Show all songs") == 0)											//Show all songs
	{
		//printf("Show all songs check\n");
		fflush(stdin);
		Show_all();								//預留接口 
		return 5;
	}
	else if(stricmp(buf, "Random Play") == 0)												//Random Play
	{
		//printf("Random Play check\n");
		fflush(stdin);
		FunctionRandomSong(MusicS, Song_num);	//預留接口 
		return 6;
	}
	else if(stricmp(buf, "Show Head") == 0)			// Hidden function
	{
		//printf("Exit check\n");
		int NUM;
		printf("請鍵入想要顯示的頂端歌曲數量\nPlease enter the number of songs to display at the top:");
		scanf("%d",&NUM);
		fflush(stdin);
		Show_head(NUM);							//預留接口 
		return 7;
	}
	else if(stricmp(buf, "Show tail") == 0)			// Hidden function
	{
		//printf("Exit check\n");
		int NUM;
		printf("請鍵入想要顯示的底端歌曲數量\nPlease enter the number of songs to display at the below:");
		scanf("%d",&NUM);
		fflush(stdin);
		Show_tail(NUM);							//預留接口 
		return 8;
	}
	else if(stricmp(buf, "Exit") == 0)														//Exit
	{
		//printf("Exit check\n");
		printf("歡迎下次使用\nByebye\n");
		return 0;
	}
	else																						//Null
	{
		system("cls");
		printf("沒有您輸入的 %s 功能\n請重新輸入\n",buf);
		fflush(stdin); // 清除輸入緩衝區
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
		//INPUT_FILE = "D:\\gitmaker\\Demo_202106\\MUSIC.csv";
		INPUT_FILE = "MUSIC.csv";
	}
	
	while(1){
		char act[25];
		system("cls");
		puts(  "╔═══════════════════════════════════歡迎來到音樂播放器首頁══════════════════════════════════╗");
		printf("║ 輸入(大小寫無別)　　　　　　　　功能介紹　　　　　　　　　　　　　　格式要求　　　　　　　║\n");
		printf("║ Ａｄｄ　　　　　　　　　　　　啟用新增功能　　　　　　　　格式（演唱者,歌名,歌曲長度）　　║\n");
		printf("║ Ｄｅｌｅｔｅ　　　　　　　　　刪除歌曲功能　　　　　　　　格式（演唱者,歌名,歌曲長度）　　║\n");
		printf("║ Ｍｏｄｉｆｙ　　　　　　　　　修改歌曲功能　　　　　　　　格式（演唱者,歌名,歌曲長度）　　║\n");
		printf("║ Ｓｅａｒｃｈ　　　　　　　　　搜尋歌曲功能　　　　　　　　格式（演唱者,歌名,歌曲長度）　　║\n");
		printf("║ Ｓｈｏｗ　ａｌｌ　Ｓｏｎｇｓ　顯示音樂列表　　　　　　　　　　　　　　　　　　　　　　　　║\n");
		printf("║ Ｓｈｏｗ　ｈｅａｄ　　　　　　顯示最开头的几首音樂　　　　　　　格式（歌曲数目）　　　　　║\n");
		printf("║ Ｓｈｏｗ　ｔａｉｌ　　　　　　顯示最末尾的几首音樂　　　　　　　格式（歌曲数目）　　　　　║\n");
		printf("║ Ｒａｎｄｏｍ　Ｐｌａｙ　　　　隨機撥放　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
		printf("║ Ｅｘｉｔ　　　　　　　　　　　離開程式　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
		puts(  "╚═══════════════════════════════════════════════════════════════════════════════════════════╝");
		printf("請輸入想執行的事件\n");
		scanf("%[^\n]",act);
		fflush(stdin);
		if(Menu(act)==0)		break;
	}	

	return 0;
}
