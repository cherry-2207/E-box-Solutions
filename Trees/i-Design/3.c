#include <stdio.h>
#include <stdlib.h>

struct tree {
    int data;
    struct tree *right, *left;
};

struct queue {
    int front, rear;
    int size;
    struct tree **array;
};

struct tree* newNode(int data) {
    struct tree *temp = (struct tree *)malloc(sizeof(struct tree));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct queue* createQueue(int size) {
    struct queue *queue = (struct queue *)malloc(sizeof(struct queue));
    queue->front = queue->rear = -1;
    queue->size = size;
    queue->array = (struct tree **)malloc(queue->size * sizeof(struct tree *));
    return queue;
}

void enqueue(struct tree *root, struct queue *queue) {
    if ((queue->rear + 1) % queue->size == queue->front)
        return;
    queue->rear = (queue->rear + 1) % queue->size;
    queue->array[queue->rear] = root;
    if (queue->front == -1)
        queue->front = queue->rear;
}

struct tree* dequeue(struct queue *queue) {
    if (queue->front == -1)
        return NULL;
    struct tree *temp = queue->array[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front = (queue->front + 1) % queue->size;
    return temp;
}

void insert(struct tree **root, int data, struct queue *queue) {
    struct tree *temp = newNode(data);
    if (!*root)
        *root = temp;
    else {
        struct tree *front = queue->array[queue->front];
        if (!front->left)
            front->left = temp;
        else if (!front->right)
            front->right = temp;
        if (front->left && front->right)
            dequeue(queue);
    }
    enqueue(temp, queue);
}

void levelOrder(struct tree* root) {
    if (!root)
        return;
    struct queue *queue = createQueue(1000);
    enqueue(root, queue);
    while (queue->front != -1) {
        struct tree *temp = dequeue(queue);
        printf("%d ", temp->data);
        if (temp->left)
            enqueue(temp->left, queue);
        if (temp->right)
            enqueue(temp->right, queue);
    }
    printf("\n");
}

int isBSTUtil(struct tree* node, int min, int max) {
    if (node == NULL)
        return 1;
    if (node->data < min || node->data > max)
        return 0;
    return isBSTUtil(node->left, min, node->data - 1) && isBSTUtil(node->right, node->data + 1, max);
}

int isBST(struct tree* node) {
    return isBSTUtil(node, 0, 1000);
}

int main() {
    int n;
    printf("Enter the number of elements in the tree\n");
    scanf("%d", &n);
    struct tree *root = NULL;
    struct queue *q = createQueue(1000);
    printf("Enter the elements in the tree\n");
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insert(&root, data, q);
    }
    printf("The elements in the tree in level order are ");
    levelOrder(root);
    if (isBST(root))
        printf("The tree is a BST\n");
    else
        printf("The tree is not a BST\n");
    return 0;
}
