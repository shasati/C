/*Program to implement double linked list*/
#include<stdio.h>
#include<stdlib.h>

//Creating a structure for double linked list
struct node{
    struct node* prev;
    int data;
    struct node* next;
};

struct node *head = NULL;

//Function to add at beginning of double linked list
void addatbeginning(int x){
    struct node *temp = head;
    struct node *newnode = NULL;
    newnode = malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = NULL;
    if(head == NULL){
        head = newnode;
    }else{
        newnode->next = temp;
        temp->prev = newnode;
        head = newnode;
    }
}

//Function to add at end of double linked list
void addatend(int x){
    struct node *temp = head;
    struct node *newnode = NULL;
    newnode = malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->data = x;
    newnode->next = NULL;
    if(head == NULL){
        head = newnode;
    }else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

//Function to display the double linked list
void display(){
    printf("The double linked list : ");
    struct node *temp = head;
    printf("NULL->");
    while(temp != NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL->");
}

//Function to insert an element in middle of double linked list
void addatmiddle(int x){
    struct node *hare = head;
    struct node *tort = head;
    struct node *newnode = NULL;
    newnode = malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->data = x;
    newnode->next = NULL;
    if(head == NULL){
        head = newnode;
    }else{
        while(hare!=NULL && hare->next != NULL){
            hare = hare->next->next;
            tort = tort->next;
        }
        tort->prev->next = newnode;
        newnode->next = tort;        
    }
    display();
}



int main(){
    int n;
    printf("Enter the number of elements you want in the linked list : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        printf("Enter the %d element : ",i);
        scanf("%d",&x);
        int option;
        printf("Enter 1 to add at beginning or enter 2 to add at end : ");
        scanf("%d",&option);
        if(option == 1){
            addatbeginning(x);
        }
        else 
        if(option == 2){
            addatend(x);
        }
        else{
            printf("Invalid Input");
            return -1;
        }
    }
    display();
    addatmiddle(66);
}