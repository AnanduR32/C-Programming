#include <stdio.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
 
void bubbleSort(int arr[], int n)
{
    int i, j; 
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n-i-1; j++)
          if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);        
    }
}
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void main()
{
    int i=0,n=0;
    int arr[20];
    printf("Enter the size of the arry : ");
    scanf("%d",&n);
    while(i<n){
   	scanf("%d",&arr[i]);
	i++;
    }
    i=0;
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
}
