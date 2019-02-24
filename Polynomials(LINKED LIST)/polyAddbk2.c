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
	struct Node *new_node, *p,*head=(struct Node*)malloc(sizeof(struct Node));
	//struct Node *head=createNode(0,0);
	head=p;
	int i,c,e;	
	for(i=0;i<n;i++){
		printf("Enter the coefficient :");
		scanf("%d",&c);
		printf("Enter the exponent :");
		scanf("%d",&e);
		new_node=createNode(c,e);
		p=new_node;
		p=p->next;
	}
	return head;
}
void printList(struct Node* head)
{	
	struct Node* node=head->next;
	//node=node->next;
	while(node!=NULL){
		printf("%dx^%d ",node->c,node->e);
		node=node->next;
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
struct Node* addPoly(struct Node* a,struct Node* b)
{
	struct Node *n,*p,*head=(struct Node*)malloc(sizeof(struct Node));
	//struct Node *head=createNode(0,0);
	head=p;
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
	return head;
}
void main()
{
	int choice,data,n,num;
	struct Node*a,*b,*c=(struct Node*)malloc(sizeof(struct Node));
	do{
		printf("Enter the number of terms in polynomial 'a' :");
		scanf("%d",&num);
		a=createPoly(num);
		printf("Enter the number of terms in polynomial 'b' :");
		scanf("%d",&num);
		b=createPoly(num);
		c=addPoly(a,b);
		printf("\nResult of polynomial Addition : ");
		printList(c);
		printf("\nEnter 1 to continue : \n");
		scanf("%d",&n);
	}while(n==1);
	printf("\n");
}	
