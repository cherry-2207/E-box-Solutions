#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
	int data;
	struct node * link;
};
void append ( struct node **, int ) ;
void display ( struct node * ) ;
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
	}while(!strcmp(ch,"Yes"));
	printf("The elements in the linked list are");
	display(p);
	printf("\n");
	return 0;
}

/* adds a node at the end of a linked list */
void append ( struct node **q, int num ){
	//Fill in the code here
	// q is head  node and link is next pointer
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
	return;
}

void display ( struct node *q ){
	//Fill in the code here
	temp = q;
	while(temp != NULL) {
		printf("%d\n", temp->data);
		temp = temp->link;
	}
}
