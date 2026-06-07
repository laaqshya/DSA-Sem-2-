#include <stdio.h>
#include <stdlib.h>

#define MAX_LOAD_FACTOR 0.5

int *hashTable;
int SIZE = 10;
int count = 0;

void initialize() {
    hashTable = (int *)malloc(SIZE * sizeof(int));

    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

int hashFunction(int key) {
    return key % SIZE;
}

float loadFactor() {
    return (float)count / SIZE;
}

void insertValue(int key) {
    int index = hashFunction(key);
    int newIndex;

    for (int i = 0; i < SIZE; i++) {
        newIndex = (index + i * i) % SIZE;

        if (hashTable[newIndex] == -1) {
            hashTable[newIndex] = key;
            count++;
            return;
        }
    }

    printf("Could not insert %d\n", key);
}

void rehash() {
    int oldSize = SIZE;
    int *oldTable = hashTable;

    SIZE = SIZE * 2;

    hashTable = (int *)malloc(SIZE * sizeof(int));

    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    count = 0;

    for (int i = 0; i < oldSize; i++) {
        if (oldTable[i] != -1)
            insertValue(oldTable[i]);
    }

    free(oldTable);

    printf("Table size doubled to %d and rehashed.\n", SIZE);
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

        printf("Current load factor = %.2f\n", loadFactor());
    }
}

void search() {
    int key, index, newIndex;

    printf("Enter value to search: ");
    scanf("%d", &key);

    index = hashFunction(key);

    for (int i = 0; i < SIZE; i++) {
        newIndex = (index + i * i) % SIZE;

        if (hashTable[newIndex] == key) {
            printf("Value found at index %d\n", newIndex);
            return;
        }

        if (hashTable[newIndex] == -1)
            break;
    }

    printf("Value not found.\n");
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

int main() {
    int choice;

    initialize();

    while (1) {
        printf("\n--- Quadratic Probing Menu ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Load Factor\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: search(); break;
            case 3: display(); break;
            case 4: printf("Current load factor = %.2f\n", loadFactor()); break;
            case 5: free(hashTable); exit(0);
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}
