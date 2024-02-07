#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *next;
};
typedef struct node NodeType;
NodeType *first, *last;

void insertAtBeg(int);
void insertAtPosition(int);
void insertAtEnd(int);
void deleteAtBeg();
void deleteAtEnd();
void deleteAtPosition();

void display();

void main() {
    int choice;
    int item;

    first = last = NULL;

    do {
        printf("\nMenu driven Program:\n");
        printf("1. Insert First\n2. Insert at Position\n3. Insert At End\n4. Delete First\n5. Delete Last Node\n6. Delete nth node\n7. Display Items\n8. exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter Item to be inserted: ");
                scanf("%d", &item);
                insertAtBeg(item);
                break;

            case 2:
                printf("Enter Item to be inserted: ");
                scanf("%d", &item);
                insertAtPosition(item);
                break;

            case 3:
                printf("Enter Item to be inserted: ");
                scanf("%d", &item);
                insertAtEnd(item);
                break;

            case 4:
                deleteAtBeg();
                break;

            case 5:
                deleteAtEnd();
                break;

            case 6:
                deleteAtPosition();
                break;

           
            case 7:
                display();
                break;

            case 8:
                exit(0);
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (1);
}

void insertAtBeg(int item) {
    NodeType *temp;
    temp = (NodeType *)malloc(sizeof(NodeType));
    temp->info = item;
    temp->next = NULL;

    if (first == NULL) {
        first = last = temp;
    } else {
        temp->next = first;
        first = temp;
    }

    printf("Item %d inserted at the beginning.\n", item);
}

void insertAtPosition(int item) {
    NodeType *temp, *prev, *curr;
    int pos, i = 1;
    
    printf("Enter the position to insert: ");
    scanf("%d", &pos);

    temp = (NodeType *)malloc(sizeof(NodeType));
    temp->info = item;
    temp->next = NULL;

    if (first == NULL && pos > 1) {
        printf("Invalid position. List is empty.\n");
        free(temp);
        return;
    }

    if (pos == 1) {
        temp->next = first;
        first = temp;
        return;
    }

    curr = first;
    while (i < pos && curr != NULL) {
        prev = curr;
        curr = curr->next;
        i++;
    }

    if (curr == NULL && i < pos) {
        printf("Invalid position.\n");
        free(temp);
        return;
    }

    prev->next = temp;
    temp->next = curr;

    printf("Item %d inserted at position %d.\n", item, pos);
}

void insertAtEnd(int item) {
    NodeType *temp;
    temp = (NodeType *)malloc(sizeof(NodeType));
    temp->info = item;
    temp->next = NULL;

    if (first == NULL) {
        first = last = temp;
    } else {
        last->next = temp;
        last = temp;
    }

    printf("Item %d inserted at the end.\n", item);
}

void deleteAtBeg() {
    if (first == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    NodeType *temp;
    temp = first;
    first = first->next;
    free(temp);

    printf("Item deleted from the beginning.\n");
}

void deleteAtEnd() {
    if (first == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    NodeType *temp, *prev;
    temp = first;
    prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        free(temp);
        first = last = NULL;
    } else {
        free(temp);
        prev->next = NULL;
        last = prev;
    }

    printf("Item deleted from the end.\n");
}

void deleteAtPosition() {
    if (first == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    int pos;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);

    if (pos == 1) {
        NodeType *temp;
        temp = first;
        first = first->next;
        free(temp);
        printf("Item deleted from position 1.\n");
        return;
    }

    NodeType *temp, *prev, *curr;
    int i = 1;
    curr = first;

    while (i < pos && curr != NULL) {
        prev = curr;
        curr = curr->next;
        i++;
    }

    if (curr == NULL && i < pos) {
        printf("Invalid position.\n");
        return;
    }

    prev->next = curr->next;
    free(curr);

    printf("Item deleted from position %d.\n", pos);
}





void display() {
    if (first == NULL) {
        printf("List is empty. Nothing to display.\n");
        return;
    }

    NodeType *temp;
    temp = first;

    printf("Items in the list: ");
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}
