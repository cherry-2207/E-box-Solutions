#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int id;
    char name[10];
    char gender[10];
    struct student* prev;
    struct student* next;
};

void append(struct student** head, int id, const char* name, const char* gender) {
    struct student* newNode = (struct student*)malloc(sizeof(struct student));
    newNode->id = id;
    strcpy(newNode->name, name);
    strcpy(newNode->gender, gender);
    newNode->prev = NULL;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct student* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void delatend(struct student** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct student* temp = *head;
    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

void display(struct student* head) {
    while (head != NULL) {
        printf("%4d %10s %7s\n", head->id, head->name, head->gender);
        head = head->next;
    }
}

int main() {
    struct student* students = NULL;
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

        append(&students, id, name, gender);

        printf("Do you want to add details of another student? Type Yes/No\n");
        scanf("%s", ch);
    } while (strcmp(ch, "Yes") == 0);

    printf("The details of the students are\n");
    printf("%4s %10s %7s\n", "ID", "Name", "Gender");
    display(students);

    do {
        delatend(&students);
        printf("The details of the students after deleting a student are\n");
        printf("%4s %10s %7s\n", "ID", "Name", "Gender");
        display(students);

        printf("Do you want to delete details of another student? Type Yes/No\n");
        scanf("%s", ch);
    } while (strcmp(ch, "Yes") == 0);

    return 0;
}
