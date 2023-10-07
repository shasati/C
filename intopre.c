/*Converting an infix expression to prefix expression*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 40

struct stack{
    char data;
    struct stack* next;
};

struct stack* top = NULL;

int isEmpty(){
    if(top == NULL){
        return 1;
    }else
        return 0;
}

void push(char x){
    struct stack* new = malloc(sizeof(struct stack));
    new->data = x;
    new->next = NULL;
    if(top == NULL){
        top = new;
    }else{
        new->next = top;
        top = new;
    }
}

char pop(){
    struct stack* temp=top;
    if(isEmpty()){
        printf("Stack Underflow");
        return '\0';
    }
    else{
        top = temp->next;
        return temp->data;
        free(temp);
    }
}

int precedence(char op){
    if(op == '^'){
        return 3;
    }
    if(op == '*' || op == '/'){
        return 2;
    }
    if(op == '+' || op == '-'){
        return 1;
    }    
    return 0;
}

int main(){
    char infix[max],prefix[max];
    printf("Enter the infix expression : ");
    gets(infix);
    strrev(infix);
    int j=0;
    for(int i=0;infix[i]!='\0';i++){
        if(infix[i]>='a' && infix[i]<='z'){
            prefix[j++]=infix[i];
        }else
        if(infix[i]==')'){
            push(infix[i]);
        }else
        if(infix[i] == '('){
            while(!isEmpty() && top->data!=')'){
                prefix[j++]=pop();
            }
            if(top->data == ')'){
                pop();
            }
        }
        else{
            while(!isEmpty() && precedence(infix[i])<=precedence(top->data)){
                prefix[j++]=pop();
            }
            push(infix[i]);
        }
    }
    while(!isEmpty()){
        prefix[j++]=pop();
    }
    prefix[j]='\0';
    strrev(prefix);
    printf("The prefix string is %s",prefix);
}