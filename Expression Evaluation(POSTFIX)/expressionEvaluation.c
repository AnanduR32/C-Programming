#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int size=20,sizex=20,top=-1,topx=-1,stack[20],stackx[20];
void push(char item){
	if(top==size-1){
		printf("STACK OVERFLOW");
	}else{
		top+=1;
		stack[top]=item;
	}
}char pop(){
	char k;
	if(top==-1){
		printf("STACK UNDERFLOW");
		exit(0);
	}else{
		k=stack[top];
		top--;
		return k;
	}
}int isp(char x){
	int priority;
	switch(x){
		case '+':
		case '-': priority=2;
			  break;
		case '/':
		case '%':
		case '*': priority=4;
			  break;
		case '^': priority=5;
			  break;
		case '(': priority=0;
			  break;
	}return(priority);
}int icp(char x){
	int priority;
	switch(x){
		case '+':
		case '-': priority=1;
			  break;
		case '/':
		case '%':
		case '*': priority=3;
			  break;
		case '^': priority=6;
			  break;
		case '(': priority=9;
			  break;
		case ')': priority=0;
			  break;
	}return(priority);
}void evaluate(char exp[]){
	int i=0;
	char item,x;
	push('(');
	while(top>=0){
		item=exp[i];
		x=pop();
		if(isalpha(item)||isdigit(item)){
			push(x);
			printf(" %c",item);
		}else if(item==')'){
			while(x!='('){
				printf(" %c",x);
				x=pop();
			}
		}else if(isp(x)>=icp(item)){
			while(isp(x)>=icp(item)){
				printf(" %c",x);
				//pushx(x);
				x=pop();
			}push(x);
			push(item);
		}else if(isp(x)<icp(item)){
			push(x);
			push(item);
		}else printf("\nInvalid Expression\n");
	i++;
	}
}void main(){
	char exp[20];
	printf("\nEnter the mathematical expression :");
	scanf("%s",&exp);
	int len=strlen(exp);
	exp[len]=')';	
	evaluate(exp);
}
				
		


			
