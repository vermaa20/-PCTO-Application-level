#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 4

int main(void)
{
 FILE *fp = fopen("log.v.2.0.txt", "r");
 char c;
 char tester[MAX];
 int i = 0, j = 0, prova = 0;
 int l = 0;

 if (fp == NULL) {
 printf("File opening failed");

 return EXIT_FAILURE;
 }
 else {
    //printf("Data Length\n| Data Bytes (hex)\n|  |\n+  -+ -- -- -- -- -- -- --\n");
    while (!feof(fp)) {
        for(i = 0; i < 4; i++){
            fscanf(fp, "%c", &c);
            tester[i] = c;
        }
        tester[i] = '\0';
        if(strcmp(tester, "07DF") == 0){
            fscanf(fp, "%c", &c);
            fscanf(fp, "%d", &l);
            printf("%d ", l);
            fscanf(fp, "%c", &c);
            fscanf(fp, "%c", &c);

            j = 0;

            while (j < l * 2 + l - 1) {
                fscanf(fp, "%c", &c);
                printf("%c",c);
                j++;
            }
            printf("\n");
        }

        if(strcmp(tester, "07E8") == 0){
            fscanf(fp, "%c", &c);
            fscanf(fp, "%d", &l);
            printf("%d ", l);
            fscanf(fp, "%c", &c);
            fscanf(fp, "%c", &c);

            j = 0;

            while (j < l * 2 + l - 1) {
                fscanf(fp, "%c", &c);
                printf("%c",c);
                j++;
            }
            printf("\n");
        }
    }
 }

 fclose(fp);

 return 0;
}
