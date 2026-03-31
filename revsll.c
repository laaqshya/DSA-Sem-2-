//reverse a sll
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct node{
    int data;
    struct node *link;
}*first=NULL,*last=NULL,*nn,*t=NULL;

void create();
void reverse();
void display();

int main()
{
    char c='y';
    int choice;

    while(c=='y' || c=='Y')
    {
        printf("\nSelect:\n");
        printf("1.Create\n");
        printf("2.Reverse\n");
        printf("3.Display\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Creation:\n");
                create();
                break;

            case 2:
                printf("Reversing the list:\n");
                reverse();
                break;

            case 3:
                printf("Displaying the list:\n");
                display();
                break;

            default:
                printf("Invalid choice\n");
        }

        printf("\nDo you want to continue (y/n): ");
        scanf(" %c",&c);
    }

    return 0;
}
// to create a linked list
void create(){
    int n,i;
    first=NULL;
    last=NULL;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        nn=(struct node*)malloc(sizeof(struct node));
        printf("Enter value: ");
        scanf("%d",&nn->data);
        nn->link=NULL;
        if(first==NULL){
            first=nn;
            last=nn;
        }
        else{
            last->link=nn;
            last=nn;
        }
    }
    display(); // check list
}
// to reverse a linked list
void reverse(){
    struct node *t,*t1,*t2;
    if(first==NULL)
        printf("List is empty\n");
    t=first;
    t1=NULL;
    while(t!=NULL){
        t2=t->link;
        t->link=t1;
        t1=t;
        t=t2;
    }
    first=t1;
    printf("List reversed successfully\n");
}
// to display the linked list
void display(){
    struct node *t;
    if(first==NULL)
        printf("List is empty\n");
        
    t=first;
    while(t!=NULL){
        printf("%d ",t->data);
        t=t->link;
    }
    printf("\n");
}
