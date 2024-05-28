#include <stdio.h>
#include <stdlib.h>
#include<stdlib.h>
#include<math.h>
#include <limits.h>

struct stack
{
    int *a;
    int top;
    int maxSize;
};

void initstack(struct stack *p, int maxSize);
void push(struct stack *p, int item);
int pop(struct stack *p);
void moveDisk(char fromPeg, char toPeg, int disk);
void moveDisksBetweenTwoPoles(struct stack *src, struct stack *dest, char s, char d);
void hanoiIterative(int num_of_disks, struct stack *src, struct stack *aux, struct stack *dest);

int main()
{
    int num_of_disks;
    printf("Enter the number of disks\n");
    scanf("%d", &num_of_disks);
    struct stack src, dest, aux;
    initstack(&src, num_of_disks);
    initstack(&aux, num_of_disks);
    initstack(&dest, num_of_disks);
    hanoiIterative(num_of_disks, &src, &aux, &dest);
    return 0;
}

void initstack(struct stack *p, int maxSize)
{
    p->a = (int *)malloc(maxSize * sizeof(int));
    p->top = -1;
    p->maxSize = maxSize;
}

void push(struct stack *p, int item)
{
    if (p->top == p->maxSize - 1)
    {
        return;
    }
    p->top++;
    p->a[p->top] = item;
}

int pop(struct stack *p)
{
    if (p->top == -1)
    {
        return INT_MIN;
    }
    int item = p->a[p->top];
    p->top--;
    return item;
}

void moveDisk(char fromPeg, char toPeg, int disk)
{
    printf("Move the disk %d from '%c' to '%c'\n", disk, fromPeg, toPeg);
}

void moveDisksBetweenTwoPoles(struct stack *src, struct stack *dest, char s, char d)
{
    int pole1TopDisk = pop(src);
    int pole2TopDisk = pop(dest);

    // When pole1 is empty
    if (pole1TopDisk == INT_MIN)
    {
        push(src, pole2TopDisk);
        moveDisk(d, s, pole2TopDisk);
    }
    // When pole2 is empty
    else if (pole2TopDisk == INT_MIN)
    {
        push(dest, pole1TopDisk);
        moveDisk(s, d, pole1TopDisk);
    }
    // When top disk of pole1 > top disk of pole2
    else if (pole1TopDisk > pole2TopDisk)
    {
        push(src, pole1TopDisk);
        push(src, pole2TopDisk);
        moveDisk(d, s, pole2TopDisk);
    }
    // When top disk of pole1 < top disk of pole2
    else
    {
        push(dest, pole2TopDisk);
        push(dest, pole1TopDisk);
        moveDisk(s, d, pole1TopDisk);
    }
}

void hanoiIterative(int num_of_disks, struct stack *src, struct stack *aux, struct stack *dest)
{
    int i, total_moves;
    char s = 'S', d = 'D', a = 'A';

    // If number of disks is even, then interchange auxiliary pole and destination pole
    if (num_of_disks % 2 == 0)
    {
        char temp = d;
        d = a;
        a = temp;
    }
    total_moves = pow(2, num_of_disks) - 1;

    // Larger disks will be pushed first
    for (i = num_of_disks; i >= 1; i--)
    {
        push(src, i);
    }

    for (i = 1; i <= total_moves; i++)
    {
        if (i % 3 == 1)
        {
            moveDisksBetweenTwoPoles(src, dest, s, d);
        }
        else if (i % 3 == 2)
        {
            moveDisksBetweenTwoPoles(src, aux, s, a);
        }
        else if (i % 3 == 0)
        {
            moveDisksBetweenTwoPoles(aux, dest, a, d);
        }
    }
}
