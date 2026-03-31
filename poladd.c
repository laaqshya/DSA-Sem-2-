#include <stdio.h>
#include <stdlib.h>

struct node{
    int coeff;
    int exp;
    struct node *link;
};

struct node *first1=NULL,*first2=NULL,*result=NULL;

//function prototypes
struct node* create();
void display(struct node *first);
void add(struct node *first1, struct node *first2);

int main()
{
    printf("Enter Polynomial 1:\n");
    first1 = create();

    printf("\nEnter Polynomial 2:\n");
    first2 = create();

    printf("\nPolynomial 1: ");
    display(first1);

    printf("\nPolynomial 2: ");
    display(first2);

    printf("\nResult after Addition:\n");
    add(first1,first2);

    display(result);

    return 0;
}

//create polynomial (returns head)
struct node* create()
{
    int n,i;
    struct node *nn,*first=NULL,*last=NULL;

    printf("Enter number of terms: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        nn=(struct node*)malloc(sizeof(struct node));

        printf("Enter coefficient and exponent: ");
        scanf("%d%d",&nn->coeff,&nn->exp);

        nn->link=NULL;

        if(first==NULL)
        {
            first=nn;
            last=nn;
        }
        else
        {
            last->link=nn;
            last=nn;
        }
    }
    return first;
}

//display polynomial
void display(struct node *first)
{
    struct node *t=first;

    while(t!=NULL)
    {
        printf("%dx^%d",t->coeff,t->exp);
        t=t->link;

        if(t!=NULL)
            printf(" + ");
    }
    printf("\n");
}

//add two polynomials
void add(struct node *first1, struct node *first2)
{
    struct node *t1=first1,*t2=first2,*nn,*last=NULL;

    result = NULL;

    while(t1!=NULL && t2!=NULL)
    {
        nn=(struct node*)malloc(sizeof(struct node));
        nn->link=NULL;

        if(t1->exp > t2->exp)
        {
            nn->coeff=t1->coeff;
            nn->exp=t1->exp;
            t1=t1->link;
        }
        else if(t1->exp < t2->exp)
        {
            nn->coeff=t2->coeff;
            nn->exp=t2->exp;
            t2=t2->link;
        }
        else
        {
            nn->coeff=t1->coeff + t2->coeff;
            nn->exp=t1->exp;
            t1=t1->link;
            t2=t2->link;
        }

        if(result==NULL)
        {
            result=nn;
            last=nn;
        }
        else
        {
            last->link=nn;
            last=nn;
        }
    }

    // remaining terms of t1
    while(t1!=NULL)
    {
        nn=(struct node*)malloc(sizeof(struct node));
        nn->coeff=t1->coeff;
        nn->exp=t1->exp;
        nn->link=NULL;

        if(result==NULL)
        {
            result=nn;
            last=nn;
        }
        else
        {
            last->link=nn;
            last=nn;
        }

        t1=t1->link;
    }

    // remaining terms of t2
    while(t2!=NULL)
    {
        nn=(struct node*)malloc(sizeof(struct node));
        nn->coeff=t2->coeff;
        nn->exp=t2->exp;
        nn->link=NULL;

        if(result==NULL)
        {
            result=nn;
            last=nn;
        }
        else
        {
            last->link=nn;
            last=nn;
        }

        t2=t2->link;
    }
}
