#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int hashTable[SIZE];

// Initialize hash table
void initialize() {
    for(int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }
}

// Hash function
int hashFunction(int key) {
    return key % SIZE;
}

// Insert function
void insert() {
    int n, key, index, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {

        printf("Enter value %d: ", i + 1);
        scanf("%d", &key);

        index = hashFunction(key);

        // Linear probing
        while(hashTable[index] != -1) {
            index = (index + 1) % SIZE;
        }

        hashTable[index] = key;
    }

    printf("Elements inserted successfully.\n");
}

// Display function
void display() {

    printf("\nHash Table:\n");

    for(int i = 0; i < SIZE; i++) {

        if(hashTable[i] == -1)
            printf("Index %d : EMPTY\n", i);
        else
            printf("Index %d : %d\n", i, hashTable[i]);
    }
}

// Search function
void search() {

    int key, index, startIndex;

    printf("Enter value to search: ");
    scanf("%d", &key);

    index = hashFunction(key);
    startIndex = index;

    while(hashTable[index] != -1) {

        if(hashTable[index] == key) {
            printf("Value found at index %d\n", index);
            return;
        }

        index = (index + 1) % SIZE;

        if(index == startIndex)
            break;
    }

    printf("Value not found.\n");
}

// Delete function
void deleteKey() {

    int key, index, startIndex;

    printf("Enter value to delete: ");
    scanf("%d", &key);

    index = hashFunction(key);
    startIndex = index;

    while(hashTable[index] != -1) {

        if(hashTable[index] == key) {

            hashTable[index] = -1;

            printf("Value deleted successfully.\n");
            return;
        }

        index = (index + 1) % SIZE;

        if(index == startIndex)
            break;
    }

    printf("Value not found.\n");
}

// Main function
int main() {

    int choice;

    initialize();

    while(1) {

        printf("\n--- Linear Probing Menu ---\n");
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
