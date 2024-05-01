#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
	int data;
	struct node * link;
};
void append ( struct node **, int ) ;
void display ( struct node * ) ;
void delete (struct node **, int);
struct node *temp = NULL;
int main() {
	struct node *p ;
	p=NULL;
	int n;
	char ch[10];
	do {
		printf("Enter the value\n");
		scanf("%d",&n);
		append(&p,n);
		printf("Do you want to add another node? Type Yes/No\n");
		scanf("%s",ch);
	} while(!strcmp(ch,"Yes"));
	printf("The elements in the linked list are");
	display(p);
	printf("\n");
	printf("Enter the element to be deleted\n");
	scanf("%d",&n);
	delete(&p,n);
	printf("The elements in the linked list after deleting the element are");
	display(p);
	printf("\n");
	return 0;
}

void append ( struct node **q, int num ) {
	// Fill in the code here
	struct node *newNode = (struct node *)malloc(sizeof(struct node *));
	newNode -> data = num;
	newNode -> link = NULL;
	if(*q == NULL)
	{
		*q = newNode;
		temp = newNode;
		return;
	} 
	temp -> link = newNode;
	temp = newNode;
}

void display ( struct node *q ) {
	// Fill in the code here
	temp = q;
	while(temp != NULL) {
		printf("%d ", temp->data);
		temp = temp -> link;
	}
	printf("\n");
}


void delete ( struct node **q, int num ) {
	// Fill in the code here
	struct node *temp = *q, *prev;

    // If the list is empty, return
    if (temp == NULL)
        return;

    // If the key is found at the head node
    if (temp != NULL && temp->data == num) {
        *q = temp->link; // Change head
        free(temp); // Free old head
        return;
    }

    // Search for the key to be deleted, keep track of the previous node as well
    while (temp != NULL && temp->data !=num) {
        prev = temp;
        temp = temp->link;
    }

    // If key was not present in the list
    if (temp == NULL)
        return;

    // Unlink the node from linked list
    prev->link= temp->link;

    // Free the memory
    free(temp);
}
