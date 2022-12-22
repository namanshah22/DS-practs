#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
char st[MAX];
int top=-1;
void push(float st[],float val)
{
 top++;
 st[top]=val;
}
char pop(float st[])
{
 float val;
 val=st[top];
 top--;
 return val;
}
float evaluate(char str[])
{
 int i=0;
 float op1,op2,value;
 while(str[i]!='\0')
 {
 if(isdigit(str[i]))
 {
 push(st, (float)(str[i]-'0'));
 }
 else
 {
 op2=pop(st);
 op1=pop(st);
 switch(str[i])
 {
 case '+':
 value=op1+op2;
 break;
 
 case '-':
 value=op1-op2;
 break;
 
 case '*':
 value=op1*op2;
 break;
 
 case '/':
 value=op1/op2;
 break;
 
 case '%':
 value=(int)op1%(int)op2;
 break;
 }
 push(st,value);
 }
 i++;
 }
 return (pop(st));
}
int main()
{
 float val;
 char str[100];
 printf("Enter a postfix expression:\n");
 gets(str);
 val = evaluate(str);
 printf("\nThe value of the postfix expression = %.2f",val);
 getch();
 return 0;
}
