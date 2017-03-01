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

int searchBinary(int * array,int n,int element)
{
	int mid,low=0;
	int high=n-1;
	while(low<=high)
	{
		mid=low+(high-low)/2;
		if(array[mid]==element)
		return mid;
		else
		{
		 if(array[mid]>=element)
		 high=mid-1;
		 else
		 low=mid+1;	
		}
	}
	return -1;
}
int main()
{
	int n,i,pos,element;
	int array[1000];
	printf("\nEnter the no of elements in the array ");
	scanf("%d",&n);
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
	pos=searchBinary(array,n,element);
	if(pos==-1)
	printf("\nElement not present is the Array....!!!!");
	else
	printf("\nElement is present at %d position",pos);
	return 0;
}
