// Online C compiler to run C program online
#include <stdio.h>
#include<string.h>
#include<ctype.h>
char stack[100];
int top=-1;
int priority(char x){
    if(x=='+'||x=='-')
    return 1;
    if(x=='*'||x=='/')
    return 2;
    if(x=='^')
    return 3;
}
void push(char x){
    stack[++top]=x;
}
char pop(){
    return stack[top--];
}
int main(){
    char pf[100],inf[100];
    int i,j=0;
    printf("enter infix expression:");
    scanf("%s",inf);
    for(i=0;inf[i]!='\0';i++){
        if(inf[i]=='(')
        push(inf[i]);
        
        else if(isalnum(inf[i]))
        pf[j++]=inf[i];
        
        else if(inf[i]==')'){
            while(top!=-1&&stack[top]!='(')
            pf[j++]=pop();
            
            
            if(top!=-1)
            pop();
        }
        else{
            while(top!=-1 && stack[top]!='('&& priority(stack[top])>=priority(inf[i]))
            pf[j++]=pop();
            
            push(inf[i]);
        }
        
    }
    while(top!=-1)
    pf[j++]=pop();
    
    pf[j]='\0';
    
    printf("%s",pf);
    return 0;
  
}
