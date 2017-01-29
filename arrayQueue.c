//Source code for circular queue
#include<stdio.h>
#include<stdlib.h>
struct arrayQueue
{
	int front,rear,capacity;
	int * array;
	};

struct arrayQueue * createQueue(int cap)
{
	struct arrayQueue *q=(struct arrayQueue *)malloc(sizeof(struct arrayQueue));
	if(!q)
	{
	printf("\nUnable to create a queue......!!!!!!memory Error returning.!!");
	return NULL;
	}
	else
	{
		q->front=-1;
		q->rear=-1;
		q->capacity=cap;
		q->array=(int *)malloc(q->capacity * sizeof(int));
		return q;
	}
}

void insertRear(struct arrayQueue *q,int n)
{
	if(q->rear==-1)			//if there is no element present currently
	{
		q->rear=q->front=0;
		q->array[q->rear]=n;
		printf("\nElement inserted into the Queue %d",q->array[q->rear]);
		printf("\nFront is %d",q->front);
		printf("\nRear is %d",q->rear);	
	}
	else
	{
		printf("\nThe no of elements pesent %d",countQueue(q));
		if(countQueue(q)==q->capacity)		//if queue already reached its capacity
		printf("\nQueue is already full,Unable to add any more data Returning..!!");
		else
		{		
			q->rear=((q->rear+1) % q->capacity);
			q->array[q->rear]=n;
		printf("\nElement inserted into the Queue %d",q->array[q->rear]);
		printf("\nFront is %d",q->front);
		printf("\nRear is %d",q->rear);	
		}
	}
}

void removeFront(struct arrayQueue *q)
{
	if(!countQueue(q))
	{
		printf("\nNo data present in the Queue....Returning..!!");
	}
	else
	{
		printf("\nRemoved data from queue : %d",q->array[q->front]);
		if(q->front==q->rear)
		q->front=q->rear=-1;
		else
		q->front=(q->front+1)%q->capacity;
		printf("\nFront is %d",q->front);
		printf("\nRear is %d",q->rear);
	}
}

int countQueue(struct arrayQueue *q)		//counting nuber of lements present in queue
{
	if(q->front==-1)
	return 0;
	else
	{
		
		if(q->rear >= q->front)
		return(q->rear - q->front + 1);
		else
		return(q->capacity - (q->front - q->rear) +1 );
		}
}

void showQueue(struct arrayQueue *q)
{
	int length=countQueue(q);
	int i=q->front;
	if(q->front==-1)
	printf("\nThe Queue is empty .... Returning.!!!");
	else
	{
		printf("\nShowing all the elements of Queue\n");
		while(length--)
		{
			printf("%d	",q->array[i]);
			i=(i+1)%q->capacity;
		}
		
	}
}

void deleteQueue(struct arrayQueue *q)
{
	if(q)
	{
		if(q->array)
		free(q->array);
		free(q);
	}
	printf("\nFreed the Memory allocated to queue");
}

int main()
{
	int x,n,cap,ch=0;
	struct arrayQueue *q1;
	printf("\nEnter the capacity of Queue ");
	scanf("%d",&cap);
	q1=createQueue(cap);
	while(ch!=5)
	{
		printf("\n\n1: Insert an element at the end in Queue");
		printf("\n2: Remove an element from the Queue ");
		printf("\n3: Show the number of elements present in the Queue ");
		printf("\n4: Show the content of the Queue");
		printf("\n5: EXIT..........!!");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the element to be inserted into the Queue	");
				scanf("%d",&n);
				insertRear(q1,n);
				break;
			case 2:
				printf("\nRemoving the element from Queue");
				removeFront(q1);
				break;
			case 3:
				printf("\nNo of elements present in the Queue	%d",countQueue(q1));
				break;
			case 4:
				printf("\nShowing the content of the queue ");
				showQueue(q1);
				break;	
			default:
				break;						
		}
	}
	printf("\nDeleting the complete Queue..........!!!!!!");
	deleteQueue(q1);
	q1=NULL;
}
	
	
	
	
