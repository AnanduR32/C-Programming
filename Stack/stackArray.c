#include<stdio.h>
#include<stdlib.h>
int top=-1,stack[20];
void push(int item,int size){
	if(top==size-1){
		printf("STACK OVERFLOW");
		exit(0);
	}else{
		printf("Enter the element to be inserted :");
		scanf("%d",&item);
		top+=1;
		stack[top]=item;
	}
}int pop(){
	int k;
	if(top==-1){
		printf("STACK UNDERFLOW");
		exit(0);
	}else{
		k=stack[top];
		top--;
		return k;
	}
}void main(){
	int size,choice=-1,item=-1,i,j=0;
	printf("Enter the size of stack :");
	scanf("%d",&size);
	printf("Enter your choice :\n\t1.Insert an element into the stack\n\t2.Delete first element in stack\n\t3.Exit Program\n");
	do{
		if(j>0)printf("Enter choice (1-2):\n");
		scanf("%d",&choice);	
		switch(choice){
			case 1:	push(item,size);
				break;
			case 2:	item=pop();
				printf("Entry from stack that has been deleted is %d: ",item);
				break;
			case 3:	exit(0);
			default:
				printf("Invalid Entry\n");
		}
		j++;
	}while(1);
	printf("The resultant stack :\n");
	i=0;
	for(i=0;i<size;i++){
		printf(" %d",stack[i]);
	}
}

			
		
