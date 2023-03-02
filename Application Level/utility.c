#include "utility.h"
#include <stdio.h>

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

int scrittura(int *xMax, int *xmin, int *yMax) {
 FILE *fp = fopen("info.xls", "w");
 char c;
 char tester[MAX];
 int i = 0, j = 0, prova = 0, dim = 0, controlla = 0, xM = 0, yM = 0, ym = 0, xm = 0;
    int x[MAX], y[MAX], somma = 0;
    printf("Valore di x: ");
    scanf("%d", &x[0]);

    printf("Valore di y: ");
    scanf("%d", &y[0]);
    somma += y[0];

    ym = y[0];
    xm = x[0];
    yM = y[0];
    xM = x[0];

 	for(i = 1; i < MAX; i++){
		printf("Valore di x: ");
		scanf("%d", &x[i]);

		printf("Valore di y: ");
		scanf("%d", &y[i]);
		somma += y[i];

        if(y[i] > yM)
        {
            yM = y[i];
            xM = x[i];
        }
        if(y[i] < ym)
        {
            ym = y[i];
            xm = x[i];
        }
	}

     for(i = 0; i < MAX; i++){
        fprintf(fp, "%d", x[i]);
        fprintf(fp, "\t");
		fprintf(fp, "%d", y[i]);
		fprintf(fp, "\t");
		fprintf(fp, "%.1f", (float)somma/4);
		fprintf(fp, "\n");
     }
     printf("\n%d, %d to %d, %d", xm, ym, yM, xM);

     *xmin = xm;
     *xMax = xM;
     *yMax = yM;

     fclose(fp);
     return ym;
}
void bat(xMax, xmin, ymin, yMax){
    FILE *fp = fopen("data.bat", "w");
        fprintf(fp, "cd 'C:\\Users\\VERMAA20\\Desktop\\PCTO\\gio_4\\prova.v.4'\n");
        fprintf(fp, "set key left top\n");
        fprintf(fp, "plot \"info.xls\" u 1:2 w l lw 3 lc 4 title \"Consumo\", \"info.xls\" u 1:3 w l lw 3 lc 8 dt 2 title \"Media\"");
		fprintf(fp, "\nset title \"squares of numers\"");
        fprintf(fp, "\nset xlabel \"Benzina\"");
        fprintf(fp, "\nset ylabel \"Km\"");
        fprintf(fp, "\nset xrange[0:%d]", xMax + 4);
        fprintf(fp, "\nset yrange[0:%d]", yMax + 4);
        fprintf(fp, "\nset arrow from %d,%d to %d,%d title \"min\"", xmin, ymin + 2, xmin, ymin);
        printf("\n%d,%d to %d, %d", xmin, ymin, xmin, ymin - 2);
        fprintf(fp, "\nset arrow from %d,%d to %d,%d  title \"max\"", xMax, yMax + 2, xMax, yMax);
        /*fprintf(fp, "\nset xrange[0:100]");
        fprintf(fp, "\nset yrange[0:100]");*/
        fprintf(fp, "\nset grid");
        fprintf(fp, "\nset term png size 1050, 1050");
        fprintf(fp, "\nset term pngcairo dashed");
        fprintf(fp, "\nset output \"number.png\"");
        fprintf(fp, "\nreplot");
}

void plot(){
	FILE *fp = fopen("load.plt", "w");
	fprintf(fp, "load \"data.bat\"");
}

