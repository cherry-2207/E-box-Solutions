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
void addafter ( struct student *,struct student,int) ;

int main() {
	struct student *p ;
	struct student s;
	int loc;
	p=NULL;
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
	do {
		printf("Enter the position after which you want to add another node\n");
		scanf("%d",&loc);
		printf("Enter the id\n");
		scanf("%d",&s.id);
        printf("Enter the name\n");
 		scanf("%s",s.name); 
		printf("Enter the gender\n");
		scanf("%s",s.gender);
		addafter(p,s,loc);
	        printf("The details of the students are\n");
	        printf("%4s%15s%7s\n","ID","Name","Gender");
		display(p);
		printf("Do you want to add details of another student after a certain position? Type Yes/No\n");
		scanf("%s",ch);
	}while(!strcmp(ch,"Yes"));
	return 0;
}

void append ( struct student **q, struct student s)
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
      new->next=NULL;
      
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

void addafter ( struct student *q,  struct student s,int loc)
{
	// Fill in the code here
	struct student *temp,*new;
	int i;
	new=(struct student *) malloc(sizeof(struct student));
	new->id=s.id;
	strcpy(new->name,s.name);
	strcpy(new->gender,s.gender);
	new->prev=NULL;
	new->next=NULL;

	temp=q;
	for(i=0;(i<loc)&&(temp!=NULL);i++)
	   temp=temp->next;
	if ( temp == NULL ){
	    printf("There are less than %d students in the list\n" , loc );
	    return;
	}   
	new->next=temp->next;
	if( temp->next !=NULL )
	    temp->next->prev=new;
	temp->next = new;
	new->prev=temp;
	
	
	
}
