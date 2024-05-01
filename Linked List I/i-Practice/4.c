#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
	int data;
	struct node * link;
};
void append ( struct node **, int ) ;
void display ( struct node * ) ;
void addafter ( struct node *, int, int ) ;

int main() {
	struct node *p ;
	p=NULL;
	int n,l;
	char ch[10];
	do {
		printf("Enter the value\n");
		scanf("%d",&n);
		append(&p,n);
		printf("Do you want to append another node? Type Yes/No\n");
		scanf("%s",ch);
	}while(!strcmp(ch,"Yes"));
	printf("The elements in the linked list are");
	display(p);
	printf("\n");
	do {
		printf("Enter the position after which you want to add another node\n");
		scanf("%d",&l);
		printf("Enter the value\n");
		scanf("%d",&n);
		addafter(p,l,n);
		printf("The elements in the linked list are ");
		display(p);
		printf("\n");
		printf("Do you want to add another node after a certain position? Type Yes/No\n");
		scanf("%s",ch);
	}while(!strcmp(ch,"Yes"));
	return 0;
}

void append ( struct node **q, int num ) {
	struct node *nn=(struct node *)malloc(sizeof(struct node));
	struct node *temp=*q;
	nn->data=num;
	nn->link=NULL;
	if(*q==NULL){
	    *q=nn;
	}else{
	    while(temp->link!=NULL){
	        temp=temp->link;
	    }temp->link=nn;
	}
}

void display ( struct node *q ) {
	// Fill in the code here
	struct node *temp = q;
	while(temp) {
		printf("%d ", temp->data);
		temp = temp ->link;
	}
}
void addafter ( struct node *q, int loc, int num ) {
	// Fill in the code here	
	struct node *temp = q;
	struct node *newNode;
	newNode = (struct node *)malloc(sizeof(struct node ));
	newNode->data=num;
	newNode->link=NULL;
	int i = 0;
	while(i < loc && temp) {
		temp = temp->link;
		i++;
	}
	if (temp==NULL ) {
		printf("There are less than %d elements in the linked list" ,loc);
		return ;
	}
	newNode->link=temp->link;
	temp->link=newNode;
}
