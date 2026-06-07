Circular Queue
#include <stdio.h>
#include<stdlib.h>
#define max 5
int cq[max], r=-1,f=0;
void insertcq(int ele)
{
    if((f==0 && r==max-1)||(f==r+1 && f!=0 && r!=-1))
        printf("Queue is full");
    else
        {
            r=(r+1)%max;
            cq[r]=ele;
        }
}

int deletecq(void)
{
    int ele;
    if(f==0 && r==-1)
        return -1;
    else
        if (f==r)
        {
            ele=cq[f];
            f=0,r=-1;
            return ele;
        }
        else
        {
            ele=cq[f];
            f=(f+1)%max;
            return ele;
        }
}

int isfull()
{
    if((f==0 && r==max-1)||(f==r+1 && f!=0 && r!=-1))
        return 1;
    else
        return 0;
}

int isempty ()
{
    if(f==0 && r==-1)
        return 1;
    else
        return 0;
}

void traverse()
{
    int i;
    if(isempty())
        printf("Queue is empty\n");
    else
    {
        printf("Content of queue is: ");
        for(i=f;i<=r;i++)
            printf("%d ",cq[i]);
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
                   insertcq(ele);
                   break;
            case 2:ele=deletecq();
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
