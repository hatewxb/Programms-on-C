#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
int main() { 
    FILE *in_file, *out_file; 
    char filename[] = "input.txt"; 
    char out_filename[] = "output.txt"; 
    char hold[1000]; 
    int year; 
    char sn[100]; 
     
    in_file = fopen(filename, "r"); 
    if (in_file == NULL) 
 { 
        printf("Error opening file %s.\n", filename); 
        exit(1); 
    } 
     
    out_file = fopen(out_filename, "w"); 
    if (out_file == NULL) 
 { 
        printf("Error opening file %s.\n", out_filename); 
        exit(1); 
    } 
     
    while (fgets(hold, 1000, in_file) != NULL) 
 { 
        sscanf(hold, "%*s %*s %*s %d", &year); 
        if (year > 1980) 
  { 
            fputs(hold, out_file); 
        } 
    } 
 
    fclose(in_file); 
    fclose(out_file); 
    printf("Done!"); 
    return 0; 
}
