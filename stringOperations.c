#include<stdio.h>
#include<ctype.h>
#include<string.h>
int search(char *str,char *p,int lens,int lenp){
	int i=0,j=0;
	while(i<lens&&j<lenp){
		j=0;
		while(*(str+i++)==*(p+j++));
	}
	if(i<lens) 
		return (i-j);
	else 
		return -1;
}	
void delete(char *s,char *p,int lens,int lenp){
	int pos=search(s,p,lens,lenp);
	int k=0;
	while((pos+k)<=(lens)){
		*(s+pos+k)=*(s+pos+lenp+k);
		k++;
	}
	*(s+pos+k)='\0';
}
void strconcat(char *s1,char *s2){
	int i=0,j=0;
	while(*(s1+i)!='\0') 
		i++;
	while(*(s2+j)!='\0') 
		*(s1+i++)=*(s2+j++);
}void main(){
	int choice,i=0,pos=-1,lens,lenp;
	char s1[30],s2[30],s[45];
	printf("Enter your choice (1-3)\n\t\t1.Concatenation of two strings\n\t\t2.Search for pattern in a string\n\t\t3.Deletion of pattern from a string\n");
	scanf("%d",&choice);
	do{
		printf("Enter sentence/string 1 :");
		scanf("%s",&s1);
		printf("Enter pattern/String 2 :");
		scanf("%s",&s2);
		lens=strlen(s1);
		lenp=strlen(s2);
		switch(choice){
			case 1:	strconcat(s1,s2);
					printf("Resultant string is %s",s1);
					break;
			case 2: pos=search(s1,s2,lens,lenp);
					if(pos!=-1) printf("pattern found at location %d ",pos);
					else printf("Pattern not located\n");
					break;
			case 3: delete(s1,s2,lens,lenp);
					printf("Resultant string is %s",s1);
					break;
			default:printf("Invalid Choice");
		}
		i++;
	}while(i=0);
	
}
