#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 4

void lettura()
{
 FILE *fp = fopen("log.txt", "r");
 char c;
 char tester[MAX];
 int i = 0, j = 0, prova = 0, dim = 0, controlla = 0;

 if (fp == NULL) {
 printf("File opening failed");

 }
 else {
    printf("ID(hex)");
    printf("\n|    Data Length");
    printf("\n|    |  Data Bytes");
    printf("\n|    |  |");
    printf("\n+--- + -+ -- -- -- -- -- -- --\n");
    while (!feof(fp)) {

        if(controlla > 0) {
            for(i = 0; i < 3; i++){
                tester[i] = tester[i + 1];
            }
            fscanf(fp, "%c", &c);
            tester[i] = c;
        } else {
            for(i = 0; i < 4; i++){
                fscanf(fp, "%c", &c);
                tester[i] = c;
            }
            controlla = 1;
        }
        if(strcmp(tester, "07DF") == 0){
            fscanf(fp, "%c", &c);
            fscanf(fp, "%d", &dim);
            printf("%s ", tester);
            printf("%d", dim);
            fscanf(fp, "%c", &c);
            printf("%c", c);
            fscanf(fp, "%c", &c);
            j = 0;
            while (j < dim * 2 + dim - 1) {
                fscanf(fp, "%c", &c);
                printf("%c",c);
                j++;
            }
            printf("\n");
        }

        if(strcmp(tester, "07E8") == 0){
            fscanf(fp, "%c", &c);
            fscanf(fp, "%d", &dim);
            printf("%s ", tester);
            printf("%d", dim);
            fscanf(fp, "%c", &c);
            printf("%c", c);
            fscanf(fp, "%c", &c);
            j = 0;
            while (j < dim * 2 + dim - 1) {
                fscanf(fp, "%c", &c);
                printf("%c",c);
                j++;
            }
            printf("\n");
        }
    }
 }

 fclose(fp);

}

void scrittura()
{
 FILE *fp = fopen("info.xls", "w");
 char c;
 char tester[MAX];
 int i = 0, j = 0, prova = 0, dim = 0, controlla = 0;

 if (fp == NULL) {
 printf("File opening failed");

 }
 else {
    int x, y;
	printf("Valore di x: ");
	scanf("%d", &x);
	fprintf(fp, "%d", x);
	printf("Valore di y: ");
	scanf("%d", &y);
	fprintf(fp, "\t");
	fprintf(fp, "%d", y);
 }

 fclose(fp);

}


int main(){
	lettura ();
	scrittura();
	return 0;
}
