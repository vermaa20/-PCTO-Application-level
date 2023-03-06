
#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 8
#define MAX_LUNG 21

#define M_01 0.1
#define Q_01 -273.0

int lettura(float *risposta, int *secondi, char tipoDomanda1)
{
 FILE *fp = fopen("log.txt", "r");
 char c, c1offset;
 char tester[MAX], num[MAX], tipoDomanda[MAX_LUNG],dato[MAX];
 int i = 0, j = 0, prova = 0, dim = 0, controlla = 0, count = 0, domrisp = 0;
 int u = 0, dec = 0, mig = 0, indice = 0, cent = 0, flag = 0, lenghtDom = 0;
 int lenghtRis = 0,datoInt = 0, countFlag = 0;
 float offset;


 if (fp == NULL) {
 printf("File opening failed");

 }
 else {
    while (!feof(fp)) {
        count++;
        itoa(count, num, 10);
        num[strlen(num)] = ')';
        num[strlen(num) + 1] = '\0';

        indice = strlen(num) ;
        flag = 0;

        while(flag != 1){
            countFlag++;
            if(controlla > 0) {
                for(i = 0; i < indice - 1; i++){
                    tester[i] = tester[i + 1];
                }
                fscanf(fp, "%c", &c);
                tester[i] = c;
                tester[indice + 1] = '\0';
            } else {
                for(i = 0; i < indice - 1; i++){
                    fscanf(fp, "%c", &c);
                    tester[i] = c;
                }
                tester[indice] = '\0';
                controlla = 1;
            }



            if(strcmp(tester, num) == 0){
                printf(num);
                flag = 1;
                countFlag = 0;
                fscanf(fp, "%c", &c);
                while(c1offset == ' ')
                    fscanf(fp, "%c", &c1offset);
                fscanf(fp, "%f", &offset);
                printf("%.1f", offset);
                for(i = 0; i < 23; i++){
                    fscanf(fp, "%c", &c);
                }

                if(count % 2 == 1){
                    domrisp = 1;
                }
                else{
                    domrisp = 0;
                }
                if (domrisp == 1) {
                    fscanf(fp, "%d", &lenghtDom);
                    printf("\t%d", lenghtDom);
                    fscanf(fp, "%c", &c);

                    j = 0;
                    for(i = 0; i < (lenghtDom * 2 + lenghtDom); i++){
                        fscanf(fp, "%c", &c);
                        if(c != ' '){
                            tipoDomanda[j] = c;
                            j++;
                        }
                    }
                    tipoDomanda[j] = '\0';
                    printf("\t%s", tipoDomanda);
                    printf("\n");
                } else {
                    fscanf(fp, "%d", &lenghtRis);
                    printf("\t%d", lenghtRis);
                    fscanf(fp, "%c", &c);

                    int diff = lenghtRis - lenghtDom;

                    for(i = 0; i < (lenghtDom * 2 + lenghtDom); i++){
                        fscanf(fp, "%c", &c);
                    }

                    j = 0;
                    for(i = 0; i < (diff * 2 + diff); i++){
                        fscanf(fp, "%c", &c);
                        if(c  != ' '){
                            dato[j] = c;
                            j++;
                        }
                    }
                    dato[j] = '\0';

                    datoInt = (int)strtol(dato, NULL, 16);
                    printf("\t%d", datoInt);

                    risposta[count/2 - 1] = datoInt * M_01 + Q_01;
                    secondi[count/2 - 1] = round(offset/1000);
                    tipoDomanda[j] = '\0';
                    tipoDomanda1[count/2 - 1] = tipoDomanda;
                    printf("\n");
                }
            }
            if(countFlag > 500){
                break;
            }
        }



    }
    fclose(fp);
 }
return count;
 }

void scrittura(float *risposta,int *secondi, int count, char *tipoDomanda1) {
 FILE *fp = fopen("info.xls", "w");
 char c;
 char tester[MAX];
 int i = 0, j = 0, prova = 0, dim = 0, controlla = 0, xM = 0, yM = 0, ym = 0, xm = 0;

 	for(i = 0; i < (count - 1) / 2; i++){

        if (strcmp(tipoDomanda1[i], "222008") == 0) {
            fprintf(fp, "%d", secondi[i]);
            fprintf(fp, "\t");
            fprintf(fp, "%.1f", risposta[i]);
        }
        } else if (strcmp(tipoDomanda1[i], "222001") == 0) {
            tipo = 1;
            contTipo[tipo] = contTipo[tipo] + 1;
        } else if (strcmp(tipoDomanda1[i], "222409") == 0) {
            tipo = 2;
            contTipo[tipo] = contTipo[tipo] + 1;
        } else if (strcmp(tipoDomanda1[i], "22246E") == 0) {
            tipo = 3;
            contTipo[tipo] = contTipo[tipo] + 1;
        } else if (strcmp(tipoDomanda1[i], "22242A") == 0) {
            tipo = 4;
            contTipo[tipo] = contTipo[tipo] + 1;
        } else if (strcmp(tipoDomanda1[i], "222407") == 0) {
            tipo = 5;
            contTipo[tipo] = contTipo[tipo] + 1;
        } else if (strcmp(tipoDomanda1[i], "222542") == 0) {
            tipo = 6;
            contTipo[tipo] = contTipo[tipo] + 1;
        } else if (strcmp(tipoDomanda1[i], "2224FB") == 0) {
            tipo = 7;
            contTipo[tipo] = contTipo[tipo] + 1;
        } else if (strcmp(tipoDomanda1[i], "222006") == 0) {
            tipo = 8;
            contTipo[tipo] = contTipo[tipo] + 1;
        } else if (strcmp(tipoDomanda1[i], "2224A5") == 0) {
            tipo = 9;
            contTipo[tipo] = contTipo[tipo] + 1;
        } else if (strcmp(tipoDomanda1[i], "222496") == 0) {
            tipo = 10;
            contTipo[tipo] = contTipo[tipo] + 1;
        }
 	}
     fclose(fp);
}

void bat(){
    FILE *fp = fopen("data.bat", "w");
        fprintf(fp, "cd 'C:\\Users\\VERMAA20\\Desktop\\PCTO\\gio_6'\n");
        fprintf(fp, "set key left top\n");
        fprintf(fp, "plot \"info.xls\" w l lw 3 lc 11 title \"Fuel Temp\"");
		fprintf(fp, "\nset title \"Fuel Temp\"");
        fprintf(fp, "\nset xlabel \"Time (sec)\"");
        fprintf(fp, "\nset ylabel \"Temperature (°C)\"");
        fprintf(fp, "\nset grid");
        fprintf(fp, "\nset term png size 1050, 1050");
        fprintf(fp, "\nset output \"number.png\"");
        fprintf(fp, "\nreplot");

}

void plot(){
	FILE *fp = fopen("load.plt", "w");
	fprintf(fp, "load \"data.bat\"");
}
