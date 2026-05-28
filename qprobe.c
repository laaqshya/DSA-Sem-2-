#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define EMPTY -1
#define DELETED -2

int hashTable[SIZE];

void initialize() {
    for(int i = 0; i < SIZE; i++) {
        hashTable[i] = EMPTY;
    }
}

int hashFunction(int key) {
    return key % SIZE;
}

void insert() {
    int n, key, index, newIndex;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(int j = 0; j < n; j++) {
        printf("Enter value %d: ", j + 1);
        scanf("%d", &key);

        index = hashFunction(key);

        for(int i = 0; i < SIZE; i++) {
            newIndex = (index + i * i) % SIZE;

            if(hashTable[newIndex] == EMPTY || hashTable[newIndex] == DELETED) {
                hashTable[newIndex] = key;
                printf("%d inserted at index %d\n", key, newIndex);
                break;
            }

            if(i == SIZE - 1) {
                printf("Hash table is full. Cannot insert %d\n", key);
            }
        }
    }
}

void search() {
    int key, index, newIndex;

    printf("Enter value to search: ");
    scanf("%d", &key);

    index = hashFunction(key);

    for(int i = 0; i < SIZE; i++) {
        newIndex = (index + i * i) % SIZE;

        if(hashTable[newIndex] == key) {
            printf("Value found at index %d\n", newIndex);
            return;
        }

        if(hashTable[newIndex] == EMPTY) {
            break;
        }
    }

    printf("Value not found.\n");
}

void deleteKey() {
    int key, index, newIndex;

    printf("Enter value to delete: ");
    scanf("%d", &key);

    index = hashFunction(key);

    for(int i = 0; i < SIZE; i++) {
        newIndex = (index + i * i) % SIZE;

        if(hashTable[newIndex] == key) {
            hashTable[newIndex] = DELETED;
            printf("Value deleted successfully.\n");
            return;
        }

        if(hashTable[newIndex] == EMPTY) {
            break;
        }
    }

    printf("Value not found.\n");
}

void display() {
    printf("\nHash Table:\n");

    for(int i = 0; i < SIZE; i++) {
        if(hashTable[i] == EMPTY)
            printf("Index %d : EMPTY\n", i);
        else if(hashTable[i] == DELETED)
            printf("Index %d : DELETED\n", i);
        else
            printf("Index %d : %d\n", i, hashTable[i]);
    }
}

int main() {
    int choice;

    initialize();

    while(1) {
        printf("\n--- Quadratic Probing Menu ---\n");
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
                deleteKey();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
