#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
int data;
struct node * link;
};
void append ( struct node **, int ) ;
void display ( struct node * ) ;
void delafter ( struct node *, int ) ;

int main() {
struct node *p ;
p=NULL;
int n,l;
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
do {
printf("Enter the position after which you want to delete another node\n");
scanf("%d",&l);
delafter(p,l);
printf("The elements in the linked list are");
display(p);
printf("\n");
printf("Do you want to delete another node after a certain position? Type Yes/No\n");
scanf("%s",ch);
}while(!strcmp(ch,"Yes"));
return 0;
}

void append ( struct node **q, int num ) {
// Fill in the code here
struct node *new,*last;
         
         new = (struct node *)malloc(sizeof(struct node));
         new->data=num;
         new->link=NULL;
       
       if(*q==NULL)
        { *q=new;
        }
       else
       {
        last=*q;
       while(last->link !=NULL)
        {
             last=last->link;
             
        }
       
      last->link=new;
       }


}

void display ( struct node *q ) {
// Fill in the code here
struct node *s;
s=q;
  while(s!=NULL)
  {
   printf("%d",s->data);
   s=s->link;
  }
   
}

void delafter ( struct node *q, int loc ) {
// Fill in the code here
struct node *temp,*prev;
int i=1;
temp=q;

while(temp->link!=NULL)
{ temp=temp->link;
 i++;
}
if(loc>i-1){
   printf("Invalid position");
}
else{
   temp=q;
   i=0;
   while(temp->link!=NULL)
{
       prev=temp;
       temp=temp->link;
      i++;
      if(loc==i){
          break;
      }
     
}
prev->link=temp->link;
}


}
