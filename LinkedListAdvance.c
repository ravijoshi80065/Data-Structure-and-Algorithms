#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
int countNodes(struct node *start)	//func to count number f rows present in linked list
{
	int count=0;
	while(start)
	{
		count++;
		start=start->next;
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
		newNode->next=NULL;
	}
	count=countNodes(*start);
	if(index > (count+1))
	{
		printf("\nNumber of nodes present %d",count);
		printf("\ntotal no of nodes less than index-1,adding at the end");
		index=count+1;
	}
	if(index==1)
	{
		newNode->next=*start;
		*start=newNode;
	}
	else
	{
		pos=*start;
		for(i=2;i<index;i++)	//travesing till the correct position		
		pos=pos->next;
		//adding new node at proper position
		temp=pos->next;
		pos->next=newNode;
		newNode->next=temp;
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
		*start=(*start)->next;
		printf("\ndeleting the data %d",temp->data);
		free(temp);
	}
	else
	{
		pos=*start;
		for(i=2;i<index;i++)	//locating the node previous to node to be deleted
		pos=pos->next;
		//deleting the node
		temp=pos->next;
		pos->next=pos->next->next;
		printf("\ndeleting the data %d",temp->data);
		free(temp);
		}
}

void delCompleteList(struct node *start)
 {
 	struct node *delNode;
 	if(!start)	//if list is empty
 	{
 		printf("\nThere is nothing to delete..Returning....!!");
 		return;
	 }
	 while(start)
	 {		
	 	delNode=start;
		start=start->next;
		free(delNode);	 	
	 }
 }


 void showLinkedList(struct node *start)
 {
 	
 	if(!start)
 	{
 		printf("\nList is empty..........!!!!!!!!!");
 		return;
 		}
 	while(start)
 	{
	 printf("%d  ",start->data);
	 start=start->next;	
		}
	 }
int main()
{
	struct node *start=NULL;
	int index,x,count,ch=0;
	while(ch!=6)
	{
	printf("\n\n1:Insert somewhere in Linked List ");
	printf("\n2:Show complete Linked List");
	printf("\n3:Delete a node ");
	printf("\n4:Delete complete Linked List");
	printf("\n5:Show the number of nodes present ");
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
