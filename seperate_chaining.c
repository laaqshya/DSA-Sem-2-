#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Structure for node
struct node {
    int data;
    struct node *next;
};

// Hash table
struct node *hashTable[SIZE];

// Hash function
int hashFunction(int key) {
    return key % SIZE;
}

// Insert function
void insert() {
    int n, key, index;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {

        printf("Enter value %d: ", i + 1);
        scanf("%d", &key);

        index = hashFunction(key);

        struct node *newNode;
        newNode = (struct node *)malloc(sizeof(struct node));

        newNode->data = key;
        newNode->next = NULL;

        // If bucket is empty
        if(hashTable[index] == NULL) {
            hashTable[index] = newNode;
        }
        else {
            struct node *temp;

            // Traverse using for loop
            for(temp = hashTable[index];
                temp->next != NULL;
                temp = temp->next);

            temp->next = newNode;
        }
    }

    printf("Elements inserted successfully.\n");
}

// Display function
void display() {
    int i;
    struct node *temp;

    for(i = 0; i < SIZE; i++) {

        printf("Index %d : ", i);

        temp = hashTable[i];

        while(temp != NULL) {
            printf(" -> %d", temp->data);
            temp = temp->next;
        }

        printf(" -> NULL\n");
    }
}

// Search function
void search() {
    int key, index, found = 0;

    printf("Enter value to search: ");
    scanf("%d", &key);

    index = hashFunction(key);

    struct node *temp = hashTable[index];

    while(temp != NULL) {

        if(temp->data == key) {
            found = 1;
            break;
        }

        temp = temp->next;
    }

    if(found)
        printf("Value found.\n");
    else
        printf("Value not found.\n");
}

// Delete function
void deleteNode() {
    int key, index;

    printf("Enter value to delete: ");
    scanf("%d", &key);

    index = hashFunction(key);

    struct node *temp = hashTable[index];
    struct node *prev = NULL;

    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Value not found.\n");
        return;
    }

    if(prev == NULL)
        hashTable[index] = temp->next;
    else
        prev->next = temp->next;

    free(temp);

    printf("Value deleted successfully.\n");
}

// Main function
int main() {

    int choice;

    while(1) {

        printf("\n--- Separate Chaining Menu ---\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                insert();
                break;

            case 2:
                display();
                break;

            case 3:
                search();
                break;

            case 4:
                deleteNode();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
