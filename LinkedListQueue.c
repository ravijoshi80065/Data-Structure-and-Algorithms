#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node* next;
};

struct linkedListQueue 
{
	struct node *front;
	struct node *rear;
	int capacity;
};

struct linkedListQueue * createQueue(int cap)
{
	struct linkedListQueue *newQueue=(struct linkedListQueue *)malloc(sizeof(struct linkedListQueue));
	if(!newQueue)
	printf("\nUnable to create a Queue........Returning......!!");
	else
	{
		newQueue->front=NULL;
		newQueue->rear=NULL;
		newQueue->capacity=cap;
	}
	return newQueue;
}

void insertRear(struct linkedListQueue * q,int n)
{
	int count;
	count=countQueue(q);
	if(count==q->capacity)
	printf("\nOVERFLOW.!!.Queue is full..CANNOT add more elements.!!");
	else
	{
		struct node * newNode=(struct node *)malloc(sizeof(struct node));
		if(!newNode)
		{
			printf("\nUnable to add more node...Memory Error.!!");
			return;
		}
		newNode->data=n;
		newNode->next=NULL;
		if(q->front==NULL)			//If NO element is present in the queue
		{
			q->front=newNode;
			q->rear=newNode;	
		}
		else
		{
			q->rear->next=newNode;
			q->rear=newNode;
		}
		printf("\nNew Element inserted into the Queue %d",q->rear->data);
	}
}

void removeFront(struct linkedListQueue * q) 
{
	int count;
	struct node *temp=NULL;
	count=countQueue(q);
	if(count==0)			//No element prenent in the Queue
	{
		printf("\nNo element is present in the queue.....Returning.!!");
	}
	else
	{
		if(q->front==q->rear)			//if only one element is present in the queue
		{
			temp=q->front;	
			q->front=q->rear=NULL;
		}
		else
		{
			temp=q->front;
			q->front=q->front->next;
		}
		printf("\nRemoving the element : %d",temp->data);
		free(temp);
	}
}

int countQueue(struct linkedListQueue * q)
{
	int count=0;
	struct node *temp=q->front;
	while(temp)
	{
		count++;
		temp=temp->next;
	}
	return count;
}

void showQueue(struct linkedListQueue * q)
{
	struct node *temp=q->front;
	if(!temp)
	printf("No data is present");
	else
	{
		while(temp)
		{
			printf("%d	",temp->data);
			temp=temp->next;
		}
	}
}

void deleteQueue(struct linkedListQueue * q)
{
	struct node *temp;
	if(q)
	{
		while(q->front)
		{
			temp=q->front;
			q->front=q->front->next;
			printf("\nDeleting element :%d",temp->data);
			free(temp);
		}
		printf("\nFreeing the queue memory");
		free(q);	
	}
}

int main()
{
	struct linkedListQueue * q1=NULL;
	int x,n,cap,ch=0;
	printf("\nEnter the capacity of Queue	");
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
				printf("\nShowing the content of the queue \n");
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
	
