#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int items[MAX_SIZE];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = value;
}

int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->items[(s->top)--];
}

int peek(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->items[s->top];
}

void enqueue(struct Stack *s1, struct Stack *s2, int value) {
    push(s1, value);
}

int dequeue(struct Stack *s1, struct Stack *s2) {
    if (isEmpty(s2)) {
        while (!isEmpty(s1)) {
            push(s2, pop(s1));
        }
    }
    return pop(s2);
}

void display(struct Stack *s1, struct Stack *s2) {
    for (int i = s2->top; i >= 0; i--) {
        printf("%d\n ", s2->items[i]);
    }
    for (int i = s1->top; i >= 0; i--) {
        printf("%d ", s1->items[i]);
    }
    
}



int main() {
    struct Stack s1, s2;
    initStack(&s1);
    initStack(&s2);
    int choice, value;
    do {
        printf("enter ur choice\n1.add to queue\n2.remove from queue\n3.display\n4.exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("enter the element to be added to queue\n");
                scanf("%d", &value);
                enqueue(&s1, &s2, value);
                break;
            case 2:
                printf("%d\n", dequeue(&s1, &s2));
                break;
            case 3:
                display(&s1, &s2);
                break;
            case 4:
                exit(0);
            default:
                printf("invalid\n");
        }
    } while (1);
    return 0;
}
