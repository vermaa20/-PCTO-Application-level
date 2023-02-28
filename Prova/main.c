#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 4

int main(void)
{
 FILE *fp = fopen("dati.1", "r");
 char c;
 char tester[MAX];
 int i = 0, j = 0, prova = 0;

 if (fp == NULL) {
 printf("File opening failed");

 return EXIT_FAILURE;
 }
 else {
    //printf("Data Length\n| Data Bytes (hex)\n|  |\n+  -+ -- -- -- -- -- -- --\n");
    while (prova < 3) {
        fscanf(fp, "%c", &c);
        for(i = 0; i < 4; i++){
            tester[i] = c;
            fscanf(fp, "%c", &c);
        }
        tester[i] = '\0';
        if(strcmp(tester, "FILE") == 0){
            fscanf(fp, "%c", &c);
            j = 0;
            while (j < 26) {
                fscanf(fp, "%c", &c);
                printf("%c",c);
                j++;
            }
            prova++;
            printf("\n");
        }

        if(strcmp(tester, "07E8") == 0){
            fscanf(fp, "%c", &c);
            j = 0;
            while (j < 26) {
                fscanf(fp, "%c", &c);
                printf("%c",c);
                j++;
            }
            prova++;
            printf("\n");
        }
    }
 }

 fclose(fp);

 return 0;
}
