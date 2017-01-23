#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
int countNodes(struct node *start)	//func to count number of rows present in circular linked list
{
	struct node * temp=start;
	int count=0;
	while(temp)
	{
		count++;
		temp=temp->next;
		if(temp==start)		//if we have reached to the starting node while traversing				
		temp=NULL;
	}
	return count;
}

void insertLinkedList(struct node **start,int x,int index)
{
	struct node *newNode,*pos,*temp;
	int count,i;
	newNode=(struct node *)malloc(sizeof(struct node));
	if(!newNode)
	{
		printf("\nCannot create new node returning.......");
		return;
	}
	else
	{
		newNode->data=x;
		newNode->next=newNode;
	}
	count=countNodes(*start);
	if(index > (count+1))
	{
		printf("\nNumber of nodes present %d",count);
		printf("\ntotal no of nodes less than index-1,adding at the end");
		index=count+1;
	}
	temp=*start;
	if(index==1)
	{
		if(temp)
		{
			while(temp->next!=(*start))	//traversing till the last node,the one pointing to start node
			temp=temp->next;
			temp->next=newNode;
			newNode->next=(*start);
			}
		(*start)=newNode;	
	}
	else
	{
		//Traversing till the node,next to which a new node is to be inserted
		for(i=2;i<index;i++)
		temp=temp->next;
		newNode->next=temp->next;
		temp->next=newNode;
		}
}

void delNodeIndex(struct node **start,int index)
{	

	struct node *pos,*temp;
	int i;
	int count=countNodes(*start);
	if(count<index)	//return if index no out of range
	{
		printf("\nno of nodes are fewer than the index CAN NOT delete......returning.....!!!!!");
		return;
	}
	if(index==1)
	{
		temp=*start;
		if(count==1)		//if only one node is present,just nullify the start pointer
		{
			*start=NULL;
			}
		else
		{
			pos=*start;
			while(pos->next!=(*start))		//locating the last node,the node pointing to starting node
			pos=pos->next;
			pos->next=(*start)->next;	//pointing to the new starting point
			(*start)=(*start)->next;		
			}
		printf("\nDeleting the first node with data %d",temp->data);	
		free(temp);
	}
	else
	{
		pos=(*start);
		for(i=2;i<index;i++)
		pos=pos->next;
		temp=pos->next;
		pos->next=pos->next->next;
		printf("\nDeleting some intermidiate node with data %d",temp->data);	
		free(temp);
		}
}

void delCompleteList(struct node *start)
 {
 	struct node *delNode,*firstNode;
 	firstNode=start;
 	if(!start)	//if list is empty
 	{
 		printf("\nThere is nothing to delete..Returning....!!");
 		return;
	 }
	 while(start)
	 {		
	 	delNode=start;
		start=start->next;
		printf("\nDeleting the node with data %d",delNode->data);
		free(delNode);
		if(start==firstNode)		//if reached to the final node,the node pointing to the first node
		start=NULL;	 	
	 }
 }


 void showLinkedList(struct node *start)
 {
 	struct node *firstNode=start;
 	if(!start)
 	{
 		printf("\nList is empty..........!!!!!!!!!");
 		return;
 		}
 	while(start)
 	{
	 printf("%d  ",start->data);
	 start=start->next;	
	 if(start==firstNode)
	 start=NULL;
		}
	 }
int main()
{
	struct node *start=NULL;
	int index,x,count,ch=0;
	while(ch!=6)
	{
	printf("\n\n1:Insert somewhere in Circular Linked List ");
	printf("\n2:Show complete Circular Linked List");
	printf("\n3:Delete a node ");
	printf("\n4:Delete complete Circular Linked List");
	printf("\n5:Show the number of nodes present in Circular Linked List ");
	printf("\n6:Exit.....					" );
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("\nEnter the position you want to enter at,if position greater than total no of nodes it will be aded at end : ");
			scanf("%d",&index);
			printf("\nEnter the data 	");
			scanf("%d",&x);
			insertLinkedList(&start,x,index);
			break;
		case 2:	
			printf("showing complete list ");
			showLinkedList(start);
			break;
		case 3:
			printf("\nEnter the index no of node you want to delete  ");
			scanf("%d",&index);
			delNodeIndex(&start,index);
			break;
		case 4:
			printf("\nDeleting the complete linked list ");
			delCompleteList(start);
			start=NULL;
			break;			
		case 5:
			count=countNodes(start);
			printf("\nTotal no of nodes present in linked list	%d",count);
			break;
		default:
			break;
	}
}
}
