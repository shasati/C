/*Addition of two polynomial equations using linked list*/
#include<stdio.h>
#include<stdlib.h>
struct poly{
    int coeff;
    int exp;
    struct poly* next;
};

struct poly* head1 = NULL;
struct poly* head2 = NULL;
struct poly* resulthead = NULL;

void createpoly(struct poly** head){
    struct poly *newnode,*temp;
    int exp,coeff;
    newnode = malloc(sizeof(struct poly));
    printf("Enter the coefficient and exponent of polynomial equation : ");
    scanf("%d%d",&coeff,&exp);
    newnode->exp = exp;
    newnode->coeff = coeff;
    if(*head == NULL){
        *head = newnode;
    }
    else{
        temp = *head;
        while(temp->next != NULL && temp->next->exp > newnode->exp){
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void display(struct poly* head){
    struct poly* temp = head;
    while(temp != NULL){
        printf("%dx%d+",temp->coeff,temp->exp);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int n;
    printf("Enter the total elements in first polynomial eq. : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        createpoly(&head1);
    }
    printf("Enter the total elements in second polynomial eq. : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        createpoly(&head2);
    }
    display(head1);
    display(head2);
}