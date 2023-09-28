/*Creating sparse matrix using single linked list*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int row;
    int column;
    int data;
    struct node *next;
};
struct node* head = NULL;

int main(){
    int r,c;
    printf("Enter the number of rows and columns in the sparse matrix : ");
    scanf("%d%d",&r,&c);
    int *arr = (int*)malloc(r*c*sizeof(int));
    printf("Enter the sparse matrix elements : ");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&arr[i*r+j]);
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d ",arr[i*r+j]);
        }
    }
}