#include <stdio.h>
#include<stdlib.h>
#define max 3
int q[max], r=-1,f=0;
void insertq(int ele)
{
    if(r==max-1)
        printf("Queue is full");
    else
        q[++r]=ele;
}

int deleteq(void)
{
    int ele;
    if(f>r)
        return -1;
    else
        if (f==r)
        {
            ele=q[f];
            f=0,r=-1;
            return ele;
        }
        else
            return(ele=q[f++]);
}

int isfull()
{
    if(r==max-1)
        return 1;
    else
        return 0;
}

int isempty ()
{
    if(f>r)
        return 1;
    else
        return 0;
}

void traverse()
{
    int i;
    if(isempty())
        printf("Queue is empty");
    else
    {
        printf("Content of queue is: ");
        for(i=0;i<=r;i++)
            printf("%d ",q[i]);
        printf("\n");
    }
}

void main()
{
    int choice, ele;
    char c='y';
    while(c=='y')
    {
        printf("\n1:Insert 2:Delete 3:isFull 4:isEmpty 5:Traverse\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter element to insert: ");
                   scanf("%d",&ele);
                   insertq(ele);
                   break;
            case 2:ele=deleteq();
                   if(ele==-1)
                    printf("Queue is empty\n");
                   else
                    printf("Deleted element is %d\n",ele);
                   break;
            case 3:if(isfull())
                    printf("Queue is full\n");
                   else
                    printf("Queue is not full\n");
                   break;
            case 4:if(isempty())
                    printf("Queue is empty\n");
                   else
                    printf("Queue is not empty\n");
                   break;
            case 5:traverse();
                   break;
            default:printf("Wrong choice\n");
        }
        getchar();
        printf("Continue y/n: ");
        c=getchar();
    }
}
