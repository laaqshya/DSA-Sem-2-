//implementation of q using ll
#include <stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* link;
}*f=NULL,*r=NULL,*nn,*t;
void insert(int ele);
void delete();
int isempty();
void traverse();
int main(){
	char c='y';
	int choice,ele;
	while(c=='y'){
		printf("select:\n1.insert\n2.delete\n3.isfull\n4.isempty\n5.traverse\n");
		printf("enter choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("enter element:");
			       scanf("%d",&ele);
			       insert(ele);
			       break;
			case 2:delete();
			       break;
			case 4:if(isempty())
			       printf("Empty");
			       else
			       printf("not Empty");
			       break;
			case 5:traverse();
			       break;
		}//end of switch
		printf("do you want to continue(y/n):");
		fflush(stdin);
		c=getchar();
	}//end of while
	return 0;
}//end of main
//function to insert an element
void insert(int ele){
	nn=(struct node*)malloc(sizeof(struct node));
	nn->data=ele;
	if(f==NULL && r==NULL){
		f=nn;
		r=nn;
		f->link=NULL;
	}
	else{
		r->link=nn;
		r=nn;
		r->link=NULL;
	}
}//end of function
//to delete an element
void delete(void){
	int ele;
	if(isempty())
	printf("queue is empty");
	else if(f==r){
		t=f;
		f=NULL;
		r=NULL;
		ele=t->data;
		printf("Deleted element=%d",ele);
		free(t);
	}
	else{
		t=f;
		f=f->link;
		ele=t->data;
		t->link=NULL;
		printf("deleted element=%d",ele);
		free(t);
	}	
}
void traverse(){
	if(isempty())
	printf("Q is empty");
	else{
		printf("content of q:\n");
		t=f;
		while(t!=NULL){
			printf("%d ",t->data);
			t=t->link;
		}
	}
}
//to check if q is empty
int isempty(){
	if(f==NULL)
	return 1;
	else 
	return 0;
}
