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
void rev(char inf[]){
    char t;
    for(int i=0,j=strlen(inf)-1;i<j;i++,j--){
        t=inf[i];
        inf[i]=inf[j];
        inf[j]=t;
    }
}
int main(){
    char pf[100],inf[100];
    int i,j=0;
    printf("enter infix expression:");
    scanf("%s",inf);
    rev(inf);
    for(i=0;inf[i]!='\0';i++){
        if(inf[i]==')')
        push(inf[i]);
        else if(isalnum(inf[i]))
        pf[j++]=inf[i];
        else if(inf[i]=='('){
            while(top!=-1&&stack[top]!=')')
            pf[j++]=pop();
            
            pop();
        }
        else{
            while(priority(stack[top])>=priority(inf[i])&&top!=-1&&
            stack[top]!=')')
            pf[j++]=pop();
            
            push(inf[i]);
        }
        
    }
    while(top!=-1)
    pf[j++]=pop();
    pf[j]='\0';
    rev(pf);
    printf("%s",pf);
    return 0;
  
}
