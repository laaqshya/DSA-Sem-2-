// Online C compiler to run C program online
#include <stdio.h>
#include<string.h>
#include<ctype.h>
int stack[100];
int top=-1;
void push(int x){
    stack[++top]=x;
}
int pop(){
    return stack[top--];
}
int main(){
    char pf[100];
    int i=0,j=0,a,b,x;
    printf("enter postfix expression:");
    scanf("%s",pf);
    while(pf[i]!='\0'){
        if(isalnum(pf[i])){
        printf("enter the value of %c:",pf[i]);
        scanf("%d",&x);
        push(x);
        }
        else{
            a=pop();
            b=pop();
            switch(pf[i]){
                case '+':push(b+a);
                         break;
                case '-':push(b-a);
                         break;
                case '*':push(b*a);
                         break;
                case '/':push(b/a);
                         break;
            }
        }
        i++;
    }
    printf("value:%d",stack[top]);
}
