#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct Node *next;
};

void insert (struct node *head, int val) {
    struct node *temp = head;

    while (temp->next != '\0') {
        temp = temp->next;
    }

    struct node *new = malloc(sizeof(struct node));
    new->val = val;
    new->next = '\0';

    temp->next = new;
}

void delete (struct node *head, int val) {
    struct node *temp = head;
    struct node *prev = temp;

    while (temp != '\0') {
        if (temp->val == val) {
            prev->next = temp->next;
            free(temp);
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Node not found\n");
}

void search (struct node *head, int val) {
    struct node *temp = head;
    int position = 1;

    while (temp != '\0') {
        if (temp->val == val) {
            printf("Node found at position: %d\n", position);
            return;
        }
        position++;
        temp = temp->next;
    }
    printf("Node not found\n");
}

void display (struct node *head) {
    struct node *temp = head;

    while (temp != '\0') {
        printf("%d ", temp->val);
        temp = temp->next;
    }
}

void main () {
    struct node *head = malloc(sizeof(struct node));
    head->val = 0;
    head->next = '\0';

    while (1) {
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Search a node\n");
        printf("4. Display the list\n");
        printf("5. Exit\n\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        int val;
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert(head, val);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                delete(head, val);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &val);
                search(head, val);
                break;
            case 4:
                display(head);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice");
        }

        printf("\n\n");
    }
}
