#include<stdio.h>
#include<stdlib.h>

struct twoStacks
{
    int *arr;
    int size;
    int top1, top2;
};
 
void initstack(struct twoStacks *p, int size);
void push1(struct twoStacks *p, int item);
void push2(struct twoStacks *p, int item);
int pop1(struct twoStacks *p);
int pop2(struct twoStacks *p);
void display1(struct twoStacks p);
void display2(struct twoStacks p);
void printMenu();

int main()
{
    struct twoStacks ts;
    int n, ch = 1, a;
    printf("Enter the maximum size of the stack\n");
    scanf("%d", &n);
    initstack(&ts, n);
    do
    {
        printMenu();
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("Enter the element to be pushed in stack1\n");
                scanf("%d", &a);
                push1(&ts, a);
                break;
            case 2:
                printf("Enter the element to be pushed in stack2\n");
                scanf("%d", &a);
                push2(&ts, a);
                break;
            case 3:
                a = pop1(&ts);
                if(a != -1000)
                    printf("The popped element from stack1 is %d\n", a);
                break;
            case 4:
                a = pop2(&ts);
                if(a != -1000)
                    printf("The popped element from stack2 is %d\n", a);
                break;
            case 5:
                printf("The contents of the stack1 are");
                display1(ts);
                printf("\n");
                break;
            case 6:
                printf("The contents of the stack2 are");
                display2(ts);
                printf("\n");
                break;
            default:
                return 0;
        }
    } while(1);
    return 0;
}

void initstack(struct twoStacks *p, int size)  
{
    p->arr = (int *)malloc(size * sizeof(int));
    p->size = size;
    p->top1 = -1;
    p->top2 = size;
}

void push1(struct twoStacks *p, int item)
{
    if (p->top1 < p->top2 - 1)
    {
        p->arr[++(p->top1)] = item;
    }
    else
    {
        printf("Stack1 is full\n");
    }
}

void push2(struct twoStacks *p, int item)
{
    if (p->top1 < p->top2 - 1)
    {
        p->arr[--(p->top2)] = item;
    }
    else
    {
        printf("Stack2 is full\n");
    }
}

int pop1(struct twoStacks *p)
{
    if (p->top1 >= 0)
    {
        return p->arr[(p->top1)--];
    }
    else
    {
        printf("Stack1 is empty\n");
        return -1000;
    }
}

int pop2(struct twoStacks *p)
{
    if (p->top2 < p->size)
    {
        return p->arr[(p->top2)++];
    }
    else
    {
        printf("Stack2 is empty\n");
        return -1000;
    }
}
void display1(struct twoStacks p)
{
    if (p.top1 == -1)
    {
        printf(" {}\n");
        return;
    }
    printf(" ");
    for (int i = 0; i <= p.top1; i++)
    {
        printf("%d ", p.arr[i]);
    }
}

void display2(struct twoStacks p)
{
    if (p.top2 == p.size)
    {
        printf(" {}\n");
        return;
    }
    printf(" ");
    for (int i = p.size - 1; i >= p.top2; i--)
    {
        printf("%d ", p.arr[i]);
    }
}



void printMenu()
{
    printf("Choice 1 : Push1\n");
    printf("Choice 2 : Push2\n");
    printf("Choice 3 : Pop1\n");
    printf("Choice 4 : Pop2\n");
    printf("Choice 5 : Display1\n");
    printf("Choice 6 : Display2\n");
    printf("Any other choice : Exit\n");
}
