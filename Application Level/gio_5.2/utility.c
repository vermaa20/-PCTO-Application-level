
#include <stdio.h>
#include <string.h>
#define MAX 8
#define MAX_LUNG 21
#define MAX_DATI 1000
#define M_01 0.1
#define Q_01 -273.0
float lettura(int *arrRisIn,int *arrRisFin)
{
 FILE *fp = fopen("log.txt", "r");
 char c, c1offset;
 char tester[MAX], num[MAX], tipoDomanda[MAX_LUNG],dato[MAX];
 int i = 0, j = 0, prova = 0, dim = 0, controlla = 0, count = 0, domrisp = 0;
 int u = 0, dec = 0, mig = 0, indice = 0, cent = 0, flag = 0, lenghtDom = 0;
 int lenghtRis = 0,datoInt = 0;
 float offset;
 float risposta[MAX_DATI], secondi[MAX_DATI];

 if (fp == NULL) {
 printf("File opening failed");

 }
 else {
    while (!feof(fp)) {
        count++;
        itoa(count, num, 10);
        num[strlen(num)] = ')';
        num[strlen(num) + 1] = '\0';
        printf(num);
        flag = 0;
        while(flag != 1){
            if(controlla > 0) {
                for(i = 0; i < indice - 1; i++){
                    tester[i] = tester[i + 1];
                }
                fscanf(fp, "%c", &c);
                tester[i] = c;
                tester[indice + 1] = '\0';
            } else {
                for(i = 0; i < indice; i++){
                    fscanf(fp, "%c", &c);
                    tester[i] = c;
                }
                tester[indice] = '\0';
                controlla = 1;
            }



            if(strcmp(tester, num) == 0){
                flag = 1;
                fscanf(fp, "%c", &c);
                while(c1offset == ' ')
                    fscanf(fp, "%c", &c1offset);
                fscanf(fp, "%f", &offset);
                printf("%.1f", offset);
                for(i = 0; i < 23; i++){
                    fscanf(fp, "%c", &c);
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
                    //printf("\t%s", tipoDomanda);
                    printf("\n");
                } else {
                    fscanf(fp, "%d", &lenghtRis);
                    //printf("\n%d", lenghtRis);
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
                    printf("\n%d", datoInt);

                    risposta[count - 1] = datoInt * M_01 + Q_01;
                    secondi[count - 1] = round(offset/1000);
                    tipoDomanda[j] = '\0';
                    printf("\n");
                }
            }
        }
    }
    arrRisIn = &risposta;
    arrRisFin = &risposta[count - 1];
 }
 return 0;
 }

