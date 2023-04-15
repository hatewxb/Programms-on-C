
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_RECORDS 40

typedef struct {
    char name[20];
    char surname[20];
    int birth_year;
} Person;

void generate_person(Person *person) {
    char *names[] = {"John", "Mary", "David", "Sarah", "Michael", "Emily", "James", "Emma", "William", "Olivia"};
    char *surnames[] = {"Smith", "Johnson", "Brown", "Jones", "Garcia", "Davis", "Rodriguez", "Miller", "Martinez", "Wilson"};
    int num_of_names = sizeof(names) / sizeof(names[0]);
    int num_of_surnames = sizeof(surnames) / sizeof(surnames[0]);

    int name_index = rand() % num_of_names;
    int surname_index = rand() % num_of_surnames;
    int birth_year = rand() % 50 + 1970;

    sprintf(person->name, "%s", names[name_index]);
    sprintf(person->surname, "%s", surnames[surname_index]);
    person->birth_year = birth_year;
}

int main() {
    srand(time(NULL));

    FILE *out_file = fopen("output.txt", "w");
    if (out_file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    for (int i = 0; i < NUM_OF_RECORDS; i++) {
        Person person;
        generate_person(&person);
        fprintf(out_file, "%s %s %d\n", person.name, person.surname, person.birth_year);
    }

    fclose(out_file);

    return 0;
}
