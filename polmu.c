#include <stdio.h>
#include <stdlib.h>

struct node{
    int coeff;
    int exp;
    struct node *link;
};

struct node *first1=NULL,*first2=NULL,*result=NULL;

//function prototypes
void create(struct node **first);
void display(struct node *first);
void multiply(struct node *p1, struct node *p2);

int main()
{
    printf("Enter first polynomial:\n");
    create(&first1);

    printf("Enter second polynomial:\n");
    create(&first2);

    printf("\nPolynomial 1: ");
    display(first1);

    printf("Polynomial 2: ");
    display(first2);

    printf("\nMultiplication Result:\n");
    multiply(first1,first2);

    display(result);

    return 0;
}

//create polynomial
void create(struct node **first)
{
    int n,i;
    struct node *nn,*last=NULL;

    printf("Enter number of terms: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        nn=(struct node*)malloc(sizeof(struct node));

        printf("Enter coefficient and exponent: ");
        scanf("%d%d",&nn->coeff,&nn->exp);

        nn->link=NULL;

        if(*first==NULL)
        {
            *first=nn;
            last=nn;
        }
        else
        {
            last->link=nn;
            last=nn;
        }
    }
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

//multiply polynomials
void multiply(struct node *p1, struct node *p2)
{
    struct node *t1=p1,*t2;
    struct node *nn,*last=NULL;

    while(t1!=NULL)
    {
        t2=p2;

        while(t2!=NULL)
        {
            nn=(struct node*)malloc(sizeof(struct node));

            nn->coeff = t1->coeff * t2->coeff;
            nn->exp   = t1->exp + t2->exp;
            nn->link  = NULL;

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

        t1=t1->link;
    }
}
