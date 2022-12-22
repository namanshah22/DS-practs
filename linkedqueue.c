#include <stdio.h>
#include <stdlib.h>
struct queue
{
 int data;
 struct queue*next;
};
struct queue*front;
struct queue*rear;
void enqueue()
{
 struct queue*new;
 new = (struct queue*)malloc(sizeof(struct queue));
 struct queue*temp;
 printf("Enter the value you wish to insert: ");
 scanf("%d",&(new->data));
 if(front==NULL)
 {
 front=new;
 rear=new;
 front->next=rear->next=NULL;
 }
 else
 {
 rear->next=new;
 rear=new;
 rear->next=NULL;
 }
 
}
void display()
{
 struct queue*temp;
 if(front==NULL)
 {
 printf("Queue is empty");
 }
 else
 {
 printf("The queue is:\n");
 temp=front;
 while(temp!=NULL)
 {
 printf("%d \t",temp->data);
 temp=temp->next;
 }
 }
}
void dequeue()
{
 struct queue*temp;
 if(front==NULL)
 {
 printf("Queue is empty");
 }
 else
 {
 temp=front;
 front=temp->next;
 printf("The deleted element is: %d",temp->data);
 free(temp);
 
 }
}
int main()
{
 int choice;
 do{
 printf("Menu\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
 printf("Enter your choice: ");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:
 enqueue();
 display();
 printf("\n");
 break;
 
 case 2:
 dequeue();
 printf("\n");
 break;
 
 case 3:
 display();
 printf("\n");
 break;
 
 case 4:
 break;
 printf("\n");
 
 default:
 printf("Invalid choice");
 printf("\n");
 break;
 }
 }
 while(choice!=4);
}