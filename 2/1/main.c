#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
int main() 
{
 double mass[3][3] ;
 int i, j;
 for (i = 0; i<3; i++)  
 {
  for (j = 0; j<3; j++) 
     {
         scanf("%lf", &mass[i][j]);
  }
 }
 double kok = mass[0][0] + mass[2][2] + mass[1][1];
 double fof = mass[0][2] + mass[2][0] + mass[1][1];
 printf("Sum main = %f \n", kok);
 printf("Sum side = %f \n", fof);
 return 0;
 
}