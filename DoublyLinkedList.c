#include<stdio.h>
#include<stdlib.h>
struct node		//node contains pointers for previouus nad next nodes
{
	int data;
	struct node *next;
	struct node *prev;
};


int countNodes(struct node *start)	//func to count number of rows present in linked list
{
	int count=0;
	while(start)
	{
		count++;
		start=start->next;
	}
	return count;
}

void insertDoubLinkedList(struct node** start,int x,int index)
{
int count,i;
struct node *newNode,*pos;
newNode=(struct node *)malloc(sizeof(struct node));
 if(!newNode)
 { 
	printf("\nCannot allocate memory for new node...Returning........!");
	 }  
else	//initializing newly created node
{
	newNode->data=x;
	newNode->next=NULL;
	newNode->prev=NULL;
	}	
count=countNodes(*start);
if((count+1)<index)
{
	printf("\nNo of nodes in the linked list is %d ",count);
	printf("\nNo of nodes+1 is less than the index no hence adding at the end of linked list");
	index=count+1;
}
if(index==1)	//If node is inserted at the begining
{
	//printf("\n**Adding at start");	
	if(*start)
	(*start)->prev=newNode;
	newNode->next=(*start);
	(*start)=newNode;
}
else			//if node is inserted somewhere other than begining
{
	pos=*start;
	for(i=2;i<index;i++)
	{
		pos=pos->next;
		}
	//Adding new Node
	if(pos->next)		//Checking if new there in any node present after pos
	pos->next->prev=newNode;	//if present,Update its prev link
	newNode->next=pos->next;
	pos->next=newNode;
	newNode->prev=pos;	
	}
}

void showLinkedListHead(struct node *start)
{
	if(!start)	//if list is empty
	{
		printf("\nThe linked list is empty.........returning...!!");
	}
	else
	{
		while(start)
		{
		printf("%d	",start->data);
		start=start->next;
	}
	}
}

void showLinkedListTail(struct node *start)
{
	struct node *last;
	if(!start)	//if list is empty
	{
		printf("\nThe linked list is empty.........returning...!!");
	}
	else
	{
		while(start->next)	//Locating the last node in linked list		
		start=start->next;
	}
	last=start;
	//Now traversing from end to start
	while(last)
	{
		printf("%d	",last->data);
		last=last->prev;
	}
}

void delNodeIndex(struct node **start,int index)
{
	struct node *temp,*pos;
	int i;
	int count=countNodes(*start);
	if(count<index)		//if linked list is empty or specified index number not present on the list
	{
		printf("\nIndex no. not present in the linked list....hence can't perform delete.....returning........!!!");
		return;
	}
	if(index==1)
	{
		temp=*start;
		*start=(*start)->next;
		if(*start)		//if any node is present after the deleted node
		(*start)->prev=NULL;
		printf("\nDeleting the node with data %d",temp->data);
		free(temp);
	}
	else
	{
		pos=*start;
		for(i=2;i<index;i++)	//Reaching till the node before the node to be deleted
		{
			pos=pos->next;
			}
		temp=pos->next;		//deleting the node
		pos->next=pos->next->next;
		if(pos->next)		//if a node is present after the node to be deleted
		pos->next->prev=pos;	
		
		printf("\nDeleting the node with data %d",temp->data);
		free(temp);		
	}
}
void delCompleteList(struct node *start)
{
	struct node * temp;
	if(!start)		//list is empty
	{
		printf("There is no element to delete.......Returning......!!!!");
	}
	else
	{
		while(start)
		{
			temp=start;
			start=start->next;
			printf("\nDeleting the node with data %d",temp->data);
			free(temp);
		}
	}
}

int main()
{
struct node *start=NULL;
	int index,x,count,ch=0;
	while(ch!=7)
	{
	printf("\n\n1:Insert somewhere in doubly Linked List ");
	printf("\n2:Show complete Linked List HEAD TO TAIL");
	printf("\n3:Show complete Linked List TAIL TO HEAD");
	printf("\n4:Delete a node ");
	printf("\n5:Delete complete Linked List");
	printf("\n6:Show the number of nodes present ");
	printf("\n7:Exit.....					" );
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("\nEnter the position you want to enter at,if position greater than total no of nodes it will be aded at end : ");
			scanf("%d",&index);
			printf("\nEnter the data 	");
			scanf("%d",&x);
			insertDoubLinkedList(&start,x,index);
			break;
		case 2:	
			printf("\nShowing complete list HEAD TO TAIL\n");
			showLinkedListHead(start);
			break;
		case 3:
			printf("\nShowing complete list TAIL TO HEAD \n");
			showLinkedListTail(start);
			break;
		case 4:
			printf("\nEnter the index no of node you want to delete  ");
			scanf("%d",&index);
			delNodeIndex(&start,index);
			break;
		case 5:
			printf("\nDeleting the complete linked list ");
			delCompleteList(start);
			start=NULL;
			break;			
		case 6:
			count=countNodes(start);
			printf("\nTotal no of nodes present in linked list	%d",count);
			break;
		default:
			break;
	}
}	
}
