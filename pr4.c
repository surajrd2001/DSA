#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdbool.h>
#define MAX 100
char s1[MAX][MAX], s2[MAX];
int top1=-1,top2=-1;
void push1(char *s)
{
	if(top1>=MAX-1)
	return;
	
	strcpy(s1[++top1],s);
}
char *pop1()
{
	return s1[top1--];
}
char *Top1()
{
	return s1[top1];
}
bool empty1()
{
	if(top1==-1)
	return true;
	
	else
	return false;
}
void push2(char c)
{
	if(top1>=MAX-1)
	return;
	
	s2[++top2]=c;
}
char pop2()
{
	return s2[top2--];
}
char Top2()
{
	return s2[top2];
}
bool empty2()
{
	if(top2==-1)
	return true;
	
	else
	return false;
}
bool isOperator(char c)
{
	if(c=='*' || c=='/' || c=='+' || c=='-' || c=='^')
	return true;
	
	else
	return false;
}
bool isOperand(char c)
{
	if(c>='a' && c<='z' || c>='A' || c<='Z')
	return true;
	
	else
	return true;
}
int getPriority(char c)
{
	if(c=='*' || c=='/' || c=='%')
	return 1;
	
	else if(c=='+' || c=='-')
	return 0;
	
	else if(c=='^')
	return 2;
	
	else
	return -1;
}
void process()
{
	char a[50],b[50],c[2];
	c[0]=pop2();
	c[1]='\0';
	strcpy(a,c);
	strcat(a,pop1());
	strcat(a,pop1());
	push1(a);
}
void infixToPrefix(char *s,int n)
{
	int i;
	char res[n];
	for(i=n-1;i>=0;i--)
	{
		if(s[i]=='(')
		push2(s[i]);
		
		else if(isOperator(s[i]))
		{
			while(!empty2() && getPriority(s[i])<getPriority(Top2()))
			{
				process();
			}
			push2(s[i]);
		}
		else if(isOperand(s[i]))
		{
			char a[2];
			a[0]=s[i];
			a[1]='\0';
			push1(a);
		}
		else if(s[i]==')')
		{
			while(!empty2() && Top2()!='(')
			{
				process();
			}
			pop2();
		}
		
	}
	while(!empty2())
	{
		process();
	}
	strcpy(res,pop1());
	printf("\nPrefix Expression: ");
	puts(res);
}
int main()
{
	char str[100];
	printf("Enter an infix string: ");
	gets(str);
	int n=strlen(str);
	infixToPrefix(str,n);
	return 0;
}