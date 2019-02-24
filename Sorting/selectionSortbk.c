#include <stdio.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void selectionSort(int arr[], int n)
{
    int i, j, min;
 
    for (i = 0; i < n-1; i++)
    {
        min = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min])
            min = j;
 
        swap(&arr[min], &arr[i]);
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
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
}
