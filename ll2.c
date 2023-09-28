/* create a linked list and perform the following functions 
1. Search an element in the list
2.Sort the list in ascending order
3.Reverse the list
*/
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node * head = NULL;

void create(int x){
    struct node* new = NULL;
    new = malloc(sizeof(struct node));
    new->data = x;
    new->next = NULL;
    if(head == NULL){
        head = new;
    }else{
        struct node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new;
    }
    
}

void print(){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void sort(){
    struct node* temp = head;
    struct node* i;struct node* j;
    for(i=temp;i->next!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if(i->data > j->data){
                int a;
                a = i->data;
                i->data = j->data;
                j->data = a;
            }
        }
    }
    print();
}
int main(){
    int n;
    printf("Enter the number of elements you want in the linked list : ");
    scanf("%d",&n);
    printf("Enter the values for the linked list \n");
    for(int i=0;i<n;i++){
        int x;
        printf("Enter the value of the %d element : ",i);
        scanf("%d",&x);
        create(x);
    }
    print();
    sort();
}