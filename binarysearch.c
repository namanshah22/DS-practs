#include <stdio.h>
int main()
{ 
 int n,i; 
 printf("Enter the no. of elements: "); 
 scanf("%d", &n); 
 int arr[n]; 
 printf("Enter the array: "); 
 for(i=0;i<n;i++) 
 { 
 scanf("%d", &arr[i]); 
 }
 int val; 
 printf("Enter the element you wish to find: "); 
 scanf("%d", &val); 
 int start = 0; 
 int end = n-1; 
 int found=0;
 while(start<=end) 
 { 
 int mid = (start+end)/2; 
 if(arr[mid]==val) 
 {
 found=1;
 printf("%d is at index %d",val, mid); 
 break; 
 } 
 else if(arr[mid]>val) 
 { 
 end = mid - 1; 
 } 
 else
 { 
 start=mid+1; 
 } 
 }
 if(start>end && found==0) 
 { 
 printf("Element not found"); 
 } 
 return 0;
}