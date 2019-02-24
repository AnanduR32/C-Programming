#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
void push(struct Node** head_ref,int new_data)
{
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->data=new_data;
	new_node->next=(*head_ref);
	(*head_ref)=new_node;
}
void append(struct Node* last,int new_data)
{
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->next=NULL;
	new_node->data=new_data;
	while(1){
		if(last->next==NULL){
			last->next=new_node;
			break;
		}else{
			while(last->next!=NULL)
				last=last->next;
		}
	}
}
void trim(struct Node* last)
{
	struct Node* p=last;
	last=last->next;
	while(last->next!=NULL)
	{			
		p=last;
		last=last->next;					
	}
	p->next=NULL;
}
void insertAfter(struct Node *prev_node,int new_data, int n)
{
	int i=1;
	if(prev_node==NULL){
		printf("The given previous node cannot be NULL");
		return;
	}
	for(i=1;i<n;i++)
	{
		prev_node=prev_node->next;
		if(prev_node->next==NULL){
			printf("Reached End of Linked List\n");
			break;	
		}
	}	
	struct Node *new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->data=new_data;
	new_node->next=prev_node->next;
	prev_node->next=new_node;
}
void delAfter(struct Node *T_node, int n)
{
	int i=1;
	struct Node *prev_node=(struct Node*)malloc(sizeof(struct Node));
	if(T_node==NULL){
		printf("Empty Linked List");
		return;
	}
	for(i=1;i<n;i++)
	{
		prev_node=T_node;		
		T_node=T_node->next;
		if(T_node->next==NULL){
			printf("Reached End of Linked List\n");
			break;	
		}
	}	
	
	prev_node->next=T_node->next;
	T_node->next=NULL;
}
void printList(struct Node *node)
{
	while(node!=NULL){
		printf("%d ",node->data);
		node=node->next;
	}
}
void delBegin(struct Node** head_ref)
{
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->data=(*head_ref)->data;
	new_node->next=(*head_ref)->next;
	new_node=new_node->next;
	(*head_ref)=new_node;
}
void main()
{
	int choice,data,c,n;
	struct Node *head=NULL;
	do{
		printf("Choose Option From Following :\n\t1.Insertion at Beginning\n\t2.Delete first node\n\t3.Display result\n\t4.Insertion After nth element\n\t5.Deletion of the nth element\n\t6.Append a value to end of list\n\t7.Delete the last node\nEnter Choice : ");
		scanf("%d",&choice);
				
		switch(choice)
		{
			case 1:	printf("Enter the data : ");
				scanf("%d",&data);
				push(&head,data);
				break;
			case 2:	delBegin(&head);
				break;
			case 3:	printList(head);
				break;
			case 4:	printf("Enter the value of n");
				scanf("%d",&n);
				printf("Enter the data : ");
				scanf("%d",&data);
				insertAfter(head/*->next*/,data,n);
				break;
			case 5:	printf("Enter the value of n");
				scanf("%d",&n);
				delAfter(head/*->next*/,n);
				break;
			case 6:	printf("Enter the data : ");
				scanf("%d",&data);
				append(head,data);
				break;
			case 7:	trim(head);
				break;	
			default:
				printf("Invalid Entry\n");
		}
		printf("Enter 1 to continue : \n");
		scanf("%d",&c);
	}while(c==1);
	
	printf("\nCreated Linked List is : ");
	printList(head);
	printf("\n");
}	
