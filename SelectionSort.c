//Selection sort sample program,sorting in Ascending order
#include<stdio.h>
int main()
{
	int array[100];
	int n,i,j,min,temp;
	printf("\nEnter the number of elements in the array max 100:	");
	scanf("%d",&n);
	printf("\nEnter the elements of the array \n");
	for(i=0;i<n;i++)
	scanf("%d",&array[i]);
	printf("\nArray before sorting \n");
	for(i=0;i<n;i++)
	printf("%d	",array[i]);
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(array[j] < array[min])
			min=j;
		}
		temp=array[min];
		array[min]=array[i];
		array[i]=temp;
	}
		printf("\nArray after sorting \n");
	for(i=0;i<n;i++)
	printf("%d	",array[i]);
	}
