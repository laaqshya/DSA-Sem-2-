#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

void init() {
    for(int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    int start = index;

    while(hashTable[index] != -1) {
        index = (index + 1) % SIZE;

        if(index == start) {
            printf("Hash Table is Full\n");
            return;
        }
    }

    hashTable[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}

void search(int key) {
    int index = hashFunction(key);
    int start = index;

    while(hashTable[index] != -1) {
        if(hashTable[index] == key) {
            printf("Key found at index %d\n", index);
            return;
        }

        index = (index + 1) % SIZE;

        if(index == start)
            break;
    }

    printf("Key not found\n");
}

void display() {
    printf("\nHash Table:\n");

    for(int i = 0; i < SIZE; i++) {
        printf("%d --> ", i);

        if(hashTable[i] == -1)
            printf("EMPTY\n");
        else
            printf("%d\n", hashTable[i]);
    }
}

int main() {
    int choice, key;

    init();

    while(1) {
        printf("\n--- Linear Probing ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}
