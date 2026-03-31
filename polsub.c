//code for polynomial subtraction
#include <stdio.h>
#include<stdlib.h>
struct node{
    int coeff;
    int exp;
    struct node*link;
}*first=NULL,*last=NULL,*nn,*t=NULL;    
void create();
void display();
void subtract(struct node*first1,struct node*first2);
int main(){
    char c='y';
    int choice,ele;
    while(c=='y'){
        printf("select:\n1.create\n2.display\n3.subtract\n");
        printf("enter choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("creation:\n");
                   create();
                   break;
            case 2:display();
                   break;
            case 3:subtract(first,first);
                   break;
        }//end of switch
        printf("do you want to continue(y/n):");
        fflush(stdin);
        c=getchar();
    }//end of while
    return 0;
}//end of main
//to create a linked list
void create(){      
    int n,i,coeff,exp;
    printf("enter no. of terms:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        nn=(struct node*)malloc(sizeof(struct node));
        printf("enter coeff and exp:");
        scanf("%d%d",&nn->coeff,&nn->exp);
        if(first==NULL){
            first=nn;
            nn->link=NULL;
            last=nn;
        }
        else{
            last->link=nn;
            nn->link=NULL;
            last=nn;
        }
    }
    display();//check how it is created
}
//to display a linked list
void display(){
    struct node *t;
    if(first==NULL)
        printf("List is empty\n");
    else{
        t=first;
        while(t!=NULL){
            printf("%dx^%d ", t->coeff,t->exp);
            t=t->link;
        }
        printf("\n");
    }
}
//to subtract two polynomials
void subtract(struct node*first1,struct node*first2){
    struct node *t1=first1,*t2=first2;
    while(t1!=NULL && t2!=NULL){
        nn=(struct node*)malloc(sizeof(struct node));
        if(t1->exp > t2->exp){
            nn->coeff=t1->coeff;
            nn->exp=t1->exp;
            t1=t1->link;
        }
        else if(t1->exp < t2->exp){
            nn->coeff=-t2->coeff;
            nn->exp=t2->exp;
            t2=t2->link;
        }
        else{
            nn->coeff=t1->coeff-t2->coeff;
            nn->exp=t1->exp;
            t1=t1->link;
            t2=t2->link;
        }
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
    while(t1!=NULL){
        nn=(struct node*)malloc(sizeof(struct node));
        nn->coeff=t1->coeff;
        nn->exp=t1->exp;
        nn->link=NULL;
        if(first==NULL){
            first=nn;
            last=nn;
        }
        else{
            last->link=nn;
            last=nn;
        }
        t1=t1->link;
    }
    while(t2!=NULL){
        nn=(struct node*)malloc(sizeof(struct node));
        nn->coeff=-t2->coeff; // change sign for subtraction
        nn->exp=t2->exp;
        nn->link=NULL;
        if(first==NULL){
            first=nn;
            last=nn;
        }
        else{
            last->link=nn;
            last=nn;
        }
        t2=t2->link;
    }
    display();
}
