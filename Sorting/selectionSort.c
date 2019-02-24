#include<stdio.h>
void main()
{
	int arr[20],i=0,j=0,size=0,temp=0,min;
	printf("Enter the size of the arry : ");
	scanf("%d",&size);
	while(i<size){
		scanf("%d",&arr[i]);
		i++;
	}
	i=0;
	printf("Before sorting\n");
	while(i<size){
		printf("%d ",arr[i]);
		i++;
	}
	i=0;
	for(i=0;i<size-1;i++)
	{
		min=i;
		for(j=i+1;j<size;j++)
		{
			if(arr[j]<arr[min]){
				min=j;
			}
		}	
		temp=arr[min];
		arr[min]=arr[j];
		arr[j]=temp;
	}
	printf("\nAfter Sorting\n");
	i=0;
	while(i<size){
		printf("%d ",arr[i]);
		i++;
	}
	printf("\n");
}




	
