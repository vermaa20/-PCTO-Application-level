#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int s=0;
	int x=0;
	int n=0;

	printf("insrsci x");
	scanf("%d", &x);
	printf("insersci n");
	scanf("%d", &n);
	s=somma(x,n);
	printf("%d",s);
}

int somma (int x, int n){
	int i=0;
	int risultato=0;

	for (i=1; i<=x; i++){
		risultato=risultato+pow(i, n);
		printf("\n%d", risultato);
	}
	return risultato;
}
