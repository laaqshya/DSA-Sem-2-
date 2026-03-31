//to merge two singly linked lists
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
}*first1=NULL,*last1=NULL,*first2=NULL,*last2=NULL,*first3=NULL,*last3=NULL;
void create1();
void create2();
void merge(struct node *first1, struct node *first2);
void display(struct node *first);
int main(){
    char c='y';
    int choice;
    while(c=='y' || c=='Y'){
        printf("\nSelect:\n");
        printf("1.Create List1\n");
        printf("2.Create List2\n");
        printf("3.Merge Lists\n");
        printf("4.Display Merged List\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("Creation of List1:\n");
            create1();
            break;
        case 2:
            printf("Creation of List2:\n");
            create2();
            break;
        case 3:
            printf("Merging lists:\n");
            merge(first1,first2);
            break;
        case 4:
            printf("Merged list:\n");
            display(first3);
            break;
        default:
            printf("Invalid choice\n");
        }
        printf("Do you want to continue (y/n): ");
        scanf(" %c",&c);
    }
    return 0;
}
// create first list
void create1(){
    int n,i;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        struct node *nn=(struct node*)malloc(sizeof(struct node));
        printf("Enter value: ");
        scanf("%d",&nn->data);
        nn->link=NULL;
        if(first1==NULL)
        first1=last1=nn;
        else{
            last1->link=nn;
            last1=nn;
        }
    }
    display(first1);
}
// create second list
void create2()
{
    int n,i;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        struct node *nn=(struct node*)malloc(sizeof(struct node));
        printf("Enter value: ");
        scanf("%d",&nn->data);
        nn->link=NULL;
        if(first2==NULL)
            first2=last2=nn;
        else{
            last2->link=nn;
            last2=nn;
        }
    }
    display(first2);
}
// merge two sorted lists
void merge(struct node *f1, struct node *f2){
    struct node *t1=f1;
    struct node *t2=f2;
    while(t1!=NULL && t2!=NULL){
        struct node *nn=(struct node*)malloc(sizeof(struct node));
        if(t1->data < t2->data){
            nn->data=t1->data;
            t1=t1->link;
        }
        else{
            nn->data=t2->data;
            t2=t2->link;
        }
        nn->link=NULL;
        if(first3==NULL)
            first3=last3=nn;
        else{
            last3->link=nn;
            last3=nn;
        }
    }
    while(t1!=NULL){
        struct node *nn=(struct node*)malloc(sizeof(struct node));
        nn->data=t1->data;
        nn->link=NULL;
        last3->link=nn;
        last3=nn;
        t1=t1->link;
    }
    while(t2!=NULL){
        struct node *nn=(struct node*)malloc(sizeof(struct node));
        nn->data=t2->data;
        nn->link=NULL;
        last3->link=nn;
        last3=nn;
        t2=t2->link;
    }
}
// display list
void display(struct node *first){
    struct node *t=first;
    if(t==NULL){
        printf("List empty\n");
        return;
    }
    while(t!=NULL) {
        printf("%d ",t->data);
        t=t->link;
    }
    printf("\n");
}
