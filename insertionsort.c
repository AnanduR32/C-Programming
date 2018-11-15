#include <stdio.h> 
#include <math.h>   
void insertionSort(int a[], int n){
   int i, key, j; 
   for (i = 1; i < n; i++){ 
       key = a[i]; 
       j = i-1; 
       while (j >= 0 && a[j] > key){ 
           a[j+1] = a[j]; 
           j = j-1; 
       } 
       a[j+1] = key; 
   } 
}void print(int a[], int n){ 
   int i; 
   for (i=0; i < n; i++) 
   printf("%d ", a[i]); 
   printf("\n"); 
}void main(){ 
    int a[10],n,i; 
    printf("\nenter the size:");
    scanf("%d",&n);
    printf("\nenter the elements:\n");
    for(i=0;i<n;i++)
    {
         scanf("%d",&a[i]);
    }
    insertionSort(a, n); 
    print(a, n);
} 

