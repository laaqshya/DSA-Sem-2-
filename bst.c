#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev,*link;
}*root=NULL,*nn,*t;

void create();
void inorder();
void preorder();
void postorder();
void inorderRec(struct node*);
void preorderRec(struct node*);
void postorderRec(struct node*);
int height(struct node*);
int countnl(struct node*);
int countl(struct node*);
void display1(struct node*);

int main(){
    char c='y';
    int choice;

    while(c=='y'){
        printf("\nSelect:\n1.Create\n2.Inorder\n3.Preorder\n4.Postorder\n5.Display Nodes\n6.postorderRec\n7.inorderRec\n8.preorder\n9.count non-leaf\n10.count leaf\n11.height");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                create();
                break;
            case 2:
                inorder();
                break;
            case 3:
                preorder();
                break;
            case 4:
                postorder();
                break;
            case 5:
                display1(root);
                break;
            case 6:
                 printf("Postorder using reccursion:");
                 postorderRec(t);
                 break;
            case 7:
                printf("inorder using reccursion:");
                inorderRec(t);
                break;
            case 8:
                printf("preorder using reccursion:");
                preorderRec(t);
                break;
            case 9:
                printf("height of the tree:%d\n",height(t));
                break;
            case 10:
                printf("non-leaf nodes:%d\n",countnl(t));
                break;
            case 11:
                printf("leaf nodes:%d\n",countl(t));
                break;

        }//end of switch

        printf("\nDo you want to continue (y/n)? ");
        scanf(" %c",&c);
    }//end of while
    return 0;
}//end of main
//create a function
void create(){
    int n,i;
    printf("enter no. of nodes:");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
    nn=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&nn->data);
    nn->prev=NULL;
    nn->link=NULL;
    if(root==NULL)
    root=nn;
    else{
    t=root;
    while(t!=NULL){
        if(nn->data < t->data){
            if(t->prev==NULL){
                t->prev=nn;
                break;
            }
            t=t->prev;
        }
        else{
            if(t->link==NULL){
                t->link=nn;
                break;
            }
            t=t->link;
        }//end of else
   }//end of while
  }//end of outer else
 }//end of for
}//end of function

//inorder without reccursion
void inorder(){
    struct node *stack[50];
    int top=-1;
    t=root;
    printf("Inorder: ");
    while(t!=NULL || top!=-1){
        while(t!=NULL){
            stack[++top]=t;
            t=t->prev;
        }//end of inner while
        t=stack[top--];
        printf("%d ",t->data);
        t=t->link;
    }//end of outer while
}//end of function
//preorder without reccursion
void preorder(){
    struct node *stack[50];
    int top=-1;
    t=root;
    printf("Preorder: ");
    while(t!=NULL || top!=-1){
        while(t!=NULL){
            printf("%d ",t->data);
            top=top+1;
            stack[top]=t;
            t=t->prev;
        }//end of inner while
        t=stack[top];
        top=top-1;
        t=t->link;
    }//end of outer while
}
void postorder(){
    struct node *stack[50];
    struct node *last=NULL;
    int top=-1;
    t=root;
    printf("Postorder: ");
    while(t!=NULL || top!=-1){
        if(t!=NULL){
            top=top+1;
            stack[top]=t;
            t=t->prev;
        }//end of if
        else{
            struct node *p=stack[top];

            if(p->link!=NULL && last!=p->link)
                t=p->link;
            else{
                printf("%d ",p->data);
                last=p;
                top--;
            }//end of inner else
        }//end of outer else
    }//end of while
}//end of func
//function to display inorder reccursion
void inorderRec(struct node *t){
    t=root;
    if(t!=NULL){
        inorderRec(t->prev);
        printf("%d ",t->data);
        inorderRec(t->link);
    }
}

void preorderRec(struct node *t){
    t=root;
    if(t!=NULL){
        printf("%d ",t->data);
        preorderRec(t->prev);
        preorderRec(t->link);
    }
}
//function to display postorder using reccursion
void postorderRec(struct node *t){
    t=root;
    if(t!=NULL){
        postorderRec(t->prev);
        postorderRec(t->link);
        printf("%d ",t->data);
    }
}
//function to know the height of the tree
int height(struct node *t){
    int lh,rh;
    t=root;
    if(t==NULL)
        return 0;
    lh=height(t->prev);
    rh=height(t->link);
    if(lh>rh)
        return lh+1;
    else
        return rh+1;
}
//function to count the non leaf nodes
int countnl(struct node *t){
    t=root;
    if(t==NULL || (t->prev==NULL && t->link==NULL))
        return 0;
    return 1 + countnl(t->prev) + countnl(t->link);
}
//function to count the leaf node
int countl(struct node *t){
    t=root;
    if(t==NULL)
        return 0;
    if(t->prev==NULL && t->link==NULL)
        return 1;
    return countl(t->prev) + countl(t->link);
}
//function to display the nodes
void display1(struct node *t){
    t=root;
    if(t==NULL)
        return;
    printf("Node:%d ",t->data);
    if(t->prev!=NULL)
        printf("Left:%d ",t->prev->data);
    else
        printf("Left:NULL ");
    if(t->link!=NULL)
        printf("Right:%d",t->link->data);
    else
        printf("Right:NULL");
    printf("\n");
    display1(t->prev);
    display1(t->link);
}
