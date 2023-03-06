#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 8
#define MAX_LUNG 21

#define M_01 0.1
#define Q_M273 -273.0
#define M_001 0.01
#define Q_M327 -327.68
#define M_00488 0.0488
#define Q_M32768 -32768.0


void lettura(float *risposta1, int *secondi1, float *risposta2, int *secondi2, float *risposta3, int *secondi3, float *risposta4, int *secondi4, float *risposta5, int *secondi5, float *risposta6, int *secondi6, float *risposta7, int *secondi7, float *risposta8, int *secondi8, float *risposta9, int *secondi9, float *risposta10, int *secondi10, float *risposta11, int *secondi11, int *contTipo)
{
    FILE *fp = fopen("log.txt", "r");
    char c, c1offset;
    char tester[MAX], num[MAX], tipoDomanda[MAX_LUNG],dato[MAX];
    int i = 0, j = 0, prova = 0, dim = 0, controlla = 0, count = 0, domrisp = 0, tipo = 0;
    int u = 0, dec = 0, mig = 0, indice = 0, cent = 0, flag = 0, lenghtDom = 0;
    int lenghtRis = 0,datoInt = 0, countFlag = 0;
    float offset;

    if (fp == NULL) {
        printf("File opening failed");

    } else {
        for (i = 0; i < 11; i++)
            contTipo[i] = 0;
        while (!feof(fp)) { /*Fino alla fine del file*/
            count++;
            itoa(count, num, 10);   /*Conversione da numero a stringa*/
            num[strlen(num)] = ')';  /*A stringa va aggiunta la ')'*/
            num[strlen(num) + 1] = '\0';

            indice = strlen(num) ;  /*Lunghezza della stringa*/
            flag = 0;

            while(flag != 1){    /*Ciclo che si esegue finché non trova il numero cercato*/
                countFlag++;
                if(controlla > 0) {                   /*Dalla seconda volta in poi*/
                    for(i = 0; i < indice - 1; i++){   /*Shift a sinistra*/
                        tester[i] = tester[i + 1];
                    }
                    fscanf(fp, "%c", &c);
                    tester[i] = c;
                    tester[indice + 1] = '\0';
                } else {  /*Da eseguire durante la prima lettura*/
                    for(i = 0; i < indice - 1; i++){
                        fscanf(fp, "%c", &c);
                        tester[i] = c;
                    }
                    tester[indice] = '\0';
                    controlla = 1;
                }



                if(strcmp(tester, num) == 0){   /*Se trova il numero cercato*/
                    printf(num);
                    flag = 1;
                    countFlag = 0;
                    fscanf(fp, "%c", &c);
                    while(c1offset == ' ')   /*Per saltare gli spazi inutili*/
                        fscanf(fp, "%c", &c1offset);
                    fscanf(fp, "%f", &offset);   /*Lettura dei secondi*/
                    printf("%.1f", offset);
                    for(i = 0; i < 23; i++){
                        fscanf(fp, "%c", &c);
                    }

                    if(count % 2 == 1){  /*Per verificare se è domanda o la risposta*/
                        domrisp = 1;
                    } else {
                        domrisp = 0;
                    }
                    if (domrisp == 1) {
                        fscanf(fp, "%d", &lenghtDom);
                        printf("\n%d", lenghtDom);
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

                        if (strcmp(tipoDomanda, "222008") == 0) {
                            tipo = 0;
                            contTipo[tipo] = contTipo[tipo] + 1;
                        } else if (strcmp(tipoDomanda, "222001") == 0) {
                            tipo = 1;
                            contTipo[tipo] = contTipo[tipo] + 1;
                        } else if (strcmp(tipoDomanda, "222409") == 0) {
                            tipo = 2;
                            contTipo[tipo] = contTipo[tipo] + 1;
                        } else if (strcmp(tipoDomanda, "22246E") == 0) {
                            tipo = 3;
                            contTipo[tipo] = contTipo[tipo] + 1;
                        } else if (strcmp(tipoDomanda, "22242A") == 0) {
                            tipo = 4;
                            contTipo[tipo] = contTipo[tipo] + 1;
                        } else if (strcmp(tipoDomanda, "222407") == 0) {
                            tipo = 5;
                            contTipo[tipo] = contTipo[tipo] + 1;
                        } else if (strcmp(tipoDomanda, "222542") == 0) {
                            tipo = 6;
                            contTipo[tipo] = contTipo[tipo] + 1;
                        } else if (strcmp(tipoDomanda, "2224FB") == 0) {
                            tipo = 7;
                            contTipo[tipo] = contTipo[tipo] + 1;
                        } else if (strcmp(tipoDomanda, "222006") == 0) {
                            tipo = 8;
                            contTipo[tipo] = contTipo[tipo] + 1;
                        } else if (strcmp(tipoDomanda, "2224A5") == 0) {
                            tipo = 9;
                            contTipo[tipo] = contTipo[tipo] + 1;
                        } else if (strcmp(tipoDomanda, "222496") == 0) {
                            tipo = 10;
                            contTipo[tipo] = contTipo[tipo] + 1;
                        }
                        printf("\n");
                    } else {
                        fscanf(fp, "%d", &lenghtRis);
                        printf("\n%d", lenghtRis);
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
                        tipoDomanda[j] = '\0';
                        switch(tipo){
                            case 0:

                                risposta1[contTipo[0] - 1] = datoInt * M_01 + Q_M273;
                                printf("\ncjdk\n%f\n", risposta1[contTipo[0] - 1]);
                                secondi1[contTipo[0] - 1] = round(offset/1000);
                                break;
                            case 1:
                                risposta2[contTipo[1] - 1] = datoInt * M_01 + Q_M273;
                                secondi2[contTipo[1] - 1] = round(offset/1000);
                                break;
                            case 2:
                                risposta3[contTipo[2] - 1] = datoInt * M_001 + Q_M327;
                                secondi3[contTipo[2] - 1] = round(offset/1000);
                                break;
                            case 3:
                                risposta4[contTipo[3] - 1] = datoInt * M_001 + Q_M327;
                                secondi4[contTipo[3] - 1] = round(offset/1000);
                                break;
                            case 4:
                                risposta5[contTipo[4] - 1] = datoInt * M_00488;
                                secondi5[contTipo[4] - 1] = round(offset/1000);
                                break;
                            case 5:
                                risposta6[contTipo[5] - 1] = datoInt * M_00488;
                                secondi6[contTipo[5] - 1] = round(offset/1000);
                                break;
                            case 6:
                                risposta7[contTipo[6] - 1] = datoInt + Q_M32768;
                                secondi7[contTipo[6] - 1] = round(offset/1000);
                                break;
                            case 7:
                                risposta8[contTipo[7] - 1] = datoInt + Q_M32768;
                                secondi8[contTipo[7] - 1] = round(offset/1000);
                                break;
                            case 8:
                                risposta9[contTipo[8] - 1] = datoInt;
                                secondi9[contTipo[8] - 1] = round(offset/1000);
                                break;
                            case 9:
                                risposta10[contTipo[9] - 1] = datoInt * M_001;
                                secondi10[contTipo[9] - 1] = round(offset/1000);
                                break;
                            case 10:
                                risposta11[contTipo[10] - 1] = datoInt * M_001;
                                secondi11[contTipo[10] - 1] = round(offset/1000);
                        }
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
}

void scrittura1(float *risposta1, int *secondi1,int *contTipo) {
FILE *fp = fopen("info1.xls", "w");
int i = 0;


printf("\n\n%d\n\n", contTipo[0]);
    for(i = 0; i < contTipo[0]; i++){
        fprintf(fp, "%d", secondi1[i]);
        printf("\n\n%f\t%d\n\n", risposta1[i], secondi1[i]);
        fprintf(fp, "\t");
        fprintf(fp, "%.1f", risposta1[i]);
        fprintf(fp, "\n");
    }
    fclose(fp);
}

void scrittura2(float *risposta2, int *secondi2, float *contTipo) {
FILE *fp = fopen("info2.xls", "w");
int i = 0;

    for(i = 0; i < contTipo[1]; i++){
        fprintf(fp, "%d", secondi2[i]);
        fprintf(fp, "\t");
        fprintf(fp, "%.1f", risposta2[i]);
        fprintf(fp, "\n");
    }

    fclose(fp);
}

void scrittura3(float *risposta3, int *secondi3, float *contTipo) {
FILE *fp = fopen("info3.xls", "w");
int i = 0, xM = 0, yM = 0, ym = 0, xm = 0;

    for(i = 0; i < contTipo[2]; i++){
        fprintf(fp, "%d", secondi3[i]);
        fprintf(fp, "\t");
        fprintf(fp, "%.1f", risposta3[i]);
        fprintf(fp, "\n");
    }

    fclose(fp);
}

void scrittura4(float *risposta4, int *secondi4, float *contTipo) {
 FILE *fp = fopen("info4.xls", "w");
 int i = 0, xM = 0, yM = 0, ym = 0, xm = 0;

    for(i = 0; i < contTipo[3]; i++){
        fprintf(fp, "%d", secondi4[i]);
        fprintf(fp, "\t");
        fprintf(fp, "%.1f", risposta4[i]);
        fprintf(fp, "\n");
    }

    fclose(fp);
}

void scrittura5(float *risposta5, int *secondi5, float *contTipo) {
 FILE *fp = fopen("info5.xls", "w");
 int i = 0, xM = 0, yM = 0, ym = 0, xm = 0;

    for(i = 0; i < contTipo[4]; i++){
        fprintf(fp, "%d", secondi5[i]);
        fprintf(fp, "\t");
        fprintf(fp, "%.1f", risposta5[i]);
        fprintf(fp, "\n");
    }

    fclose(fp);
}

void scrittura6(float *risposta6, int *secondi6, float *contTipo) {
 FILE *fp = fopen("info6.xls", "w");
 int i = 0, xM = 0, yM = 0, ym = 0, xm = 0;

    for(i = 0; i < contTipo[5]; i++){
        fprintf(fp, "%d", secondi6[i]);
        fprintf(fp, "\t");
        fprintf(fp, "%.1f", risposta6[i]);
        fprintf(fp, "\n");
    }

    fclose(fp);
}

void scrittura7(float *risposta7, int *secondi7, float *contTipo) {
 FILE *fp = fopen("info7.xls", "w");
 int i = 0, xM = 0, yM = 0, ym = 0, xm = 0;

    for(i = 0; i < contTipo[6]; i++){
        fprintf(fp, "%d", secondi7[i]);
        fprintf(fp, "\t");
        fprintf(fp, "%.1f", risposta7[i]);
        fprintf(fp, "\n");
    }

    fclose(fp);
}

void scrittura8(float *risposta8, int *secondi8, float *contTipo) {
 FILE *fp = fopen("info8.xls", "w");
 int i = 0, xM = 0, yM = 0, ym = 0, xm = 0;

    for(i = 0; i < contTipo[7]; i++){
        fprintf(fp, "%d", secondi8[i]);
        fprintf(fp, "\t");
        fprintf(fp, "%.1f", risposta8[i]);
        fprintf(fp, "\n");
    }

     fclose(fp);
}

void scrittura9(float *risposta9, int *secondi9, float *contTipo) {
 FILE *fp = fopen("info9.xls", "w");
 int i = 0, xM = 0, yM = 0, ym = 0, xm = 0;

    for(i = 0; i < contTipo[8]; i++){
        fprintf(fp, "%d", secondi9[i]);
        fprintf(fp, "\t");
        fprintf(fp, "%.1f", risposta9[i]);
        fprintf(fp, "\n");
    }

     fclose(fp);
}

void scrittura10(float *risposta10, int *secondi10, float *contTipo) {
 FILE *fp = fopen("info10.xls", "w");
 int i = 0, xM = 0, yM = 0, ym = 0, xm = 0;

    for(i = 0; i < contTipo[9]; i++){
        fprintf(fp, "%d", secondi10[i]);
        fprintf(fp, "\t");
        fprintf(fp, "%.1f", risposta10[i]);
        fprintf(fp, "\n");
    }

     fclose(fp);
}

void scrittura11(float *risposta11, int *secondi11, float *contTipo) {
 FILE *fp = fopen("info11.xls", "w");
 int i = 0, xM = 0, yM = 0, ym = 0, xm = 0;

    for(i = 0; i < contTipo[10]; i++){
        fprintf(fp, "%d", secondi11[i]);
        fprintf(fp, "\t");
        fprintf(fp, "%.1f", risposta11[i]);
        fprintf(fp, "\n");
    }

     fclose(fp);
}

void bat1(){
    FILE *fp = fopen("data1.bat", "w");
        fprintf(fp, "cd 'C:\\Users\\VERMAA20\\Desktop\\PCTO\\gio_5\\gio_7'\n");
        fprintf(fp, "set key left top\n");
        fprintf(fp, "plot \"info.xls\" w l lw 3 lc 4 title \"Fuel Temp\"");
		fprintf(fp, "\nset title \"Fuel Temp\"");
        fprintf(fp, "\nset xlabel \"Time (sec)\"");
        fprintf(fp, "\nset ylabel \"Temperature (°C)\"");
        fprintf(fp, "\nset grid");
        fprintf(fp, "\nset term png size 1050, 1050");
        fprintf(fp, "\nset output \"Fuel Temp.png\"");
        fprintf(fp, "\nreplot");
}

void bat2(){
    FILE *fp = fopen("data2.bat", "w");
        fprintf(fp, "cd 'C:\\Users\\VERMAA20\\Desktop\\PCTO\\gio_5\\gio_7'\n");
        fprintf(fp, "set key left top\n");
        fprintf(fp, "plot \"info.xls\" w l lw 3 lc 4 title \"Water temp\"");
		fprintf(fp, "\nset title \"Water temp\"");
        fprintf(fp, "\nset xlabel \"Time (sec)\"");
        fprintf(fp, "\nset ylabel \"Temperature (°C)\"");
        fprintf(fp, "\nset grid");
        fprintf(fp, "\nset term png size 1050, 1050");
        fprintf(fp, "\nset output \"Water temp.png\"");
        fprintf(fp, "\nreplot");
}

void bat3(){
    FILE *fp = fopen("data3.bat", "w");
        fprintf(fp, "cd 'C:\\Users\\VERMAA20\\Desktop\\PCTO\\gio_5\\gio_7'\n");
        fprintf(fp, "set key left top\n");
        fprintf(fp, "plot \"info.xls\" w l lw 3 lc 4 title \"EGR Valve Control\"");
		fprintf(fp, "\nset title \"EGR Valve Control\"");
        fprintf(fp, "\nset xlabel \"Time (sec)\"");
        fprintf(fp, "\nset ylabel \" % \"");
        fprintf(fp, "\nset grid");
        fprintf(fp, "\nset term png size 1050, 1050");
        fprintf(fp, "\nset output \"EGR Valve Control.png\"");
        fprintf(fp, "\nreplot");
}

void bat4(){
    FILE *fp = fopen("data4.bat", "w");
        fprintf(fp, "cd 'C:\\Users\\VERMAA20\\Desktop\\PCTO\\gio_5\\gio_7'\n");
        fprintf(fp, "set key left top\n");
        fprintf(fp, "plot \"info.xls\" w l lw 3 lc 4 title \"EGR Command Circuit\"");
		fprintf(fp, "\nset title \"EGR Command Circuit\"");
        fprintf(fp, "\nset xlabel \"Time (sec)\"");
        fprintf(fp, "\nset ylabel \" % \"");
        fprintf(fp, "\nset grid");
        fprintf(fp, "\nset term png size 1050, 1050");
        fprintf(fp, "\nset output \"EGR Command Circuit.png\"");
        fprintf(fp, "\nreplot");
}

void bat5(){
    FILE *fp = fopen("data5.bat", "w");
        fprintf(fp, "cd 'C:\\Users\\VERMAA20\\Desktop\\PCTO\\gio_5\\gio_7'\n");
        fprintf(fp, "set key left top\n");
        fprintf(fp, "plot \"info.xls\" w l lw 3 lc 4 title \"EGR Valve First Offset\"");
		fprintf(fp, "\nset title \"EGR Valve First Offset\"");
        fprintf(fp, "\nset xlabel \"Time (sec)\"");
        fprintf(fp, "\nset ylabel \" % \"");
        fprintf(fp, "\nset grid");
        fprintf(fp, "\nset term png size 1050, 1050");
        fprintf(fp, "\nset output \"EGR Valve First Offset.png\"");
        fprintf(fp, "\nreplot");
}

void bat6(){
    FILE *fp = fopen("data6.bat", "w");
        fprintf(fp, "cd 'C:\\Users\\VERMAA20\\Desktop\\PCTO\\gio_5\\gio_7'\n");
        fprintf(fp, "set key left top\n");
        fprintf(fp, "plot \"info.xls\" w l lw 3 lc 4 title \"EGR Position\"");
		fprintf(fp, "\nset title \"EGR Position\"");
        fprintf(fp, "\nset xlabel \"Time (sec)\"");
        fprintf(fp, "\nset ylabel \" % \"");
        fprintf(fp, "\nset grid");
        fprintf(fp, "\nset term png size 1050, 1050");
        fprintf(fp, "\nset output \"EGR Position.png\"");
        fprintf(fp, "\nreplot");
}

void bat7(){
    FILE *fp = fopen("data7.bat", "w");
        fprintf(fp, "cd 'C:\\Users\\VERMAA20\\Desktop\\PCTO\\gio_5\\gio_7'\n");
        fprintf(fp, "set key left top\n");
        fprintf(fp, "plot \"info.xls\" w l lw 3 lc 4 title \"Particle Filter Pressure Diff.\"");
		fprintf(fp, "\nset title \"Particle Filter Pressure Diff.\"");
        fprintf(fp, "\nset xlabel \"Time (sec)\"");
        fprintf(fp, "\nset ylabel \" hPa \"");
        fprintf(fp, "\nset grid");
        fprintf(fp, "\nset term png size 1050, 1050");
        fprintf(fp, "\nset output \"Particle Filter Pressure Diff.png\"");
        fprintf(fp, "\nreplot");
}

void bat8(){
    FILE *fp = fopen("data8.bat", "w");
        fprintf(fp, "cd 'C:\\Users\\VERMAA20\\Desktop\\PCTO\\gio_5\\gio_7'\n");
        fprintf(fp, "set key left top\n");
        fprintf(fp, "plot \"info.xls\" w l lw 3 lc 4 title \"Particle Filter Diff. Pressure Correction\"");
		fprintf(fp, "\nset title \"Particle Filter Diff. Pressure Correction\"");
        fprintf(fp, "\nset xlabel \"Time (sec)\"");
        fprintf(fp, "\nset ylabel \" hPa \"");
        fprintf(fp, "\nset grid");
        fprintf(fp, "\nset term png size 1050, 1050");
        fprintf(fp, "\nset output \"Particle Filter Diff. Pressure Correction.png\"");
        fprintf(fp, "\nreplot");
}

void bat9(){
    FILE *fp = fopen("data9.bat", "w");
        fprintf(fp, "cd 'C:\\Users\\VERMAA20\\Desktop\\PCTO\\gio_5\\gio_7'\n");
        fprintf(fp, "set key left top\n");
        fprintf(fp, "plot \"info.xls\" w l lw 3 lc 4 title \"Mileage\"");
		fprintf(fp, "\nset title \"Mileage\"");
        fprintf(fp, "\nset xlabel \"Time (sec)\"");
        fprintf(fp, "\nset ylabel \" Km \"");
        fprintf(fp, "\nset grid");
        fprintf(fp, "\nset term png size 1050, 1050");
        fprintf(fp, "\nset output \"Mileage.png\"");
        fprintf(fp, "\nreplot");
}

void bat10(){
    FILE *fp = fopen("data10.bat", "w");
        fprintf(fp, "cd 'C:\\Users\\VERMAA20\\Desktop\\PCTO\\gio_5\\gio_7'\n");
        fprintf(fp, "set key left top\n");
        fprintf(fp, "plot \"info.xls\" w l lw 3 lc 4 title \"Weight of Soot After Regeneration\"");
		fprintf(fp, "\nset title \"Weight of Soot After Regeneration\"");
        fprintf(fp, "\nset xlabel \"Time (sec)\"");
        fprintf(fp, "\nset ylabel \" g \"");
        fprintf(fp, "\nset grid");
        fprintf(fp, "\nset term png size 1050, 1050");
        fprintf(fp, "\nset output \"Weight of Soot After Regeneration.png\"");
        fprintf(fp, "\nreplot");
}

void bat11(){
    FILE *fp = fopen("data11.bat", "w");
        fprintf(fp, "cd 'C:\\Users\\VERMAA20\\Desktop\\PCTO\\gio_5\\gio_7'\n");
        fprintf(fp, "set key left top\n");
        fprintf(fp, "plot \"info.xls\" w l lw 3 lc 4 title \"Soot in the Particle Filter\"");
		fprintf(fp, "\nset title \"Soot in the Particle Filter\"");
        fprintf(fp, "\nset xlabel \"Time (sec)\"");
        fprintf(fp, "\nset ylabel \" g \"");
        fprintf(fp, "\nset grid");
        fprintf(fp, "\nset term png size 1050, 1050");
        fprintf(fp, "\nset output \"Soot in the Particle Filter.png\"");
        fprintf(fp, "\nreplot");
}


void plot(){
	FILE *fp = fopen("load.plt", "w");
	fprintf(fp, "load \"data1.bat\"\n");
	fprintf(fp, "load \"data2.bat\"\n");
	fprintf(fp, "load \"data3.bat\"\n");
	fprintf(fp, "load \"data4.bat\"\n");
	fprintf(fp, "load \"data5.bat\"\n");
	fprintf(fp, "load \"data6.bat\"\n");
	fprintf(fp, "load \"data7.bat\"\n");
	fprintf(fp, "load \"data8.bat\"\n");
	fprintf(fp, "load \"data9.bat\"\n");
	fprintf(fp, "load \"data10.bat\"\n");
	fprintf(fp, "load \"data11.bat\"");
}

