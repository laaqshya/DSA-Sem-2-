#include <stdio.h>

#define MAX 5

int dq[MAX];
int front = -1, rear = -1;

void insertFront(int x)
{
    if (front == 0)
    {
        printf("Insertion at front not possible\n");
        return;
    }

    if (front == -1)
    {
        front = rear = 0;
    }
    else
    {
        front--;
    }

    dq[front] = x;
}

void insertRear(int x)
{
    if (rear == MAX - 1)
    {
        printf("Insertion at rear not possible\n");
        return;
    }

    if (front == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }

    dq[rear] = x;
}

int deleteFront()
{
    int x;

    if (front == -1)
        return -1;

    x = dq[front];

    if (front == rear)
        front = rear = -1;
    else
        front++;

    return x;
}

int deleteRear()
{
    int x;

    if (front == -1)
        return -1;

    x = dq[rear];

    if (front == rear)
        front = rear = -1;
    else
        rear--;

    return x;
}

int isEmpty()
{
    return (front == -1);
}

int isFull()
{
    return (front == 0 && rear == MAX - 1);
}

void display()
{
    if (isEmpty())
    {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");

    for (int i = front; i <= rear; i++)
        printf("%d ", dq[i]);

    printf("\n");
}

int main()
{
    int ch, x;

    while (1)
    {
        printf("\n1.Insert Front");
        printf("\n2.Insert Rear");
        printf("\n3.Delete Front");
        printf("\n4.Delete Rear");
        printf("\n5.Display");
        printf("\n6.Exit");
        printf("\nEnter choice: ");

        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                insertFront(x);
                break;

            case 2:
                printf("Enter element: ");
                scanf("%d", &x);
                insertRear(x);
                break;

            case 3:
                x = deleteFront();
                if (x == -1)
                    printf("Deque is empty\n");
                else
                    printf("Deleted: %d\n", x);
                break;

            case 4:
                x = deleteRear();
                if (x == -1)
                    printf("Deque is empty\n");
                else
                    printf("Deleted: %d\n", x);
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
