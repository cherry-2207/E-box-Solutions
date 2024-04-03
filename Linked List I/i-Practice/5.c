#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
	int data;
	struct node * link;
};
void append ( struct node **, int ) ;
void display ( struct node * ) ;
int search (struct node *, int);
struct node *temp = NULL;

int main() {
	struct node *p ;
	p=NULL;
	int n,ele;
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
	printf("Enter the element to be searched\n");
	scanf("%d",&ele);
	if(search(p,ele))
		printf("%d is present in the linked list\n",ele);
	else
		printf("%d is not present in the linked list\n",ele);
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
	return;
}

void display ( struct node *q ) {
	// Fill in the code here
	temp = q;
	while(temp != NULL) {
		printf("%d\n", temp->data);
		temp = temp->link;
	}
}
int search ( struct node *q, int e ) {
	// Fill in the code here
	temp = q;
	while(temp != NULL) {
		if(temp -> data == e)
			return 1;
		temp = temp -> link;
	}
	return 0;
}
