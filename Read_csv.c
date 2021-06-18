#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Music MusicS[10000];                // Global var. Using to save songs' information in array type.  
int Song_num;                       // The number of songs in csv.

// import the exact csv(return the number of songs  Or fail by -1)
int Read_csv(Music *ALL)
{
    //system("chcp 65001");       
    FILE* fp = NULL;                // import File
    fp = fopen("D:\\gitmaker\\Demo_202106\\MUSIC.csv", "rt");
    if (fp != NULL)
    {
        printf("Open success!\n");
        char IN[100];
        
        int Current = 0;            // current number
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
            //printf("%s|%s|%d\n",ALL[Current].Name,ALL[Current].Singer,ALL[Current].Time);
            Current++;              // which means the info was imported successfully.
        }
		fclose(fp);
		fp = NULL;
        printf("There are %d songs in all.\n",Current);
        return Current;
    }
    else
    {
        printf("Cannot find the List of Songs!\nPlease find out the exact file.\n");
        fclose(fp);
        return 0;
    }
}