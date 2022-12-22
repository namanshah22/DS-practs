#include <stdio.h>
void insertionSort(int a[], int n){
 int i, j, key; 
 for( i = 1; i<n; i++){ 
 key = a[i]; 
 for( j = i-1; j>=0 && a[j]>key;j--){ 
 a[j+1] = a[j]; 
 } 
 a[j+1] = key; 
 } 
 for(int i=0;i<n;i++){ 
 printf("%d ", a[i]); 
 } 
}
int smallest(int arr[], int k, int n)
{
 int pos=k, small=arr[k], i;
 for(i=k+1;i<n;i++)
 {
 if(arr[i]<small)
 {
 small=arr[i];
 pos=i;
 }
 }
 return pos;
}
void selectionSort(int arr[],int n)
{
 int k,pos,temp;
 for(k=0;k<n;k++)
 {
 pos=smallest(arr,k,n);
 temp=arr[k];
 arr[k]=arr[pos];
 arr[pos]=temp;
 }
}
void swap(int* a, int* b) 
{ 
 int t = *a; 
 *a = *b; 
 *b = t; 
}
void printArray(int a[], int size) 
{ 
 int i; 
 for (i=0; i < size; i++) 
 { 
 printf("%d ", a[i]); 
 } 
 printf("\n"); 
} 
int main() 
{ 
 int n; 
 printf("Enter the number of elements: "); 
 scanf("%d", &n); 
 int arr[n]; 
 printf("Enter the elements: "); 
 for(int i=0;i<n;i++){ 
 scanf("%d",&arr[i]); 
 }
 int choice;
 do{
 printf("Menu:\n1.Insertion Sort\n2.Selection Sort\n");
 printf("Enter your choice:");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:
 printf("The sorted array is:\n");
 insertionSort(arr,n);
 break;
 
 case 2:
 printf("The sorted array is:\n");
 selectionSort(arr,n);
 printArray(arr,n);
 break;
case 3:
 break;
 
 default:
 printf("Invalid choice\n");
 break;
 }
 }
 while(choice!=3);
 return 0; 
}