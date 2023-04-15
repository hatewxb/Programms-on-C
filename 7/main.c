#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char name[20];
    char surname[20];
    int birth_year;
} humen;

int main() 
{
    humen arr1[4];
	humen arr2[4];

    printf("Enter data for the firsrt array:\n");
    int i;
    for (i = 0; i < 4; i++) 
	{
        printf("Person %d:\n", i+1);
        printf("Name: ");
        scanf("%s", arr1[i].name);
        printf("Surname: ");
        scanf("%s", arr1[i].surname);
        printf("Birth year: ");
        scanf("%d", &arr1[i].birth_year);
    }
    
    memcpy(arr2, arr1, sizeof(arr1));
    
    for (i = 0; i < 3; i++) 
	{
    	int j;
        for (j = i+1; j < 4; j++) 
		{
            if (arr2[i].birth_year > arr2[j].birth_year) 
			{
                humen temp = arr2[i];
                arr2[i] = arr2[j];
                arr2[j] = temp;
            }
        }
    }
    
    printf("\nSorted array:\n");
    
    for (i = 0; i < 4; i++) 
	{
        printf("Person %d:\n", i+1);
        printf("Name: %s\n", arr2[i].name);
        printf("Surname: %s\n", arr2[i].surname);
        printf("Birth year: %d\n", arr2[i].birth_year);
    }
    return 0;
}