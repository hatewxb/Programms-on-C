#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "function.h"

int main()
{double a, b, c;
	scanf("%lf%lf%lf", &a, &b, &c);
	if ((a+b <= c) || (a+c <= b) || (b+c <= a))
	{
		printf("This triangle doesnt exist\n");
		exit(0);
	}
	else
	{
		double r_1 = per (a, b, c);
		double r_2 = plo (a, b, c);
		printf("Perimetr = %lf\nSquare = %lf\n", r_1, r_2);
	}
	return 0;
}