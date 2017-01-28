#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};

void pushStack(struct node **top,int x)
{
	struct node *newNode=(struct node *)malloc(sizeof(struct node));
	if(!newNode)
	{
		printf("\nUnable to create a node.........Memory Error.....!!!! RETURNING.!");
		return;
	}
	newNode->data=x;
	newNode->next=*top;
	*top=newNode;
}

void popStack(int **top)
{
	struct node *head=*top;
	if(!head)
		printf("\nUNDERFLOW......!!! No element present in the stack.........!");
	else
	{
		printf("\nThe POPed element is %d",head->data);
		*top=head->next;
		free(head);
	}
}

int countNodes(struct node *head)
{
	int count=0;
	while(head)
	{
		count++;
		head=head->next;
	}
	return count;
}

void showStack(struct node *head)
{
	if(!head)
	printf("\nNo element to show....!!!! Stack is empty......!\n");
	else
	{
		while(head)
		{
			printf("%d	",head->data);
			head=head->next;
		}
	}
}

void delArrayStack(struct node *head)
{
	struct node *temp;
	while(head)
	{
		temp=head;
		printf("\nDeleting %d",temp->data);
		head=head->next;
		free(temp);		
	}
}

int main()
{

	int x,ch=0;
	struct node *top=NULL;
	while(ch!=5)
	{
		printf("\n\n1: PUSH");
		printf("\n2: POP");
		printf("\n3: no of elements present ");
		printf("\n4: Show all the element present in the stack 				");
		printf("\n5: EXIT......!!				");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the element to be PUSHed into stack		");
				scanf("%d",&x);
				pushStack(&top,x);
				break;
			case 2:
				printf("\nPoping the element off the stack");
				popStack(&top);
				break;
			case 3:
				printf("\nNo of elements present in the stack are %d",countNodes(top));	
				break;
			case 4:
				printf("\nShowing the elements present in the stack\n");
				showStack(top);
				break;
			default:
				break;	
		}
	}
	printf("\nDeleting the complete stack");
	delArrayStack(top);
	top=NULL;		
}
