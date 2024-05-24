#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct ticket {
int number;
struct ticket * link;
};
void append ( struct ticket **, int ) ;
void display ( struct ticket * ) ;
void addafter ( struct ticket *, int, int ) ;

int main() {
struct ticket *p ;
p=NULL;
int n,l;
int choice=1;
	
	while(choice!=4)
	{
	printf("1.Enter ticket number occupying wrong seat\n2.Arrange the seating position\n3.Display current seating position\n4.Exit\nEnter your choice\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter the ticket number\n");
				scanf("%d",&n);
				append(&p,n);
				break;
			case 2:				
				printf("Enter the position of the ticket\n");
				scanf("%d",&l);
				printf("Enter the ticket number\n");
				scanf("%d",&n);
				addafter(p,l,n);
				break;
			case 3:
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
void append(struct ticket **q, int num) {
    struct ticket *temp, *r;
    temp = *q;
    if (*q == NULL) {
        *q = (struct ticket *)malloc(sizeof(struct ticket));
        (*q)->number = num;
        (*q)->link = NULL;
    } else {
        while (temp->link != NULL)
            temp = temp->link;
        r = (struct ticket *)malloc(sizeof(struct ticket));
        r->number = num;
        r->link = NULL;
        temp->link = r;
    }
}

void display(struct ticket *q) {
    if (q == NULL) {
        printf("No tickets entered yet.\n");
    } else {
        printf("Seating position are:");
        while (q != NULL) {
            printf("%d", q->number);
            q = q->link;
        }
        printf("\n");
    }
}

void addafter(struct ticket *q, int loc, int num) {
    struct ticket *temp, *r;
    temp = q;
    for (int i = 0; i < loc - 1 && temp != NULL; i++)
        temp = temp->link;
    if (temp == NULL) {
        printf("No body has occupied ticket number %d at position %d.\n", num,loc);
    } else {
        r = (struct ticket *)malloc(sizeof(struct ticket));
        r->number = num;
        r->link = temp->link;
        temp->link = r;
        printf("Wrong seat has been moved.\n");
    }
}
