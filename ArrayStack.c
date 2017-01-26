#include<stdio.h>
#include<stdlib.h>
struct ArrayStack {
	int top,capacity;
	int *array;
};

struct ArrayStack *createStack(int cap)
{
	struct ArrayStack *s1=(struct ArrayStack *)malloc(sizeof(struct ArrayStack));
	s1->capacity=cap;
	s1->top=-1;
	s1->array=(int *)malloc(s1->capacity * sizeof(struct ArrayStack));
	return s1;
}

void pushStack(struct ArrayStack *s1,int x)
{
	if(s1->top==(s1->capacity-1))
	printf("\nOVERFLOW........Cannot push more into the stack........Returning........!!!!!!!!");
	else
	{
		s1->top++;
		s1->array[s1->top]=x;
		printf("\n%d Added to the stack",x);
	}
}

void popStack(struct ArrayStack *s1)
{
	if(s1->top==-1)
	printf("\nUNDERFLOW...........!!!!! No element present in the stack.........returning....!!");
	else
	{
		printf("\nThe POPed element is %d",s1->array[s1->top]);
		s1->top--;
	}
 } 

void showStack(struct ArrayStack *s1)
{
	int i=s1->top;
	printf("\nShowing from TOP to BOTTOM\n");
	while(i!=-1)
	{
		printf("%d	",s1->array[i]);
		i--;
	}
}

void delArrayStack(struct ArrayStack *s1)
{
	if(s1)
	{
		if(s1->array)
		free(s1->array);
		free(s1);
	}
	printf("\nfreed all the memory associated with stack......!!!!!!!1");
}

int main()
{
	int x,ch=0;
	struct ArrayStack *stack1=createStack(10);
	printf("\nThe top of the stack is %d",stack1->top);
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
				pushStack(stack1,x);
				break;
			case 2:
				printf("\nPoping the element off the stack");
				popStack(stack1);
				break;
			case 3:
				printf("\nNo of elements present in the stack are %d",stack1->top+1);	
				break;
			case 4:
				printf("\nShowing the elements present in the stack");
				showStack(stack1);
				break;
			default:
				break;	
		}
	}
	printf("\nDeleting the complete stack");
	delArrayStack(stack1);
	stack1=NULL;		
}
