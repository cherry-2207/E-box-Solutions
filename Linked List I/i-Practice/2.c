#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
	int data;
	struct node * link;
};
void append ( struct node **, int ) ;
void display ( struct node * ) ;
int count ( struct node * ) ;
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
	printf("The number of elements in the linked list is %d\n",count(p));
	return 0;
}

void append ( struct node **q, int num ) {
	//Fill in the code here
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
	//Fill in the code here
	temp = q;
	while(temp != NULL) {
		printf("%d\n", temp->data);
		temp = temp->link;
	}
}

int count ( struct node * q ) {
	//Fill in the code here
	int Count = 0;
	temp = q;
	while(temp != NULL) {
		Count++;
		temp = temp -> link;
	}
	return Count;
}
