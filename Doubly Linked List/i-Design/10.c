#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Student structure
struct Student {
    int id;
    char name[10];
    char gender[10];
    struct Student* prev;
    struct Student* next;
};

// Function to create a new student node
struct Student* createStudent(int id, const char* name, const char* gender) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->id = id;
    strcpy(newStudent->name, name);
    strcpy(newStudent->gender, gender);
    newStudent->prev = NULL;
    newStudent->next = NULL;
    return newStudent;
}

// Function to append a student to the end of the linked list
struct Student* append(struct Student* head, struct Student* newStudent) {
    if (head == NULL) {
        return newStudent;
    }

    struct Student* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newStudent;
    newStudent->prev = temp;
    return head;
}

// Function to display all students' details
void display(struct Student* head) {
    struct Student* temp = head;
    while (temp != NULL) {
        printf("%4d %10s %7s\n", temp->id, temp->name, temp->gender);
        temp = temp->next;
    }
}

// Function to move the last student to the front of the list
struct Student* moveLastToFront(struct Student* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct Student* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    temp->prev = NULL;
    temp->next = head;
    head->prev = temp;
    return temp;
}

int main() {
    struct Student* head = NULL;
    char choice[5];

    do {
        printf("Enter the id\n");
        int id;
        scanf("%d", &id);

        printf("Enter the name\n");
        char name[10];
        scanf("%s", name);

        printf("Enter the gender\n");
        char gender[10];
        scanf("%s", gender);

        head = append(head, createStudent(id, name, gender));

        printf("Do you want to add details of another student? Type Yes/No\n");
        scanf("%s", choice);
    } while (strcmp(choice, "Yes") == 0);

    printf("The details of the students are\n");
    printf("%4s %10s %7s\n", "ID", "Name", "Gender");
    display(head);

    head = moveLastToFront(head);

    printf("The details of the students are after moving last student to front\n");
    printf("%4s %10s %7s\n", "ID", "Name", "Gender");
    display(head);

    return 0;
}
