#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"

int main(){
    int ymin = 0, *xMax, *yMax, *xmin;
	lettura ();
	ymin = scrittura(&xMax, &xmin, &yMax);
	printf("\n%d", ymin);
	printf("\n%d, %d, %d", xmin, xMax, yMax);
	bat(xMax, xmin, ymin, yMax);
	plot();

	return 0;
}

