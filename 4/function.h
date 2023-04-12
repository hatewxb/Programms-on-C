#include <stdio.h>
#include <math.h>

double per(double x, double y, double z)
{
	double p = x + y + z;
	return (p);
}
double plo(double x, double y, double z)
{
	double pp = (x + y + z)/2;
	double s = sqrt(pp * (pp - x) * (pp - y) * (pp - z) );
	return (s);
}