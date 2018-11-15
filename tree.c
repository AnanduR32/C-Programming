#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *lc;
	int data;
	struct node*rc;
}*root=NULL;
struct node * createnode(int d){
	struct node *p;
	p=(struct node*)malloc(sizeof(struct node));
	p->lc=NULL;
	p->rc=NULL;
	p->data=d;
	return p;
}void inorder(struct node *ptr){
	if(ptr!=NULL){
		inorder(ptr->lc);
		printf(" %d ",ptr->data);
		inorder(ptr->rc);
	}
}
void preorder(struct node *ptr){
	if(ptr!=NULL){
		printf(" %d ",ptr->data);
		preorder(ptr->lc);
		preorder(ptr->rc);
	}
}void postorder(struct node *ptr){
	if(ptr!=NULL){
		postorder(ptr->lc);
		postorder(ptr->rc);
		printf(" %d ",ptr->data);
	}
}void insert(struct node *p){
	if(root==NULL){
		root=p;
	}else{
		int flag=0;	
		struct node *ptr=root,*parent;
		while(ptr!=NULL && flag!=1){
			if(ptr->data<p->data) 
				parent=ptr;
				ptr=ptr->rc;
			}else if(ptr->data>p->data){
				parent=ptr;
				ptr=ptr->lc;
			}else{
				flag=1;
				printf("Data exists!!");
			}
		}if(flag==0){
			if(parent->data<p->data)
				parent->rc=p;
			else
				parent->lc=p;
		}
	}
}void search(struct node *p){
	if(root==NULL)		
		printf("The tree is empty");	
	else{
		int flag=0;	
		struct node *ptr=root;
		while(ptr!=NULL && flag!=1){
			if(ptr->data<p->data) 			
				ptr=ptr->rc;
			else if(ptr->data>p->data)			
				ptr=ptr->lc;			
			else{
				flag=1;
				printf("Data exists!!");
			}
		}if(flag==0){
			printf("The data is not found");
		}
	}
}void main(){
	int choice=8,m;
	struct node *p;
	while(choice!=3){
		printf("\nEnter your choice :\n\t\t1.Insertion\n\t\t2.Traversal\n\t\t3.Exit\nInput : ");
		scanf("%d",&choice);
		switch(choice)
			{
			case 1: printf("Enter the value:");
				scanf("%d",&m);
				p=createnode(m);
				insert(p);
				break;
			case 2: inorder(root);
				printf("\n");
				break;
			case 3: preorder(root);
				printf("\n");
				break;
			case 4: postorder(root);
				printf("\n");
				break;
			case 5: printf("Enter the element to be searched:");
				scanf("%d",&m);
				p=createnode(m);
				search(p);
				printf("\n");
				break;
			case 6: printf("\n");
				break;
			default:printf("Enter the valid input\n");
			}
		}
}
