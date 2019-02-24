#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct Node
{
	int c,e;
	struct Node *next;
};
struct Node* createNode(int c, int e)
{
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->c=c;
	new_node->e=e;
	return new_node;
	
}
struct Node* createPoly(int n)
{
	struct Node *new_node, *p=(struct Node*)malloc(sizeof(struct Node));
	struct Node *head=createNode(0,0);
	p=head;
	int i,c,e;	
	for(i=n-1;i>=0;i--){
		printf("Enter the coefficient of x^%d:",i);
		scanf("%d",&c);
		new_node=createNode(c,i);
		p->next=new_node;
		p=p->next;
	}
	
	return head;
}
void printList(struct Node* head)
{	
	struct Node* node=head->next;
	//node=node->next;
	while(node!=NULL){
		/*if(node->c==0){
			node=node->next;
			continue;
		}*/
		printf(" %dx^%d ",node->c,node->e);
		node=node->next;
		if(node->e==0){
			printf("%d\n\n",node->c);
			break;
		}
	}
}
/*struct Node* addPoly(struct Node* a,struct Node* b)
{
	struct Node* n=(struct Node*)malloc(sizeof(struct Node));
	while(a!=NULL && b!=NULL){
		if(a->e>b->e){
			n=createNode(a->c,b->e);
			a=a->next;
		}
		else if(b->e>a->e){
			n=createNode(b->c,b->e);
			b=b->next;
		}
		else{
			n=createNode(a->c+b->c,a->e);
			a=a->next;
			b=b->next;
		}
	}
	return n;
}
*/
struct Node* addPoly(struct Node* a,struct Node* b,int num1, int num2)
{
	/*struct Node *n,*p,*head=(struct Node*)malloc(sizeof(struct Node));
	//struct Node *head=createNode(0,0);
	head->next=p;
	while(a!=NULL && b!=NULL){
		if(a->e>b->e){
			n=createNode(a->c,b->e);
			a=a->next;
		}
		else if(b->e>a->e){
			n=createNode(b->c,b->e);
			b=b->next;
		}
		else{
			n=createNode(a->c+b->c,a->e);
			a=a->next;
			b=b->next;
		}
		p=n;
		p=p->next;
	}
	return head;*/
	int num,i;	
	struct Node *n,*p=(struct Node*)malloc(sizeof(struct Node));
	struct Node* head=createNode(0,0);
	p=head;	
	if(num1>num2)
		num=num1;
	else
		num=num2;
	for(i=num-1;i>=0;i--){
		if(i>num1){
			n=createNode(b->c,i);
			b=b->next;
		}else if(i>num2){
			n=createNode(a->c,i);
			a=a->next;
		}else{
			n=createNode(a->c+b->c,i);
			b=b->next;
			a=a->next;
		}
		p->next=n;
		p=p->next;
	}
	return head;
}
void main()
{
	int choice,data,n,num1,num2;
	struct Node*a,*b,*c=(struct Node*)malloc(sizeof(struct Node));
	do{
		printf("Enter the number of terms in polynomial 'a' :");
		scanf("%d",&num1);
		a=createPoly(num1);
		printf("\nThe polynomial entered : ");
		printList(a);
		printf("Enter the number of terms in polynomial 'b' :");
		scanf("%d",&num2);
		b=createPoly(num2);
		printf("\nThe polynomial entered : ");
		printList(b);
		c=addPoly(a,b,num1,num2);
		printf("\nResult of polynomial Addition : ");
		printList(c);
		printf("\nEnter 1 to continue : \n");
		scanf("%d",&n);
	}while(n==1);
	printf("\n");
}	
