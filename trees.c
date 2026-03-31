//code to implement trees
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct node{
    int data;
    struct node *prev,*link;
}*root=NULL,*last=NULL,*nn,*t,*t1,*t2=NULL;

void create();
void display(struct node*);
int main(){
    char c='y';
    int choice;
    while(c=='y'){
        printf("select:\n 1.create\n2.display\n");
        printf("enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("creation:\n");
                   create();
                   break;
            case 2:printf("traversal:\n");
                   display(root);
                   break;
        }
        printf("do you want to continue (y/n)?:");
        scanf(" %c",&c);
    }
    return 0;
}
void create(){
    char c;
    nn=(struct node*)malloc(sizeof(struct node));
    printf("enter data:");
    scanf("%d",&nn->data);
    nn->prev=NULL;
    nn->link=NULL;
    if(root==NULL)
    t=t1=t2=root=nn;
    else{
    printf("do you want a left child or right child");
    scanf(" %c",&c);
    if(c=='l'||c=='L'){
        t1->prev=nn;
        t1=nn;
    }
    if(c=='r'||c=='R'){
        t2->link=nn;
        t2=nn;
    }
    }
    display(t);
    
}
void display(struct node *t){
    if(t==NULL)
    return;
    printf("node:%d ",t->data);
    if(t->prev!=NULL)
    printf("left:%d",t->prev->data);
    else
    printf("no left child");

    if(t->link!=NULL)
    printf("right child:%d",t->link->data);
    else
    printf("no right child");

    printf("\n");
    display(t->prev);
    display(t->link);

}
