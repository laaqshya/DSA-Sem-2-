#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

// Structure
struct node {
    int key;
    struct node* next;
};

struct node* hashTable[SIZE];

// Hash function
int hashFunction(int key) {
    return key % SIZE;
}

// Initialize table
void init() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }
}

// Insert
void insert(int key) {
    int index = hashFunction(key);

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->key = key;
    newNode->next = NULL;

    // Insert at beginning
    newNode->next = hashTable[index];
    hashTable[index] = newNode;

    printf("Inserted %d at index %d\n", key, index);
}

// Search
void search(int key) {
    int index = hashFunction(key);
    struct node* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->key == key) {
            printf("Key %d found at index %d\n", key, index);
            return;
        }
        temp = temp->next;
    }

    printf("Key %d not found\n", key);
}

// Delete
void deleteKey(int key) {
    int index = hashFunction(key);
    struct node* temp = hashTable[index];
    struct node* prev = NULL;

    while (temp != NULL) {
        if (temp->key == key) {
            if (prev == NULL) {
                hashTable[index] = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Key %d deleted\n", key);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Key %d not found for deletion\n", key);
}

// Display
void display() {
    for (int i = 0; i < SIZE; i++) {
        printf("Index %d: ", i);
        struct node* temp = hashTable[i];

        while (temp != NULL) {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Main (Menu)
int main() {
    int choice, key;

    init();

    while (1) {
        printf("\n--- Hash Table Menu ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;

            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteKey(key);
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}