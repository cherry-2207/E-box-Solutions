#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} Node;

/* Function to insert a node in a circular queue */
void addcirq(struct node **f, struct node **r, int item)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = item;
    if (*f == NULL) {
        *f = newNode;
    } else {
        (*r)->next = newNode;
    }
    *r = newNode;
    (*r)->next = *f;
}

/* Function to delete a node in a circular queue */
int delcirq(struct node **f, struct node **r) 
{
    if (*f == NULL) {
        printf("Queue is empty\n");
        return -1000;
    }
    Node *temp = *f;
    int deletedData = temp->data;
    if (*f == *r) {
        *f = NULL;
        *r = NULL;
    } else {
        *f = (*f)->next;
        (*r)->next = *f;
    }
    free(temp);
    return deletedData;
}

/* Function to display the contents of the circular queue */
void cirq_display(struct node *f)
{
    if (f == NULL) {
        printf(" {}\n");
        return;
    }
    Node *temp = f;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != f);
}

/* Function to print the menu */
void printMenu()
{
    printf("Choice 1 : Enter element into Queue\n");
    printf("Choice 2 : Delete element from Queue\n");
    printf("Choice 3 : Display\n");
    printf("Any other choice : Exit\n");
    printf("Enter your choice\n");
}

int main() 
{
    int data, ch, data1;
    Node *front = NULL, *rear = NULL;
    do {
        printMenu();
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the element to be inserted/entered\n");
                scanf("%d", &data);
                addcirq(&front, &rear, data);
                break;
            case 2:
                data1 = delcirq(&front, &rear);
                if (data1 != -1000)
                    printf("The deleted element is %d\n", data1);
                break;
            case 3:
                printf("The contents of the queue are");
                cirq_display(front);
                printf("\n");
                break;
        }
    } while (ch > 0 && ch < 4);
    return 0;
}
