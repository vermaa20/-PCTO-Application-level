
#include <stdio.h>
#include <string.h>
#define MAX 8
#define MAX_LUNG 21

void lettura()
{
 FILE *fp = fopen("log.txt", "r");
 char c, c1offset;
 char tester[MAX], num[MAX], tipoDomanda[MAX_LUNG],dato[MAX];
 int i = 0, j = 0, prova = 0, dim = 0, controlla = 0, count = 0, domrisp = 0;
 int u = 0, dec = 0, mig = 0, indice = 0, cent = 0, flag = 0, lenghtDom = 0;
 int lenghtRis = 0,datoInt = 0;
 float offset;
 if (fp == NULL) {
 printf("File opening failed");

 }
 else {
    while (!feof(fp)) {
        count++;
        if (count % 2 == 0) {
            domrisp = 2;
        } else {
            domrisp = 1;
        }

        if(count < 10){
           num[0] = count + 48;
           num[1] = ')';
           num[2] = '\0';
           indice = 2;
        }
        else if(count > 9 && count < 100){
            dec = (count / 10) + 48;
            u = (count % 10) + 48;
           num[0] = dec;
           num[1] = u;
           num[2] = ')';
           num[3] = '\0';
           indice = 3;
        }
        else if(count > 99 && count < 1000){
            cent = (count / 100) + 48;
            dec = (count / 10 % 10) + 48;
            u = (count % 100 % 10) + 48;
            num[0] = cent;
            num[1] = dec;
            num[2] = u;
            num[3] = ')';
            num[4] = '\0';
            indice = 4;
        }
        else if(count > 999 && count < 10000){

            mig = (count / 1000) + 48;
            cent = (count / 100 % 100) + 48;
            dec = (count / 10) + 48;
            u = (count % 10) + 48;
            num[0] = mig;
            num[1] = cent;
            num[2] = dec;
            num[3] = u;
            num[4] = ')';
            num[5] = '\0';
            indice = 5;
        }
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

                    tipoDomanda[j] = '\0';
                    printf("\n");
                }
            }
        }



    }
 }
 return 0;
 }
