#include <stdio.h>
#include <stdlib.h>

// Define the structure for each file
struct file {
    int number;
    struct file *link;
};

// Function to append a new file to the desktop
void append(struct file **head_ref, int new_data) {
    struct file *new_file = (struct file *)malloc(sizeof(struct file));
    struct file *last = *head_ref;

    // Assign data to the new file
    new_file->number = new_data;
    new_file->link = NULL;

    // If the linked list is empty, make the new file as the head
    if (*head_ref == NULL) {
        *head_ref = new_file;
        return;
    }

    // Otherwise, traverse till the last file
    while (last->link != NULL)
        last = last->link;

    // Change the next of the last file
    last->link = new_file;
}

// Function to display the files on the desktop
void display(struct file *head) {
    if (head == NULL) {
        printf("Desktop is Empty\n");
        return;
    }
    printf("Files are: ");
    while (head != NULL) {
        printf("%d ", head->number);
        head = head->link;
    }
    printf("\n");
}

// Function to arrange files in ascending order
void ascending(struct file *head) {
    struct file *current = head, *index = NULL;
    int temp;

    if (head == NULL)
        return;

    while (current != NULL) {
        // Traverse the rest of the linked list after current
        index = current->link;

        while (index != NULL) {
            if (current->number > index->number) {
                // Swap the data if current file's number is greater than index file's number
                temp = current->number;
                current->number = index->number;
                index->number = temp;
            }
            index = index->link;
        }
        current = current->link;
    }
}

int main() {
    struct file *desktop = NULL;
    int choice, file_num;

    do {
        printf("\n1.Enter a new file\n2.View desktop\n3.Arrange in order\n4.Exit\nEnter your choice\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the file\n");
                scanf("%d", &file_num);
                if (file_num < 1 || file_num > 100) {
                    printf("Oops!!! not in the range.\nEnter the file\n");
                    scanf("%d", &file_num);
                }
                append(&desktop, file_num);
                break;
            case 2:
                display(desktop);
                break;
            case 3:
                ascending(desktop);
                display(desktop);
                break;
            case 4:
                printf("Exit\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
