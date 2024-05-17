#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int id;
    char name[10];
    char gender[10];
    struct student *prev;
    struct student *next;
};

struct student* createNode(int id, char name[], char gender[]) {
    struct student *newNode = (struct student*)malloc(sizeof(struct student));
    newNode->id = id;
    strcpy(newNode->name, name);
    strcpy(newNode->gender, gender);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void append(struct student **head, int id, char name[], char gender[]) {
    struct student *newNode = createNode(id, name, gender);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct student *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void display(struct student *head) {
    struct student *temp = head;
    printf("  ID       Name  Gender\n");
    while (temp != NULL) {
        printf("%4d %10s %7s\n", temp->id, temp->name, temp->gender);
        temp = temp->next;
    }
}

void deleteAlternative(struct student **head) {
    if (*head == NULL) return;
    struct student *temp = *head;
    while (temp != NULL && temp->next != NULL) {
        struct student *toDelete = temp->next;
        temp->next = temp->next->next;
        if (temp->next != NULL) {
            temp->next->prev = temp;
        }
        free(toDelete);
        temp = temp->next;
    }
}

int main() {
    struct student *head = NULL;
    int id;
    char name[10];
    char gender[10];
    char choice[4];

    do {
        printf("Enter the id\n");
        scanf("%d", &id);
        printf("Enter the name\n");
        scanf("%s", name);
        printf("Enter the gender\n");
        scanf("%s", gender);
        append(&head, id, name, gender);
        printf("Do you want to add details of another student? Type Yes/No\n");
        scanf("%s", choice);
    } while (strcmp(choice, "Yes") == 0);

    printf("The details of the students are\n");
    display(head);

    deleteAlternative(&head);

    printf("The details of the students after deleting are\n");
    display(head);

    return 0;
}
