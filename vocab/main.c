#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    FILE *vocab_file = fopen("vocab.txt", "r");
    char line[100];
    char vocab[100][100];
    int i, j, n = 0;
    char r;
    if (vocab_file!=NULL){
        //printf("File opened with succes.\n");
        while (fgets(line, 100, vocab_file)){
            if (strcmp(line, "\n"))
            {
                //printf("%s", line);
                for (i=0;i<strlen(line);i++){
                    vocab[i][n]=line[i];
                }
                vocab[i+1][n]='\0';
                n++;
            }
        }
        /*
        printf(" ----------------- \n");
        for (i=0;i<n;i++)
        {
            j = 0;
            while (vocab[j][i]!='\n')
            {
                printf("%c", vocab[j][i]);
                j++;
            }
            printf("\n");
        }*/
        do
        {
            system("cls");
            srand(time(NULL));
            i = rand()%n;
            //printf(" --------------- \n");
            j=0;
            while (vocab[j][i]!='\n')
            {
                printf("%c", vocab[j][i]);
                j++;
            }
            printf("\n");
            scanf("%c", &r);
        }while (r!='e');
    }
    else
        printf("Error on opening the file.\n");
    return 0;
}
