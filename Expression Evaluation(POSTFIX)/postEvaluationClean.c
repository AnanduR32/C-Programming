#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int size=20,top=-1,stack[20];
void push(char item){
	
	stack[++top]=item;
}int pop(){
	
	return stack[top--];		
}float postEvaluate(char exp[]){
	int i=0,a,b,c;
	
	while(exp[i]!='\0'){
		if(isalpha(exp[i])||isdigit(exp[i])) push(exp[i]-'0');
		else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='/'||exp[i]=='*'||exp[i]=='%'){
			b=pop();
			a=pop();
			switch(exp[i]){
				case '+' : c=a+b;
					   break;
				case '-' : c=a-b;
					   break;
				case '/' : c=a/b;
					   break;
				case '*' : c=a*b;
					   break;
				case '%' : c=a%b;
					   break;
			}push(c);
		}i++;
	}
	return pop();
}void main(){
	float result;
	char exp[20];
	char *e;
	e=exp;
	printf("\nEnter the mathematical expression :");
	scanf("%s",&exp);
	result=postEvaluate(exp);
	printf("The result : %5.2f",result);
}
		
