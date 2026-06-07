#include <stdio.h>
#include <stdlib.h>

#define MAX_LOAD_FACTOR 0.7

int *hashTable;
int SIZE = 10;
int count = 0;

void initialize() {
    hashTable = (int *)malloc(SIZE * sizeof(int));

    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }
}

int hashFunction(int key) {
    return key % SIZE;
}

float loadFactor() {
    return (float)count / SIZE;
}

void insertValue(int key) {
    int index = hashFunction(key);

    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
    }

    hashTable[index] = key;
    count++;
}

void rehash() {
    int oldSize = SIZE;
    int *oldTable = hashTable;

    SIZE = SIZE * 2;

    hashTable = (int *)malloc(SIZE * sizeof(int));

    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }

    count = 0;

    for (int i = 0; i < oldSize; i++) {
        if (oldTable[i] != -1) {
            insertValue(oldTable[i]);
        }
    }

    free(oldTable);

    printf("Hash table resized to %d and rehashed successfully.\n", SIZE);
}

void insert() {
    int n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &key);

        if ((float)(count + 1) / SIZE > MAX_LOAD_FACTOR) {
            rehash();
        }

        insertValue(key);

        printf("Inserted %d\n", key);
        printf("Current load factor = %.2f\n", loadFactor());
    }
}

void display() {
    printf("\nHash Table:\n");

    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == -1)
            printf("Index %d : EMPTY\n", i);
        else
            printf("Index %d : %d\n", i, hashTable[i]);
    }

    printf("Table size = %d\n", SIZE);
    printf("Number of elements = %d\n", count);
    printf("Load factor = %.2f\n", loadFactor());
}

void search() {
    int key, index, startIndex;

    printf("Enter value to search: ");
    scanf("%d", &key);

    index = hashFunction(key);
    startIndex = index;

    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            printf("Value found at index %d\n", index);
            return;
        }

        index = (index + 1) % SIZE;

        if (index == startIndex)
            break;
    }

    printf("Value not found.\n");
}

void deleteKey() {
    int key, index, startIndex;

    printf("Enter value to delete: ");
    scanf("%d", &key);

    index = hashFunction(key);
    startIndex = index;

    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            hashTable[index] = -1;
            count--;

            printf("Value deleted successfully.\n");
            printf("Current load factor = %.2f\n", loadFactor());
            return;
        }

        index = (index + 1) % SIZE;

        if (index == startIndex)
            break;
    }

    printf("Value not found.\n");
}

int main() {
    int choice;

    initialize();

    while (1) {
        printf("\n--- Linear Probing Menu ---\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("5. Load Factor\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
                printf("Current load factor = %.2f\n", loadFactor());
                break;

            case 6:
                free(hashTable);
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
