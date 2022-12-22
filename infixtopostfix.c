#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
char st[MAX];
int top=-1;
void push(char st[],char val)
{
 top++;
 st[top]=val;
}
char pop(char st[])
{
 char val;
 val=st[top];
 top--;
 return val;
}
int getpriority(char op)
{
 if(op=='/'||op=='*'|| op=='%'){
 return 1;
 }
 else if(op=='+'||op=='-'){
 return 0;
 }
}
void conversion(char source[], char target[])
{
 int i=0,j=0;
 char temp;
 strcpy(target,"");
 while(source[i]!='\0')
 {
 if(source[i]=='(')
 {
 push(st,source[i]);
 i++;
 }
 else if(source[i]==')')
 {
 while((top!=-1)&&(st[top]!='('))
 {
 target[j]=pop(st);
 j++;
 }
 if(top==-1)
 {
 printf("Invalid Expression");
 exit(1);
 }
 temp=pop(st);
 i++;
 }
 else if(isdigit(source[i])||isalpha(source[i]))
 {
 target[j]=source[i];
 j++;
 i++;
 }
 else if(source[i]=='+' || source[i]=='-' || source[i]=='*'|| 
source[i]=='/'||source[i]=='%')
 {
 while((top!=-1)&&(st[top]!='(')&&(getpriority(st[top])>getpriority(source[i])))
 {
 target[j]=pop(st);
 j++;
 }
 push(st,source[i]);
 i++;
 }
 else
 {
 printf("Incorrect element");
 exit(1);
 }
 }
 while((top!=-1)&&(st[top]!='('))
 {
 target[j]=pop(st);
 j++;
 }
 target[j]='\0';
}
int main()
{
 char infix[100], postfix[100];
 printf("Enter an infix expression:\n");
 gets(infix);
 strcpy(postfix,"");
 conversion(infix,postfix);
 printf("\nThe corresponding postfix expression is\n");
 puts(postfix);
 getch();
 return 0;
}