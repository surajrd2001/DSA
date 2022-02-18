#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int n,cQueue[MAX],item,front=-1,rear=-1,choice;

void enqueue()
{
   if((rear+1)%n==front)
   {
   	printf("Circular queue is overflow\n");
   	return;
   }
   else if(front==-1 && rear==-1)
   {
   	front=0;
   	rear=0;
   }
   else{
   	rear=(rear+1)%n;
   }
   printf("Enter a value: ");
   scanf("%d",&item);
   cQueue[rear]=item;
   printf("\nValue inserted\n");
}
int dequeue()
{
	if(front==-1 && rear==-1)
	{
	
		return -1;
	}
	int item=cQueue[front];
	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else
	{
		front=(front+1)%n;
	}
	return item;
}
void display()
{
	if(front==-1 && rear==-1)
	{
		printf("Circular queue is empty\n");
		return;
	}
	else{
		if(front<=rear)
		{
			for(int i=front;i<=rear;i++)
			printf("%d\n",cQueue[i]);
		}
		else{
			for(int i=front;i<n;i++)
			printf("%d\n",cQueue[i]);
			
			for(int i=0;i<=rear;i++)
			printf("%d\n",cQueue[i]);
		}
	}
}
int main()
{
	printf("Enter a size of queue:");
	scanf("%d",&n);
	
	while(choice!=4)
	{
		printf("\n1.Insert\n2.Delete\n3.Display\n4.exit\n");
		printf("Enter a choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				enqueue();
				break;
		    case 2:
		    	{
			
		    	int x=dequeue();
		    	if(x==-1)
		    	printf("Circular queue is empty\n");
		    	
		    	else
		    	printf("\nDelelted value:%d\n",x);
		    	break;
		    }
		    case 3:
		    	display();
		    	break;
			case 4:
				exit(0);
				break;
			default:
				printf("Enter a valid choice\n");
		}
	}

	
	return 0;
}