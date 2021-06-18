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
//	size_t n ═ sizeof buf; /* Take the size not the length. */
//	size_t n2 ═ sizeof singer; /* Take the size not the length. */
//	size_t n3 ═ sizeof songName; /* Take the size not the length. */
//	size_t n4 ═ sizeof count; /* Take the size not the length. */
//	memset(buf, '\0', n);
//	memset(singer, '\0', n2);
//	memset(songName, '\0', n3);
	//memset(count, '\0', n4);
	
	/*puts("════════════════════歡迎來到音樂播放器首頁═════════════════");
	printf("                 功能介紹                   \n");
	printf("Add            啟用新增功能  格式(演唱者,歌名,歌曲長度)\n");
	printf("Delete         啟用新增功能  格式(演唱者,歌名,歌曲長度)\n");
	printf("Modify         啟用新增功能  格式(演唱者,歌名,歌曲長度)\n");
	printf("Search         啟用新增功能  格式(演唱者,歌名,歌曲長度)\n");
	printf("Show all songs 啟用新增功能  格式(演唱者,歌名,歌曲長度)\n");
	printf("Random Play    啟用新增功能  格式(演唱者,歌名,歌曲長度)\n");
	puts("═══════════════════════════════════════════════════════════");*/
	
//	printf("請輸入想做的事件");
	//system("chcp 936");
	system("cls");
	Song_num = Read_csv(MusicS);
	printf("您選擇了 %s 功能\n",buf);
	
	if(stricmp(buf, "Add") == 0)																//Add
	{
		count++;
		printf("add check\n");
		fflush(stdin); // 清除輸入緩衝區
		puts("請以(,)為分隔輸入(演唱者、歌名、歌曲長度) ex.( Butter, BTS, 222 )");
		scanf("%[^,],%[^,],%d",singer,songName,&sLong);
		printf("singer═ %s, songName═ %s, sLong═ %d  數值測試\n",singer,songName,sLong);		//test scanf value
		//Add(singer,songName,sLong);			//預留接口 
		Song_num = Read_csv(MusicS);			//更新同步表格
		return 1;
	}
	else if(stricmp(buf, "Delete") == 0)														//Delete
	{
		printf("delete check\n");
		fflush(stdin); // 清除輸入緩衝區
		puts("請以(,)為分隔輸入(演唱者、歌名、歌曲長度) ex.( Butter, BTS, 222 )");
		scanf("%[^,],%[^,],%d",singer,songName,&sLong);
		printf("singer═ %s, songName═ %s, sLong═ %d  數值測試\n",singer,songName,sLong);		//test scanf value
		//Delete(singer,songName,sLong);			//預留接口 
		Song_num = Read_csv(MusicS);			//更新同步表格
		return 2;
	}
	else if(stricmp(buf, "Modify") == 0)														//Modify
	{
		printf("Modify check\n");
		fflush(stdin);
		puts("請以(,)為分隔輸入(演唱者、歌名、歌曲長度) ex.( Butter , BTS, 222 )");
		scanf("%[^,],%[^,],%d",singer,songName,&sLong);
		printf("singer═ %s, songName═ %s, sLong═ %d  數值測試\n",singer,songName,sLong);		//test scanf value
		//Modify(singer,songName,sLong);			//預留接口 
		Song_num = Read_csv(MusicS);			//更新同步表格
		return 3;
	}
	else if(stricmp(buf, "Search") == 0)														//Search
	{
		//printf("Search check\n");
		puts("Please enter Singer's name! ex.( Butter )");
		scanf("%[^\n]",singer);
		fflush(stdin);
		//printf("singer═ %s  數值測試\n",singer);		//test scanf value
		Search(singer);							//預留接口 
		return 4;
	}
	else if(stricmp(buf, "Show all songs") == 0)											//Show all songs
	{
		//Song_num = Read_csv(MusicS);
		//printf("Show all songs check\n");
		fflush(stdin);
		Show_all();							//預留接口 
		return 5;
	}
	else if(stricmp(buf, "Random Play") == 0)												//Random Play
	{
		printf("Random Play check\n");
		fflush(stdin);
		//RandomPlay();								//預留接口 
		return 6;
	}
	else if(stricmp(buf, "Show Head") == 0)			// Hidden function
	{
		//printf("Exit check\n");
		int NUM;
		printf("Please enter the number of songs to display at the top:");
		scanf("%d",&NUM);
		Show_head(NUM);							//預留接口 
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
		printf("沒有您輸入的 %s 功能\n請重新輸入\n",buf);
		fflush(stdin); // 清除輸入緩衝區
		return -1;
	}
}

int main(){
	system("chcp 936");
	
	
	while(1){
		char act[25];
		system("cls");
		puts(  "╔═══════════════════════════歡迎來到音樂播放器首頁════════════════════════════╗");
		printf("║ 輸入(大小寫無別)　　　　　　　　功能介紹　　　　　　　格式要求　　　　　　　║\n");
		printf("║ Ａｄｄ　　　　　　　　　　　　啟用新增功能　格式（演唱者,歌名,歌曲長度）　　║\n");
		printf("║ Ｄｅｌｅｔｅ　　　　　　　　　刪除歌曲功能　格式（演唱者,歌名,歌曲長度）　　║\n");
		printf("║ Ｍｏｄｉｆｙ　　　　　　　　　修改歌曲功能　格式（演唱者,歌名,歌曲長度）　　║\n");
		printf("║ Ｓｅａｒｃｈ　　　　　　　　　搜尋歌曲功能　格式（演唱者,歌名,歌曲長度）　　║\n");
		printf("║ Ｓｈｏｗ　ａｌｌ　Ｓｏｎｇｓ　顯示音樂列表　　　　　　　　　　　　　　　　　║\n");
		printf("║ Ｒａｎｄｏｍ　Ｐｌａｙ　　　　隨機撥放　　　　　　　　　　　　　　　　　　　║\n");
		printf("║ Ｅｘｉｔ　　　　　　　　　　　離開程式　　　　　　　　　　　　　　　　　　　║\n");
		puts(  "╚═════════════════════════════════════════════════════════════════════════════╝");
		printf("請輸入想執行的事件\n");
		scanf("%[^\n]",act);
		fflush(stdin);
		if(Menu(act)==0)		break;
	}	

	return 0;
}
