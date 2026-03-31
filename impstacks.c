//implementation of stacks code
#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push();
void pop();
void peek();
void display();

int main()
{
    int choice;

    do
    {
        printf("\n1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {

            case 1:
                printf("perform insertion:\n");
                push();
                break;

            case 2:
                printf("perform deletion:\n");
                pop();
                break;

            case 3:
                printf("top element is:");
                peek();
                break;

            case 4:
                display();
                break;

            default:
                printf("Invalid choice\n");
        }

    }while(choice!=5);
}


/* PUSH FUNCTION
   Inserts an element at the top of the stack */
void push()
{
    int x;

    if(top==MAX-1)
        printf("Stack Overflow\n");

    else
    {
        printf("Enter element: ");
        scanf("%d",&x);

        top++;
        stack[top]=x;
    }
}
