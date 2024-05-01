#include<stdio.h>
#include<stdlib.h>
struct compartment
{
int number;
struct compartment * link;
};

void append (struct compartment **q,int n);
void insert(struct compartment **q,int n);
void display(struct compartment *q);
void merge(struct compartment **p,struct compartment **q);
void sort(struct compartment **p);
void append (struct compartment **q,int num)
{
    struct compartment *nn=(struct compartment*)malloc(sizeof(struct compartment)),*temp;
    nn->number=num;
	nn->link=NULL;
	if(*q==NULL)
	*q=nn;
	else
	{
		temp=*q;

		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		temp->link=nn;
	}	
	sort(q);
}
void display(struct compartment *q)
{
	 if(q==NULL){
		 printf("Track is Empty\n");
		 return ;
	 }
	 struct compartment *temp=(struct compartment*)malloc(sizeof(struct compartment));
	 temp=q;
	 printf("Compartments are:");
	 while(temp!=NULL){
		 printf("%d ",temp->number);
		 temp=temp->link;
	 }
	 printf("\n");
}
void merge(struct compartment **p,struct compartment **q)
{
	 if(*p==NULL && *q==NULL){
		 printf("No compartments were found.File complaint to railway enquiry\n");
		 return ;
	 }
	 struct compartment *temp=(struct compartment*)malloc(sizeof(struct compartment));
	 temp=*p;
	 while(temp->link!=NULL){
		 temp=temp->link;
	 }
	 temp->link=*q;
	 sort(p);
	 display(*p);
}
void sort(struct compartment **p)
{
 struct compartment *temp;
    if (*p == NULL || (*p)->link == NULL)
        return;

    int swapped;
    do {
        swapped = 0;
        temp = *p;
        while (temp->link != NULL) {
            if (temp->number > temp->link->number) {
                int tmp = temp->number;
                temp->number = temp->link->number;
                temp->link->number = tmp;
                swapped = 1;
            }
            temp = temp->link;
        }
    } while (swapped);
}
int main()
{
    int n,choice=1;
	struct compartment *list1;
	struct compartment *list2;
	list1 = NULL;
	list2 = NULL;
while(choice!=6)
{
	printf("1.Insert compartment in the first track\n2.Insert compartment in the second track\n3.Display track 1\n4.Display track 2\n5.Merge compartments\n6.Exit\nEnter your choice\n");
	scanf("%d",&choice);
switch(choice){
case 1:
	printf("Enter the compartment number\n");
	scanf("%d",&n);
	append(&list1,n);
	break;
case 2:
	printf("Enter the compartment number\n");
	scanf("%d",&n);
	append(&list2,n);
	break;
case 3:
	display(list1);
	break;
case 4:
	display(list2);
	break;
case 5:
	 merge(&list1,&list2);
	break;
case 6:
	printf("Exit\n");
	}
}
	return 0;
}
