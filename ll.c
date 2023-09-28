/*Program to create a linked list*/
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* head  = NULL;

//Function to insert element in linked list
void create(int x){
    struct node* newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
    }else{
        struct node* current;
        current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
}

//Function to print the linked list
void print(){
    struct node* current;
    current = head;
    printf("The element in the linked list are : ");
    while(current != NULL){
        printf("%d->",current->data);
        current = current->next;
    }   
    printf("NULL");
}
//Function to insert an element in the linked list
void insert(){
    struct node* temp = head;
    struct node* new = NULL;
    new = malloc(sizeof(struct node));
    int ele,index;
    printf("Enter the position where you want to insert the element : ");
    scanf("%d",&index);
    printf("Enter the value of the element : ");
    scanf("%d",&ele);
    new->data = ele;
    new->next = NULL;
    if(index == 0){
        new->next = head;
        head = new;
        return;
    }
    for(int i=0;i<index-1;i++){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("INVALID POSITION");
        return 1;
    }
    else{
        new->next = temp->next;
        temp->next = new;
    }
    print();
}
//Function to delete an element from linked list
void delete(){
    struct node* temp1 = head,*temp2=head;
    int ele;
    printf("Enter the index form where you want to delete the element : ");
    scanf("%d",&ele);
    for(int i=0;i<(ele-1);i++){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    temp1->next = temp1->next->next;
    free(temp2->next);
}
int main(){
    int n;
    printf("Enter the number of elements you want in your linked list : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        printf("Enter the %d element :",i);
        scanf("%d",&x);
        create(x);
    }
    int option;
    printf("Enter a number from following options \n");
    printf("1.To print the linked list");
    printf("\n2.Inserting a node at a certain position");
    printf("\n3.Deletion of element a certain position");
    printf("\n4.Counting number of nodes\n");
    printf("Enter your option : ");
    scanf("%d",&option);
    switch(option){
        case 1:
            print();
            break;
        case 2:
            insert();
            break;
        case 3:
            delete();
        default :
            printf("EXITTING...");
            break;
        }
}