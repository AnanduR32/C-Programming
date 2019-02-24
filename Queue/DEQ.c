#include<stdio.h>
#include<stdlib.h>
int queue[20],size=-1,rear=-1,front=-1;
void enqueueR(int item){
	if(rear==(size-1)){
		printf("QUEUE OVERFLOW\n");
	}else{
		printf("Enter the element to be inserted :");
		scanf("%d",&item);
		if(rear==-1)
			rear=front=0;
		else
			rear++;
		queue[rear]=item;
	}
}void enqueueF(int item){
	if(front==0)
		printf("OVERFLOW\n");
	else{
		if(front==-1) front=rear=0;
		else front=front-1;
		printf("Enter the element to be inserted :");
		scanf("%d",&item);
		queue[front]=item;
	}
}int dequeueF(){
	int k;
	if(front==(-1)){
		printf("QUEUE UNDERFLOW\n");
		exit(0);
	}else{
		k=queue[front];
		if(front==rear) front=rear=-1;
		else front++;
	}return k;
}int dequeueR(){
	int k;
	if(rear==(-1))printf("QUEUE UNDERFLOW");
	else{
		k=queue[rear];
		if(front==rear) front=rear=-1;
		else rear--;
	}
	return k;
}void main(){
	int choice=-1,item=-1,i,j=0;
	printf("Enter the size of queue :");
	scanf("%d",&size);
	printf("Enter your choice :\n\t1.Insertion End\n\t2.Deletion Beginning\n\t3.Insertion Beginning\n\t4.Deletion End\n\t5.Exit\n");
	do{
		if(j>0)printf("Enter choice (1-5):\n");
		scanf("%d",&choice);	
		switch(choice){
			case 1:	enqueueR(item);
				break;
			case 2:	item=dequeueF();
				printf("Entry deleted : %d\n",item);
				break;
			case 3:	enqueueF(item);
				break;
			case 4:	item=dequeueR();
				printf("Entry deleted : %d\n",item);
				break;
			case 5:	goto lab;
			default:
				printf("Invalid Entry\n");
		}
		j++;
	}while(1);
	lab:
	printf("The resultant queue :\n");
	i=0;
	for(i=0;i<size;i++){
		printf(" %d",queue[i]);
	}
}

