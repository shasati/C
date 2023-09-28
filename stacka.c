/*Implementation of stacks using arrays*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int top = -1;
int stack[MAX];

int isFull(){
    if(top == MAX-1){
        return 1;
    }
    else
        return 0;
}

int isEmpty(){
    if(top == -1){
        return 1;
    }
    else    
        return 0;
}

void push(int x){
    if(isFull()){
        printf("Stack Overflow\n");
        return;
    }
    else{
        top+=1;
        stack[top] = x;
    }
}

void pop(){
    if(isEmpty()){
        printf("Stack Underflow\n");
        return;
    }
    else{
        printf("%d",stack[top]);
        top = top-1;
    }
}

void peek(){
    if(isEmpty()){
        printf("Stack Underflow\n");
        return;
    }
    else{
        printf("%d",stack[top]);
    }
}

int main(){
    while(1){
        int option;
        int a;
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("Enter the element you want to insert : ");
                scanf("%d",&a);
                push(a);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                return 0;
            default:
                printf("Please choose from the given options.");
                break;

        }
    }
}