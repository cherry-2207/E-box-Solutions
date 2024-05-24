#include <stdio.h>

#define MAX_SIZE 5

struct queue {
    int contents[MAX_SIZE];
    int front;
    int count;
};

void printMenu() {
    printf("Choice 1 : Enter element into Queue\n");
    printf("Choice 2 : Delete element from Queue\n");
    printf("Choice 3 : Display\n");
    printf("Any other choice : Exit\n");
}

void initQueue(struct queue *q) {
    q->front = 0;
    q->count = 0;
}

void enQueue(struct queue *q, int element) {
    if (q->count == MAX_SIZE) {
        printf("Queue is full\n");
        return;
    }
    int rear = (q->front + q->count) % MAX_SIZE;
    q->contents[rear] = element;
    q->count++;
}

int deQueue(struct queue *q) {
    if (q->count == 0) {
        printf("Queue is empty\n");
        return -1000;
    }
    int element = q->contents[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->count--;
    return element;
}

void display(struct queue q) {
    if (q.count == 0) {
        printf(" {}\n");
        return;
    }
    for (int i = 0; i < q.count; i++) {
        int index = (q.front + i) % MAX_SIZE;
        printf(" %d", q.contents[index]);
    }
    printf("\n");
}

int main() {
    struct queue p;
    int data, ch, data1;
    initQueue(&p);
    do {
        printMenu();
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the element to be inserted/entered\n");
                scanf("%d", &data);
                enQueue(&p, data);
                break;
            case 2:
                data1 = deQueue(&p);
                if (data1 != -1000)
                    printf("The deleted element is %d\n", data1);
                break;
            case 3:
                printf("The contents of the queue are");
                display(p);
                break;
            default:
                return 0;
        }
    } while (1);
    return 0;
}
