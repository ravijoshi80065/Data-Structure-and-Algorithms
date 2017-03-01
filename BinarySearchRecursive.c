#include<stdio.h>
void sortArray(int * array,int n)
{
	int i,j,temp,min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(array[j] < array[min])
			min=j;
		}
		temp=array[i];
		array[i]=array[min];
		array[min]=temp;
	}
	printf("\nSorted Array\n");
	for(i=0;i<n;i++)
	printf("%d	",array[i]);
}

int searchBinary(int * array,int low,int high,int element)
{
	int mid;
	while(low<=high)
	{
		mid=low+(high-low)/2;
		if(array[mid]==element)
		return mid;
		else
		{
		 if(array[mid]>=element)
		 return (searchBinary(array,low,mid-1,element));
		 else
		 return (searchBinary(array,mid+1,high,element));
		}
	}
	return -1;
}

int main()
{
	int n,i,pos,element,low,high;
	int array[1000];
	printf("\nEnter the no of elements in the array ");
	scanf("%d",&n);
	low=0;
	high=n-1;
	printf("\nEnter the elements of the array \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	printf("\nArray as entered\n");
	for(i=0;i<n;i++)
	printf("%d	",array[i]);
	sortArray(array,n);
	printf("\nEntered the element to be searched		");
	scanf("%d",&element);
	pos=searchBinary(array,low,high,element);
	if(pos==-1)
	printf("\nElement not present is the Array....!!!!");
	else
	printf("\nElement is present at %d position",pos);
	return 0;
}
