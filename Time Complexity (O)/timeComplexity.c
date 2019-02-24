#include<stdio.h>
#include<stdlib.h>
int i,j,k,num,temp=0;
void bubbleSort()
{
	int a[10],n=0;
	n++;	
	printf("Enter the number of elements :");
	scanf("%d",&num);
	printf("Enter the elements :");
	for(i=0;i<num;i++)
		scanf("%d",&a[i]);
		
	n+=2;	
	for(i=0;i<num;i++){
		n++;
		for(j=0;j<num-i-1;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				n+=4;
			}
			else n++;
		}n++;
	}n+=2;
	printf("Resultant Array :");
	for(i=0;i<num;i++)
		printf("%d",a[i]);
		n++;
	n+=2;
	printf("\n%d is the time complexity",n);
}
void selectionSort()
{
	int a[10],n=0;	
	n++;
	printf("Enter the number of elements :");
	scanf("%d",&num);
	printf("Enter the elements :");
	for(i=0;i<num;i++)
		scanf("%d",&a[i]);
	
	n+=2;
	for(i=0;i<num;i++){
		n++;
		for(j=i+1;j<num;j++){
			if(a[i]>a[j]){
				temp=a[j];
				a[j]=a[i];
				a[i]=temp;
				n+=4;
			}
			else n++;	
		}n++;
	}n+=2;
	printf("Resultant Array :");
	for(i=0;i<num;i++)
		printf("%d",a[i]);
		n++;
	n+=2;
	printf("\n%d is the time complexity",n);
}
void addMatrix()
{
	int h=0,a[10][10],b[10][10],pro[10][10];
	for(h=0;h<2;h++){
		printf("Enter the number of rows and columns :");
		scanf("%d",&num);
		printf("Enter the elements :");
		for(i=0;i<num;i++){
			for(j=0;i<num;j++){
				if(h=0)
					scanf("%d",&a[i][j]);	
				else 
					scanf("%d",&b[i][j]);			
			}
		}
	}	
	printf("Enter the number of rows and columns :");
	scanf("%d",&num);
	printf("Enter the elements :");
	for(i=0;i<num;i++){
		for(j=0;i<num;j++){
			scanf("%d",&a[i][j]);	
		}
	}
	int sum[10][10];
	for(i=0;i<num;i++){
		for(j=0;j<num;j++){
			sum[i][j]=a[i][j]+b[i][j];
		}
	}
}
void mulMatrix()
{	
	int h=0,a[10][10],b[10][10],pro[10][10];
	for(h=0;h<2;h++){
		printf("Enter the number of rows and columns :");
		scanf("%d",&num);
		printf("Enter the elements :");
		for(i=0;i<num;i++){
			for(j=0;i<num;j++){
				if(h=0)
					scanf("%d",&a[i][j]);	
				else 
					scanf("%d",&b[i][j]);			
			}
		}
	}
	for(i=0;i<num;i++){
		for(j=0;j<num;j++){
			pro[i][j]=0;
			for(k=0;k<num;k++){
				pro[i][j]=pro[i][j]+a[i][j]*b[i][j];
				printf("%d ",pro[i][j]);
			printf("\n");
			}
		}		
	}
}
void main()
{	
	int choice=0,n;
	lab:
	printf("Select the function for which you wish to find the space complexity :\n\t1.Bubble Sort\n\t2.Selection Sort\n\t3.Matrix Addition\n\t4.Matrix Multiplication\n\nEnter your choice (1-4)");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:	bubbleSort();
			
			break;
		case 2:	selectionSort();
			break;
		case 3: addMatrix();
			
			break;
		case 4:	mulMatrix();		
			break;
	}
	printf("To continue enter '1'");
	scanf("%d",&n);
	if(n==1)
		goto lab;
}




				
			
	
