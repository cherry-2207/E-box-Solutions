#include<stdio.h>
struct stack {
	int a[5];
	int top;
};
void initstack(struct stack * p);
void push(struct stack * p, int item);
void display(struct stack p);
int pop(struct stack * p);
void printMenu();

int main()  {
	struct stack p;
	int data,ch, data1;
	initstack(&p);
        do {
	printMenu();	
	printf("Enter your choice\n");
	scanf("%d",&ch);
	switch(ch) {
	  case 1:
		printf("Enter the element to be pushed\n");
		scanf("%d",&data);
		push(&p, data);
		break;
	  case 2:
		data1 = pop(&p);
		if(data1 != -1000)
		printf("The popped element is %d\n",data1);
		break;
	  case 3:
		printf("The contents of the stack are");
		display(p);
		printf("\n");
		break;
	  default:
		return 0;
	}
	} while(1);
	return 0;
}

void printMenu()
{
	printf("Choice 1 : Push\n");
	printf("Choice 2 : Pop\n");
	printf("Choice 3 : Display\n");
	printf("Any other choice : Exit\n");
}

void initstack(struct stack * p) {
	(p->top)=-1;
}

void push(struct stack * p, int item) {
	if ((p->top)==4)
		printf("Stack is full\n");
	else
		p->a[++(p->top)] = item;
}

void display(struct stack p) {
	if ((p.top)==-1)
		printf(" {}");
	else
		for (int i=0;i<=(p.top); i++)
			printf(" %d", p.a[i]);
}

int pop(struct stack * p) {
	if ((p->top)==-1) {
		printf("Stack is empty\n");
		return -1000;
	} else {
		return p->a[(p->top)--];
	}
}
