/*Program to create a circular linked list*/
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node *tail = NULL;

void insert(int x){
    struct node* temp = tail;
    struct node* newnode = NULL;
    newnode = malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if(tail == NULL || tail->next == NULL){
        tail = newnode;
        tail->next = tail;
    }else{
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}

void display(){
    printf("The elements are : ");
    struct node* temp = tail;
    do{
        printf("%d ",temp->data);
        temp = temp->next;
    }while(temp->next != tail->next);
}

int main(){
    int n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    printf("Enter the elements of circular linked list : ");
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        insert(x);
    }
display();
}