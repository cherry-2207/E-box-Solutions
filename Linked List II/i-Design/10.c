#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
  int id;
  char name[10];
  char gender[10];
  struct student * link;
};
void append ( struct student **, struct student ) ;
void display ( struct student * ) ;
void reverse (struct student **);
struct student *temp;
int main() {
	struct student *p ;
	p=NULL;
	struct student s;
        char ch[10];
	do {
		printf("Enter the id\n");
		scanf("%d",&s.id);
                printf("Enter the name\n");
		scanf("%s",s.name); 
		printf("Enter the gender\n");
		scanf("%s",s.gender);
		append(&p,s);
                printf("Do you want to add details of another student? Type Yes/No\n");
		scanf("%s",ch);
	} while(!strcmp(ch,"Yes"));
	printf("The details of the students are\n");
        printf("%4s %10s %6s\n","ID","Name","Gender");
	display(p);
	printf("The details of the students after reversing are\n");
        printf("%4s %10s %6s\n","ID","Name","Gender");
	reverse(&p);
	display(p);
	return 0;
}


void append ( struct student **q, struct student s ) {
	//Fill in the code here
	struct student *temp, *right;
    temp = (struct student *)malloc(sizeof(struct student ));
    temp->id = s.id;
    strcpy(temp->name, s.name);
    strcpy(temp->gender, s.gender);
    temp->link = NULL;
    if (*q == NULL)
    {
        *q = temp;
    }
    else
    {
        right = *q;
        while (right->link != NULL)
        {
            right = right->link;
        }
        right->link = temp;
    }
}

void display ( struct student *q ) {
  struct student * temp=q;
  while(temp!=NULL)
  {
	    printf("%4d ",temp->id);
	    printf("%10s ",temp->name);
	    printf("%6s ",temp->gender);
            printf("\n");
    temp=temp->link;
  }
}

void reverse ( struct student **x ) {
       //Fill in the code here
	   struct student *prevptr, *currptr, *nextptr;
	   prevptr = NULL;
	   currptr = *x;
	   while(currptr != NULL) {
		   nextptr = currptr->link;
		   currptr->link = prevptr;
		   prevptr = currptr;
		   currptr = nextptr;
	   }
	   *x = prevptr;
 }
