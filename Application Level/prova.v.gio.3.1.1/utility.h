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
    int x[MAX], y[MAX], somma = 0;
 	for(i = 0; i < MAX; i++){
		printf("Valore di x: ");
		scanf("%d", &x[i]);

		printf("Valore di y: ");
		scanf("%d", &y[i]);
		somma += y[i];


	}
     for(i = 0; i < MAX; i++){
        fprintf(fp, "%d", x[i]);
        fprintf(fp, "\t");
		fprintf(fp, "%d", y[i]);
		fprintf(fp, "\t");
		fprintf(fp, "%.1f", (float)somma/4);
		fprintf(fp, "\n");
     }
 }

 fclose(fp);

}
void bat(){
    FILE *fp = fopen("data.bat", "w");

    if (fp == NULL) {
     printf("File opening failed");

     }
     else {
        fprintf(fp, "cd 'C:\\Users\\VERMAA20\\Desktop\\PCTO\\gio_gio3\\prova.v.gio.3.1.1'\n");
        fprintf(fp, "plot \"info.xls\" u 1:2 w l lw 3 lc 4 title \"Dato\", \"info.xls\" u 1:3 w lp lw 3 lc 8 title \"Dato1\"");
        fprintf(fp, "\nset title \"squares of numers\"");
        fprintf(fp, "\nset xlabel \"Benzina\"");
        fprintf(fp, "\nset ylabel \"Km\"");
        fprintf(fp, "\nset grid");
        fprintf(fp, "\nset term png size 1050, 750");
        fprintf(fp, "\nset output \"number.png\"");
        fprintf(fp, "\nreplot");
     }
}

void p(){
	FILE *fp = fopen("load.plt", "w");
	fprintf(fp, "load \"data.bat\"");
}
