#include <stdio.h>
#include <stdlib.h>
//surajdiwate

typedef struct LinkNode
{
	int data;
	struct LinkNode * next;
	struct LinkNode * prev;
}LinkNode;

LinkNode * getLinkNode(int data)
{
	LinkNode * me = (LinkNode * ) malloc(sizeof(LinkNode));
	if (me == NULL)
	{
		return NULL;
	}
	me->data = data;
	me->next = NULL;
	me->prev = NULL;
	return me;
}
typedef struct DoublyLinkedList
{
	struct LinkNode * head;
	struct LinkNode * tail;
}DoublyLinkedList;

DoublyLinkedList * getDoublyLinkedList()
{
	DoublyLinkedList * me = 
      (DoublyLinkedList * ) malloc(sizeof(DoublyLinkedList));
	if (me == NULL)
	{ 
		return NULL;
	}
	me->head = NULL;
	me->tail = NULL;
	return me;
}

void insert(DoublyLinkedList * me, int value)
{
	LinkNode * node = getLinkNode(value);
	if ((me->head == NULL))
	{
		me->head = node;
		me->tail = node;
		return;
	}
	me->tail->next = node;
	node->prev = me->tail;
	me->tail = node;
}
void display(DoublyLinkedList * me)
{
	if ((me->head == NULL))
	{
		printf("Empty Linked List");
	}
	else
	{
		printf("\nLinked List Head to Tail :");
		
		LinkNode * temp = me->head;
	
		while (temp != NULL)
		{
			printf(" %d ", temp->data);
		
			temp = temp->next;
		}
		printf("\nLinked List Tail to Head :");
	
		temp = me->tail;
	
		while (temp != NULL)
		{
			printf(" %d ", temp->data);
	
			temp = temp->prev;
		}
		printf("\n");
	}
}

void swapData(LinkNode * first, LinkNode * second)
{
	int value = first->data;
	first->data = second->data;
	second->data = value;
}

void insertionSort(DoublyLinkedList * me)
{
	LinkNode * front = me->head;
	LinkNode * back = NULL;
	while (front != NULL)
	{
		back = front->next;
		
		while (back != NULL && 
               back->prev != NULL && 
               back->data < back->prev->data)
		{
			
			swapData(back, back->prev);
			
			back = back->prev;
		}
	
		front = front->next;
	}
}
int main()
{
	DoublyLinkedList * dll = getDoublyLinkedList();

	insert(dll, 25);
	insert(dll, 2);
	insert(dll, 6);
	insert(dll, 14);
	insert(dll, 12);
	insert(dll, 9);
	insert(dll, 16);
	insert(dll, 3);
	printf("\n Before Sort");
	display(dll);

	insertionSort(dll);
	printf("\n After Sort");
	display(dll);
}