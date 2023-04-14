#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *input_file, *output_file;
    char line[100];
    int year;

    input_file = fopen("input.txt", "r");
    output_file = fopen("output.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Ошибка при открытии файлов\n");
        exit(1);
    }

    while (fgets(line, 100, input_file)) {
        year = atoi(strtok(line, " \n\t")) + 1900; // узнаем год рождения
        strtok(NULL, " \n\t"); // скип фамилия
        strtok(NULL, " \n\t"); // скип имя
	strtok(NULL, " \n\t");

        if (year > 1980) {
            fprintf(output_file, "%s", line); // записываем строку в выходной файл
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}