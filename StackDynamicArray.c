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
	{
	printf("\nOVERFLOW........Cannot push more into the stack with this capacity...doubling capacity.......!!!!!!!!");
	//If memory is not enough to add new element,calling a function to reallocate the stack with double capacity
	doubleStackCapacity(s1);	
		}
		s1->top++;
		s1->array[s1->top]=x;
		printf("\n%d Added to the stack",x);
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

void doubleStackCapacity(struct ArrayStack *s1)
{
	s1->capacity=s1->capacity*2;
	s1->array=realloc(s1->array,s1->capacity);		//reallocating after doubling the capacity
	printf("\nDoubled the stack capacity to %d",s1->capacity);
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
	struct ArrayStack *stack1=createStack(1);
	printf("\nThe top of the stack is %d",stack1->top);
	while(ch!=6)
	{
		printf("\n\n1: PUSH");
		printf("\n2: POP");
		printf("\n3: no of elements present ");
		printf("\n4: Show all the element present in the stack 				");
		printf("\n5: Show current capacity of stack");
		printf("\n6: EXIT......!!				");
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
			case 5:
				printf("\nCurrent capacity of stack is %d",stack1->capacity);	
				break;
			default:
				break;	
		}
	}
	//Deleting the complete Stack before exting,Freeing dynamically allocated memory
	printf("\nDeleting the complete stack");
	delArrayStack(stack1);
	stack1=NULL;
}
