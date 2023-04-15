#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
    char first_name[50];
    char last_name[50];
    char gender[10];
    int birth_year;
    int height;
};

int compare_birth_year(const void *p1, const void *p2) {
    const struct User *user1 = p1;
    const struct User *user2 = p2;
    return user1->birth_year - user2->birth_year;
}

int compare_name(const void *p1, const void *p2) {
    const struct User *user1 = p1;
    const struct User *user2 = p2;
    int cmp = strcmp(user1->last_name, user2->last_name);
    if (cmp == 0) {
        cmp = strcmp(user1->first_name, user2->first_name);
    }
    return cmp;
}

int compare_gender(const void *p1, const void *p2) {
    const struct User *user1 = p1;
    const struct User *user2 = p2;
    int cmp = strcmp(user1->gender, user2->gender);
    return cmp;
}

int compare_height(const void *p1, const void *p2) {
    const struct User *user1 = p1;
    const struct User *user2 = p2;
    return user1->height - user2->height;
}

void print_users(struct User *users, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s %s, %d, %s, %dcm\n", users[i].first_name, users[i].last_name, users[i].birth_year, users[i].gender, users[i].height);
    }
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    int count = 0;
    struct User users[100];

    while (fscanf(fp, "%s %s %s %d %d\n", users[count].first_name, users[count].last_name, users[count].gender, &users[count].birth_year, &users[count].height) == 5) {
        count++;
    }

    fclose(fp);

    printf("Sort by which field? (1=birth year, 2=name, 3=gender, 4=height): ");
    int field;
    scanf("%d", &field);

    switch (field) {
        case 1:
            qsort(users, count, sizeof(struct User), compare_birth_year);
            break;
        case 2:
            qsort(users, count, sizeof(struct User), compare_name);
            break;
        case 3:
            qsort(users, count, sizeof(struct User), compare_gender);
            break;
        case 4:
            qsort(users, count, sizeof(struct User), compare_height);
            break;
        default:
            printf("Invalid field %d\n", field);
            return 1;
    }

    print_users(users, count);

    return 0;
}