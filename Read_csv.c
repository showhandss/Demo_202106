#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Init.c"

// import the exact csv(return the number of songs  Or fail by -1)
int Read_csv(Music *ALL)
{
                 
    FILE* fp = NULL;                // import File
    fp = fopen("D:\\gitmaker\\Demo_202106\\MUSIC.csv", "rt");
    if (fp != NULL)
    {
        printf("Open success!\n");
        char IN[100];
        
        int Current = 0;            // current number
        while((fscanf(fp, "%[^\n]", IN))!=EOF)
        {
            strcpy(ALL[Current].Name, strtok(IN, ","));
            strcpy(ALL[Current].Singer, strtok(NULL, ","));
            ALL[Current].Time = atoi(strtok(NULL, "\n"));
            printf("%s,%s,%d\n",ALL[Current].Name,ALL[Current].Singer,ALL[Current].Time);
            Current++;              // which means the info was imported successfully.
            char IN[100];
        }
        printf("%s\n",IN);
		fclose(fp);
		fp = NULL;
        return Current;
    }
    else
    {
        printf("Cannot find the List of Songs!\nPlease find out the exact file.\n");
        fclose(fp);
        return 0;
    }
}