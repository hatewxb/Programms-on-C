#include <stdio.h>  
#include <stdio.h>  
#include <string.h>  
  
typedef struct {  //задаем структуру humen
  char name[50];  
  char surname[50];  
  int birth_year;  
} human;  
  
void bubble_sort(human arr[], int n) {  
  for (int i = 0; i < n-1; i++) {  
    for (int j = 0; j < n-i-1; j++) {  
      if (arr[j].birth_year > arr[j+1].birth_year) {  
        human temp = arr[j];  
        arr[j] = arr[j+1];  
        arr[j+1] = temp;  
      }  
    }  
  }  
}  
  
int main() {  
  int size;  
  printf("Enter the number of people ");  //колличество людей
  scanf("%d", &size);  
  
  human arr1[size];   
  human arr2[size];   
  
  int choice;  
  printf("Select data source:\n1. Console input\n2. Reading from file\n");  //выбор ввода данных
  scanf("%d", &choice);  
  
  if (choice == 1) {  
    printf("Enter details for %d people:\n", size);  //ручная запись
    for (int i = 0; i < size; i++) {  
      printf("Human %d:\n", i+1);  
      printf("Name: ");  
      scanf("%s", arr1[i].name);  
      printf("Surname: ");  
      scanf("%s", arr1[i].surname);  
      printf("Year of birth: ");  
      scanf("%d", &arr1[i].birth_year);  
    }  
  } else if (choice == 2) {  
    FILE *file = fopen("data.txt", "r");  //чтение файла
    if (file == NULL) {  
      printf("Error opening file\n");  
      return 1;  
    }  
    int i = 0;  
    while (fscanf(file, "%s %s %d", arr1[i].name, arr1[i].surname, &arr1[i].birth_year) != EOF && i < size) {  
      i++;  
    }  
    fclose(file);  
    if (i < size) {  
      printf("Not enough data in file to sort %d people\n", size);  
      return 1;  
    }  
  } else {  
    printf("Wrong choice\n");  
    return 1;  
  }  
  bubble_sort(arr1, size);  
  memcpy(arr2, arr1, sizeof(human) * size);  
  
  printf("\nPeople sorted by year of birth:\n");  
  for (int j = 0; j < size; j++) {  
      printf("%s %s, %d\n", arr2[j].name, arr2[j].surname, arr2[j].birth_year);  
  }  
  
  return 0;  
}