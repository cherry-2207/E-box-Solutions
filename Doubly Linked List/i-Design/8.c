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

struct student *head = NULL;

void append(int id, char name[], char gender[]) {
    struct student *temp, *newStudent;
    newStudent = (struct student *)malloc(sizeof(struct student));
    newStudent->id = id;
    strcpy(newStudent->name, name);
    strcpy(newStudent->gender, gender);
    newStudent->next = NULL;
    if (head == NULL) {
        newStudent->prev = NULL;
        head = newStudent;
        return;
    }
    temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newStudent;
    newStudent->prev = temp;
}

void delstud(char name[]) {
    struct student *temp;
    temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            if (temp == head) {
                head = temp->next;
                if (head != NULL)
                    head->prev = NULL;
            } else {
                temp->prev->next = temp->next;
                if (temp->next != NULL)
                    temp->next->prev = temp->prev;
            }
            free(temp);
            return;
        }
        temp = temp->next;
    }
    printf("Student not found.\n");
}

void display() {
    struct student *temp;
    if (head == NULL) {
        printf("No students to display.\n");
        return;
    }
    printf("%4s%14s%9s\n", "ID", "Name", "Gender");
    temp = head;
    while (temp != NULL) {
        printf("%4d%14s%9s\n", temp->id, temp->name, temp->gender);
        temp = temp->next;
    }
}

int main() {
    int id;
    char name[10], gender[10], choice[3];
    do {
        printf("Enter the id\n");
        scanf("%d", &id);
        printf("Enter the name\n");
        scanf("%s", name);
        printf("Enter the gender\n");
        scanf("%s", gender);
        append(id, name, gender);
        printf("Do you want to add details of another student? Type Yes/No\n");
        scanf("%s", choice);
    } while (strcmp(choice, "Yes") == 0);

    printf("The details of the students are\n");
    display();

    do {
        printf("Enter the name of student to be deleted\n");
        scanf("%s", name);
        delstud(name);
        printf("The details of the students after deleting a student are\n");
        display();
        printf("Do you want to delete details of another student? Type Yes/No\n");
        scanf("%s", choice);
    } while (strcmp(choice, "Yes") == 0);

    return 0;
}
