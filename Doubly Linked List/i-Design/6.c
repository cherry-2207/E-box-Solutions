#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[10];
    char gender[10];
    struct Student* prev;
    struct Student* next;
};

void append(struct Student** q, struct Student s) {
    struct Student* newNode = (struct Student*)malloc(sizeof(struct Student));
    *newNode = s;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*q == NULL) {
        *q = newNode;
    } else {
        struct Student* temp = *q;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void display(struct Student* q) {
    while (q != NULL) {
        printf("%4d %10s %7s\n", q->id, q->name, q->gender);
        q = q->next;
    }
}

void delAtBeg(struct Student** q) {
    if (*q == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Student* temp = *q;
    *q = (*q)->next;
    if (*q != NULL) {
        (*q)->prev = NULL;
    }
    free(temp);
}

int main() {
    struct Student* students = NULL;
    char ch[3];

    do {
        int id;
        char name[10];
        char gender[10];

        printf("Enter the id\n");
        scanf("%d", &id);
        printf("Enter the name\n");
        scanf("%s", name);
        printf("Enter the gender\n");
        scanf("%s", gender);

        struct Student s;
        s.id = id;
        strcpy(s.name, name);
        strcpy(s.gender, gender);

        append(&students, s);

        printf("Do you want to add details of another student? Type Yes/No\n");
        scanf("%s", ch);
    } while (strcmp(ch, "Yes") == 0);

    printf("The details of the students are\n");
    printf("%4s %10s %7s\n", "ID", "Name", "Gender");
    display(students);

    do {
        delAtBeg(&students);
        printf("The details of the students after deleting a student are\n");
        printf("%4s %10s %7s\n", "ID", "Name", "Gender");
        display(students);

        printf("Do you want to delete details of another student? Type Yes/No\n");
        scanf("%s", ch);
    } while (strcmp(ch, "Yes") == 0);

    return 0;
}
