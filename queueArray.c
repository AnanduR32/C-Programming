#include<stdio.h>
#include<stdlib.h>
int queue[20],size=-1,rear=-1,front=-1;
void enqueue(int item){
	if(rear==(size-1)){
		printf("QUEUE OVERFLOW");
		exit(0);
	}else{
		printf("Enter the element to be inserted :");
		scanf("%d",&item);
		if(rear==-1)
			rear=front=0;
		else
			rear++;
		queue[rear]=item;
	}
}int dequeue(){
	int k;
	if(front==(-1)){
		printf("QUEUE UNDERFLOW");
		exit(0);
	}else{
		k=queue[front];
		if(front==rear)
			front=rear=-1;
		else
			front++;
	}
	return k;
}void main(){
	int choice=-1,item=-1,i,j=0;
	printf("Enter the size of queue :");
	scanf("%d",&size);
	printf("Enter your choice :\n\t1.Insertion\n\t2.Deletion\n\t3.Exit\n");
	do{
		if(j>0)printf("Enter choice (1-2):\n");
		scanf("%d",&choice);	
		switch(choice){
			case 1:	enqueue(item);
				break;
			case 2:	item=dequeue();
				printf("Entry deleted : %d\n",item);
				break;
			case 3:	exit(0);
			default:
				printf("Invalid Entry\n");
		}
		j++;
	}while(1);
	printf("The resultant queue :\n");
	i=0;
	for(i=0;i<size;i++){
		printf(" %d",queue[i]);
	}
}

