#include<stdio.h>
#include<stdlib.h>
#define MAX 40

//Diwate Suraj Ramrao

int isEmpty(int top, int stack_arr[]);
void PFactors( int num);
void push(int x, int *top, int stack_arr[]);
int pop(int *top, int stack_arr[]);
int main()
{
        int num;
        printf("Enter an integer : ");
        scanf("%d",&num);
        printf("Prime factors are : ");
        PFactors(num);
        return 0;
}
void push(int x, int *top, int stack_arr[])
{
        if(*top == (MAX-1))
                printf("Stack Overflow\n");
        else
        {
                *top=*top+1;
                stack_arr[*top] = x;
        }
}

void PFactors( int num)
{
        int stack[MAX], top=-1, i;
        for(i=2; num!=1; i++)
                while(num%i == 0)
                {
                        push(i, &top, stack);
                        num = num/i;
                }
        while(top!=-1)
        {
                printf("%d ",stack[top]);
                pop(&top, stack);
        }
        printf("\n");
 }

int pop(int *top, int stack_arr[])
{
        int x;
        if(*top == -1)
        {
                printf("Stack Underflow\n");
                exit(1);
        }
        else
        {
                x = stack_arr[*top];
                *top=*top-1;
        }
        return x;
}
