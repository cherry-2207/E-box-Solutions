#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct employee 
{
	int id;
	struct employee * link;
};
void append ( struct employee **, int ) ;
void display ( struct employee * ) ;
void deleteanyelement (struct employee **, int);

int main() 
{
	struct employee *p ;
	p=NULL;
	int n,choice;
while(choice!=4)
	{
	printf("1.Insert a new Employee\n2.Display the Employees\n3.Remove an Employee ID\n4.Exit\nEnter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter an Employee id\n");
				scanf("%d",&n);
				append(&p,n);
				break;
			case 2:
				display(p);
				break;
			case 3:
				printf("Enter an Employee id to be removed\n");
				scanf("%d",&n);
				deleteanyelement(&p,n);
				display(p);
				break;
			case 4:
				printf("Exit\n");
				break;
			default:
				printf("Enter a valid choice");
				break;
			}
		}
	return 0;
}

void append ( struct employee **q, int num )
{
// Fill in the code here void append(struct employee** head_ref, int new_id) {
struct employee* new_employee = (struct employee*) malloc(sizeof(struct employee));
    struct employee* last = *q;
    new_employee->id = num;
    new_employee->link = NULL;
    if (*q == NULL) {
        *q = new_employee;
        return;
    }
    while (last->link != NULL) {
        last = last->link;
    }
    last->link = new_employee;
    return;

}

void display ( struct employee *q )
{
// Fill in the code here
if (q == NULL) {
        printf("Employees ID list is empty\n");
        return;
    }
    printf("Employees ID list:\n");
    while (q != NULL) {
        printf("%d\n", q->id);
        q = q->link;
    }
}



void deleteanyelement ( struct employee **q, int num )
{
// Fill in the code here 

//void deleteanyelement(struct employee **head_ref, int key
 struct employee *temp = *q, *prev;
    if (temp != NULL && temp->id == num) {
        *q = temp->link;
        free(temp);
        printf("Employee ID are removed from the Company.\n");
        return;
    }
    while (temp != NULL && temp->id != num) {
        prev = temp;
        temp = temp->link;
    }
    if (temp == NULL) {
        printf("Employee ID %d is not found\n", num);
        return;
    }
    prev->link = temp->link;
    free(temp);
    printf("Employee ID are removed from the Company.\n");
}
