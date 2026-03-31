// implementation of stacks using linked list
#include <stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* link;
}*top=NULL,*nn,*t;
void push(int ele);
void pop();
int isempty();
void traverse();
int main(){
	char c='y';
	int choice,ele;
	while(c=='y'){
		printf("select:\n1.insert\n2.delete\n3.isempty\n4.traverse\n");
		printf("enter choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("enter element:");
			       scanf("%d",&ele);
			       push(ele);
			       break;
			case 2:pop();
			       break;
			
			case 3:if(isempty())
			       printf("stack is Empty");
			       else
			       printf("stack is not Empty");
			       break;
			case 4:traverse();
			       break;
		}//end of switch
		printf("do you want to continue(y/n):");
		fflush(stdin);
		c=getchar();
		
	}//end of while
	return 0;
}//end of main
//function to insert an element in stack
void push(int ele){
	nn=(struct node*)malloc(sizeof(struct node));
	nn->data=ele;
	if(top==NULL){
		top=nn;
		top->link=NULL;
	}
	else{
		nn->link=top;
		top=nn;
	}
}//end of function
//function to delete an element in stack
void pop(){
	int ele;
	if(top==NULL)
	printf("stack is empty");
	else{
		ele=top->data;
		t=top;
		top=top->link;
		t->link=NULL;
		free(t);
	}		
}
//function for checking whether stack is empty
int isempty(void){
	if(top==NULL)
	return 1;
	else
	return 0;
}
//to traverse a stack
void traverse(void){
	int i;
	if(top==NULL)
	printf("\nstack is empty\n");
	    else{
	    	printf("content of stack:\n");
	    	t=top;
	    	while(t!=NULL){
	    		printf("%d\n",t->data);
	    		t=t->link;
			}
	    	
		}
	}
