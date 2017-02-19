//Bubble sort sample program sorting in Ascending order
#include<stdio.h>
int main()
{
	int array[100];
	int n,i,j,x;
	printf("\nEnter the number of elements in the array max 100:	");
	scanf("%d",&n);
	printf("\nEnter the elements of the array \n");
	for(i=0;i<n;i++)
	scanf("%d",&array[i]);
	printf("\nArray before sorting \n");
	for(i=0;i<n;i++)
	printf("%d	",array[i]);
	for(i=0;i<n-1;i++)
	for(j=0;j<n-1-i;j++)
	{
		if(array[j]>array[j+1])
		{
			x=array[j];
			array[j]=array[j+1];
			array[j+1]=x;
		}
	}
	printf("\nArray after sorting \n");
	for(i=0;i<n;i++)
	printf("%d	",array[i]);
	}
