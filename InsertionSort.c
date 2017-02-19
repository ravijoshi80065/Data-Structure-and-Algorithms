//Insertion sort sample program,sorting in Ascending order
#include<stdio.h>
int main()
{
	int array[100];
	int n,i,j,temp;
	printf("\nEnter the number of elements in the array max 100:	");
	scanf("%d",&n);
	printf("\nEnter the elements of the array \n");
	for(i=0;i<n;i++)
	scanf("%d",&array[i]);
	printf("\nArray before sorting \n");
	for(i=0;i<n;i++)
	printf("%d	",array[i]);
	for(i=1;i<n;i++)
	{
		temp=array[i];
		j=i;
		while((array[j-1]>temp) && (j >= 1))
		{
			array[j]=array[j-1];
			j--;
		}
		array[j]=temp;
	}
	printf("\nArray after sorting \n");
	for(i=0;i<n;i++)
	printf("%d	",array[i]);
	}
