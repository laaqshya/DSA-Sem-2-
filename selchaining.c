#include<stdio.h>
#include<stdlib.h>
#define Size 10

struct node{
	int data;
	strucy node*link;
}*nn,*Table[Size],*first=NULL,*t;


void create(){
	int n;
	printf("enter no.of keys");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		nn=(struct node*)malloc(sizeof(struct node));
		printf("enter key:");
		scanf("%d",&nn->data);
		int k=nn->data%size;
		nn->link=NULL;
		if(Table[k]==NULL)
			Table[k]=nn;
		else{
			t=Table[k];
			while(t!=NULL){
				t=t->link;
			}
			t=t->link;
		}
}
display();
}

//to search for a given element
void search(){
	int e;
	printf("enter element to search:");
	scanf("%d",&e);
	int a=e%Size;
	t=Table[a];
	if(t==NULL)
	printf("element does not exist\n");
	while(t!=NULL){
		if(t->data==e){
			print("element found");
			break;
		}
		t=t->link;
	}
}
void display(int n)
	for(int i=0;i<n;i++){
		printf("elements at %d index",i);
		if(Table[i]==NULL)
		printf("no elements found at index %d",i);
		else{
			t=table[i]
			while(t!=NULL){
				printf("%d->",t->data);
				t=t->link;
			}
		}
	}
}

int main(){
	int choice;
	printf("Select:\n1.Create\n2.search\n3.display\n");
	char c='y';
	for(int i=0;i<n;i++)
	Table[i]=NULL;
	while(c=='y'){
		printf("enter your choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
			       printf("creation:");
			       create();
			       break;
			case 2:
				  printf("search:\n");
				  search();
				  break;
			case 3:
				  printf("display:\n");
				  display();
				  break;
			default:
				  printf("invalid choice:");	  
		}
		printf("Do you want to continue:");
		scanf("%c",&c)
	}
}

}
