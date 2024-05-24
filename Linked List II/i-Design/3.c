#include <stdio.h>
#include <stdlib.h>

// Define a structure for a keyboard key
struct keyboard {
    int key;
    struct keyboard *link;
};

// Function to insert a key in ascending order while assembling the keyboard
void insert(struct keyboard **head_ref, int new_key) {
    struct keyboard *new_node = (struct keyboard *)malloc(sizeof(struct keyboard));
    new_node->key = new_key;
    new_node->link = NULL;

    // If the list is empty or the new key is less than the head key
    if (*head_ref == NULL || new_key < (*head_ref)->key) {
        new_node->link = *head_ref;
        *head_ref = new_node;
    } 
    else {
        struct keyboard *current = *head_ref;
        // Find the appropriate position to insert the new key
        while (current->link != NULL && current->link->key < new_key) {
            current = current->link;
        }
        new_node->link = current->link;
        current->link = new_node;
    }
}

// Function to display the assembled keyboard
void display(struct keyboard *head) {
    if (head == NULL) {
        printf("Keyboard has no disassembled key\n");
    } else {
        printf("Keyboard:\n");
        while (head != NULL) {
            printf("%d ", head->key);
            head = head->link;
        }
        printf("\n");
    }
}

int main() {
    struct keyboard *head = NULL;
    int choice, key;
    do {
        printf("1.Enter a disassembled key\n");
        printf("2.View keyboard\n");
        printf("3.Exit\n");
        printf("Enter your choice\n ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the key number\n ");
                scanf("%d", &key);
                // Input validation to ensure the key is in the range [0, 9]
                while (key < 0 || key > 9) {
                    printf("Enter the key number \n ");
                    scanf("%d", &key);
                }
                insert(&head, key);
                break;
            case 2:
                display(head);
                break;
            case 3:
                printf("Exit\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 3);

    return 0;
}
