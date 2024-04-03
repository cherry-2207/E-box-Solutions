#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct food_court
{
  int data;
  struct food_court*link;
};
void append(struct food_court**,int);
void display(struct food_court*);
int sum(struct food_court*);
int main()
{
  int n,b;
  struct food_court*p;
  p=NULL;
  int x=0;
  do
  {
    printf("1.Visit the food court\n");
	printf("2.View my transactions\n");  
	printf("3.Show my points\n");
	printf("Enter your choice\n");
	scanf("%d",&x);
switch(x)
{
case 1:
    	printf("Pay bill amount:\n");
    	scanf("%d",&n);
    	append(&p,n);
	break;

case 2:
	if(p!=NULL)
	{
		printf("Card transactions :\n");
		display(p);
	}
	else
	{

		printf("No transactions found\n");
	}
	break;
case 3:
	if(p!=NULL)
	{
		b=sum(p);
		printf("Gained points :%d\n",b);
	}
	else
	{
		printf("Your score is NIL\n");
	}
	break;
case 4:
	printf("Please visit again\n");
	break;    
    
  }}while(x!=4);
  return 0;
}
struct food_court *temp = NULL;
void append(struct food_court**q,int data)
{
// Fill in the code here
	struct food_court *newNode = (struct food_court *)malloc(sizeof(struct food_court *));
	newNode->data=data;
	newNode->link=NULL;
	if(*q==NULL){
		*q=newNode;
		temp=newNode;
		return;
	}
	temp->link=newNode;
	temp=newNode;
	return;
}
void display(struct food_court*q)
{
 // Fill in the code here
 // q is head pointer
 struct food_court *temp;
 temp = q;
 while(temp != NULL)
{
	printf("%d\n ", temp->data);
	temp = temp -> link;
}
}

int sum(struct food_court*q)
{
// Fill in the code here
struct food_court *temp;
temp = q;
int Sum = 0;
while(temp != NULL)
{
	Sum += (temp -> data);
	temp = temp -> link;
}
return Sum;
}
