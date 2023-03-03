#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int d, s, m[2][2]; 
    for (d = 0; d<2; d++)
        { 
            for (s = 0; s<2; s++)  
                { 
                    scanf("%d", &m[d][s]); 
                } 
        }       
 printf("|%d %d|\n", m[0][0]*m[0][0] + m[0][1]*m[1][0], m[0][0]*m[0][1] + m[0][1]*m[1][1] ); 
 printf("|%d %d|", m[0][0]*m[1][0] + m[1][1]*m[1][0], m[1][0]*m[0][1] + m[1][1]*m[1][1]); 
 return 0;
}