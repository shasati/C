/*Addition of two polynomial equations using linked list*/
#include<stdio.h>
#include<stdlib.h>
struct poly{
    int coeff;
    int exp;
    struct poly* next;
};

struct poly* head = NULL;

void createpoly(){
    struct poly *newnode,*temp;
    int exp,coeff;
    newnode = malloc(sizeof(struct poly));
    printf("Enter the coefficient and exponent of polynomial equation : ");
    scanf("%d%d",&coeff,&exp);
    newnode->exp = exp;
    newnode->coeff = coeff;
    if(head == NULL){
        head = newnode;
    }
    else{
        temp = head;
        while(temp!=NULL && temp->next->exp > newnode->exp){
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

int main(){
    int n;
    printf("Enter the total elements in polynomial equation : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        createpoly();
    }
}