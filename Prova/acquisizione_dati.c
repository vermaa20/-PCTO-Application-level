#include <stdio.h>
#include <stdlib.h>
// #define MAX 3
int main(void)
{
 FILE *fp = fopen("result.xls", "w");
 int data, i = 0;
 long int n = 0;

 if (fp == NULL) {
 printf("File opening failed");

 return EXIT_FAILURE;
 }
 else {
    do {
        printf("\n Numero dati da inserire: ");
        scanf("%ld", &n);
    } while (n <= 0);
     for (i = 0; i < n; i++) {
        printf("Dato: ");
        scanf("%d", &data);

        fprintf(fp, "DATA NUM: %ld  - DATA:  %d\n", n, data);
     }
 }

 fclose(fp);

 return 0;
}
