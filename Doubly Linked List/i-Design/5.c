#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
  int id;
  char name[10];
  char gender[10];
  struct student * prev;
  struct student * next;
};

void append ( struct student **, struct student ) ;
void display ( struct student * ) ;
int search (struct student *, struct student,char *);


int main() {
	struct student *p ;
	struct student s ;
	p=NULL;
	char n[10];
        char ch[10];
	do {
		printf("Enter the id\n");
		scanf("%d",&s.id);
                printf("Enter the name\n");
		scanf("%s",s.name); 
		printf("Enter the gender\n");
		scanf("%s",s.gender);
                s.prev = NULL;
                s.next = NULL;
		append(&p,s);
		printf("Do you want to add details of another student? Type Yes/No\n");
		scanf("%s",ch);
	}while(!strcmp(ch,"Yes"));
        printf("The details of the students are\n");
        printf("%4s %10s %7s\n","ID","Name","Gender");
	display(p);
	printf("Enter the name of the student to be searched\n");
	scanf("%s",n);
	if(search(p,s,n))
		printf("%s is present in the list\n",n);
	else
		printf("%s is not present in the list\n",n);
	return 0;
}


void append ( struct student **q, struct student s ) 
{
	// Fill in the code here
	struct student *last,*new;
	new=(struct student *) malloc(sizeof(struct student));
	new->id=s.id;
	strcpy(new->name,s.name);
	strcpy(new->gender,s.gender);
	new->prev=NULL;
	new->next=NULL;
	if(*q==NULL)
        *q=new;
    else
      {last=*q;
      while(last->next!=NULL)
      {last=last->next;
      }
      last->next=new;
      new->prev=last;
     
      }
}

void display ( struct student *q ) 
{
    struct student *temp=q;
    while(temp!=NULL)
    {
    printf("%4d ",temp->id);
    printf("%10s ",temp->name);
    printf("%7s ",temp->gender);
    printf("\n");
    temp=temp->next;
    }
}
int search ( struct student *q, struct student s ,char *n) 
{
  	// Fill in the code here
  	struct student *temp;
  	temp=q;
  	while(temp!=NULL)
  	{
  	  if( strcmp(temp->name, n)==0 )
  	      return 1;
  	   temp=temp->next;
  	}
  	return 0;
  	
}
