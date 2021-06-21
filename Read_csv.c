#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Music MusicS[10000];                // Global var. Using to save songs' information in array type.  
int Song_num;                       // The number of songs in csv.


// import the exact csv(return the number of songs  Or fail by -1)
int Read_csv(Music *ALL)
{       
    FILE* fp = NULL;                // import File
    fp = fopen(INPUT_FILE, "rt");
    if (fp != NULL)
    {
        printf("打開成功!|Open success!\n");
        char IN[100];
        
        int Current = 0;            // current number
        // memset(SingerS,0,sizeof(SL)*4);
        // Singer_num = 0;
        while((fgets(IN, 100, fp))!=NULL)
        {
            int name_len;           // calculate the length of song name to deal with quotation mark of singer
            if(IN[0]!='\"')         // With no quotation marks
            {
                strcpy(ALL[Current].Name, strtok(IN, ","));         
                name_len = strlen(ALL[Current].Name) + 1;
            }         
            else                    // With quotation marks
            {
                strcpy(ALL[Current].Name, strtok(IN, "\""));
                name_len = strlen(ALL[Current].Name) + 3;
            }                            
            
            if(IN[name_len]!='\"')  // With no quotation marks
            {
                strcpy(ALL[Current].Singer, strtok(NULL, ","));         
            }         
            else                    // With quotation marks
            {
                strcpy(ALL[Current].Singer, strtok(NULL, "\""));
            }  
            
            ALL[Current].Time = atoi(strtok(NULL, ","));
            Current++;              // which means the info was imported successfully.

            /////////////////////////////////////////////////////////////////////////

            // int ii = 0, isExist = 0;
            // for(ii = 0; ii < Singer_num;ii++)
            // {
            //     if(strcmp(ALL[Current].Singer, SingerS[ii].Singer) == 0)
            //     {
            //         isExist++;
            //         break;
            //     }
            // }
            // if(isExist!=0)
            // {
            //     SingerS[ii].MusicL[SingerS[ii].MusicN] = Current;
            //     SingerS[ii].MusicN++;
            // }
            // else
            // {
            //     SingerS[Singer_num].MusicL[0]  = Current;
            //     SingerS[Singer_num].MusicN = 1;
            //     strcpy(SingerS[Singer_num].Singer , ALL[Current].Singer);
            //     Singer_num++;
            // }
        }
		fclose(fp);
		fp = NULL;
        printf("此數據庫總共包含%d首歌。\nThere are %d songs in all.\n",Current,Current);
        return Current;
    }
    else
    {
        printf("找不到歌曲列表!请找出确切的文件。\n");
        printf("Cannot find the List of Songs!Please find out the exact file.\n");
        fclose(fp);
        return 0;
    }
}