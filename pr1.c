#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#define MAX 100
int stack[MAX],queue[MAX],top=-1,front=-1,rear=-1;

void enqueue(int x,int n)
{
	if(rear>=n-1)
	return;
	
	if(front==-1 && rear==-1)
	front=0;
	
	queue[++rear]=x;
}
void dequeue()
{
	if(front==-1 && front>rear)
	return;
	
	if(front==rear)
	{
		front=rear=-1;
	}
	front++;
}
int Front()
{
	if(front==-1 || front>rear)
	return -1;
	
	return queue[front];
}
bool qEmpty()
{
	if(front==-1|| rear==-1 || front>rear)
	return true;
	
	else
	return false;
}
void display()
{
	for(int i=front;i<=rear;i++)
	printf("%d\n",queue[i]);
}
void push(int x)
{
	if(top>=MAX-1)
	return;
	
	stack[++top]=x;
}
void pop()
{
	if(top==-1)
	return;
	
	top--;
}
int Top()
{
	if(top==-1)
	return -1;
	
	return stack[top];
}
bool sEmpty()
{
	if(top==-1)
	return true;
	
	else
	return false;
}
bool checkSorted(int n)
{

	int expected=1;
	int fnt;
	
	while(!qEmpty())
	{
		
		fnt=Front();
	    dequeue();
	    
	    if(fnt==expected)
	    {
		 
	      expected++;
         }
         
        else{
    	      if(sEmpty())
    	      push(fnt);
	         	
               else if(!sEmpty() && fnt>Top())
               {
			     
    	         return false;
              }
               else
               push(fnt);
            }
      
    }
    while(!sEmpty() && Top()==expected)
        {
        	pop();
           expected++;
		}
    if(expected-1==n && sEmpty())
     return true;
    
    return false;
}
int main()
{
	int n;
	printf("Enter size of the queue: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		printf("Enter a value for given queue:");
		scanf("%d",&x);
		enqueue(x,n);
	}
    
	   bool ans=checkSorted(n);
	 
    	if(ans)
    	printf("\nGiven queue can be sorted\n");
    	
    	else
    	printf("\nGiven queue cannot be sorted\n");
	return 0;
}