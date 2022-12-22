#include <stdio.h>
#include <stdlib.h>
#define max 5

struct node{
    int data;
    struct node *next;
};

struct node *f = NULL;

struct node *createnode(){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->next = NULL;
    return new;
}

void push(){
    struct node *new = createnode();
    printf("Enter Value : ");
    scanf("%d",&new->data);
    if(f == NULL){
        f = new;
    }
    else{
        new->next = f;
        f = new;
    }
}

void pop(){
    if(f == NULL){
        printf("Stack Underflow");
    }
    else{
       printf("\nPop data : %d", f->data);
       struct node *temp = f;
       f = f->next;
       free(temp);
    }
}

void peek(){
    if(f == NULL){
        printf("Stack Underflow");
    }
    else{
       printf("\nTop data : %d", f->data);
    }
}
void display()
{
 struct node*ptr;
 ptr=f;
 if(f==NULL)
 {
 printf("Stack is empty");
 }
 else
 {
 printf("Stack is:\n");
 while(ptr!=NULL)
 {
 printf("%d\n",ptr->data);
 ptr=ptr->next;
 }
 }
}


void main(){
    int s, flag =1;
    while(flag){
        printf("\nmenu\n1.Push\n2.Pop\n3.Peek\n4.display\n5.Exit\n : ");
        scanf("%d", &s);
        switch(s){
            case 1:push();break;
            case 2:pop();break;
            case 3:peek();break;
            case 4:display();break;
            case 5:flag=0;break;
            default : printf("Wrong Input");
        }
    }
}