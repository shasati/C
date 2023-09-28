/*Program to check if the brackets  in an expression are valid or not using stacks*/
#include<stdio.h>
#include<stdlib.h>
#define max 100
struct stack{
    char symbol;
    struct stack* next;
};

struct stack *head = NULL;

int isEmpty(){
    if(head == NULL){
        return 1;
    }
    else
        return 0;
}

void push(char s){
    struct stack* temp = head;
    struct stack* newnode = NULL;
    newnode = malloc(sizeof(struct stack));
    newnode->symbol = s;
    newnode->next = NULL;
    if(head == NULL){
        head = newnode;
    }else{
        newnode->next = temp;
        head = newnode;
    }
}

void pop(){
    struct stack* temp = head;
    printf("%c",temp->symbol);
    head = temp->next;
    free(temp);
}

int validate(char s){
    if(isEmpty()){
        printf("Brackets on the right more than expected.\n");
    }
    else{
        struct stack* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        if(s == ')' && temp->symbol=='('){
            pop();
            printf("%c\n",s);
        }else{
            printf("Brackets on the left more than expected.\n");
        }
    }
}

int main(){
    char A[max];
    printf("Enter the expression to be evaluated : ");
    scanf("%[^\n]s",&A);
    int i = 1;
    while(A[i] != '\0'){
        if(A[i] == '(' || A[i] == '[' || A[i] == '{'){
            push(A[i]);
        }
        else{
            if(A[i] == ')' || A[i] == ']' || A[i] == '}'){
                if(validate(A[i])){
                    continue;
                }
                else{
                    printf("Brackets on the right are more than expected.");
                }
            }
        }
        i++;
    }
}