#include<stdio.h>
struct node
{
	int data;
	struct node * left;
	struct node * right;
};

struct node * insertTree(struct node * root,int d)
{
	if(!root)
		{
			struct node * newNode=(struct node * )malloc(sizeof(struct node));
			newNode->data=d;
			newNode->left=NULL;
			newNode->right=NULL;
			return newNode;
		}
	else
		{
			if(root->data > d)
				root->left=insertTree(root->left,d);
			else
				if(root->data < d)
					root->right=insertTree(root->right,d);
				else
				printf("Element already present...!!!!!!");
				return root; 
			}	
}

struct node * searchTree(struct node * root,int d)
{
	if(!root)
		return NULL;
	else
		{
			if(root->data==d)
			return root;
			else
			{
				if(root->data > d)
					return(searchTree(root->left,d));
				else
					return(searchTree(root->right,d));		
			}
		}	
}

struct node * minTree(struct node * root)
{
	if(!root)
	return NULL;
	else
	{
		if(root->left==NULL)
		return root;
		else
		return (minTree(root->left));
	}
}

struct node * maxTree(struct node * root)
{
	if(!root)
	return NULL;
	else
	{
		if(root->right==NULL)
		return root;
		else
		return (maxTree(root->right));
	}
}

struct node * deleteTree(struct node * root,int d)
{
	struct node * temp;
	struct node * max;
	if(!root)
	{
		printf("\nElement not present in the tree ");
		return NULL;
	}
	else
	{
		if(root->data > d)
		root->left=deleteTree(root->left,d);
		else if(root->data < d)
		root->right=deleteTree(root->right,d);
		else
		{
			if(root->left && root->right)
			{
				max=maxTree(root->left);
				root->data=max->data;
				root->left=deleteTree(root->left,max->data);
			}
			else
			{
				temp=root;
				if(root->left==NULL)	
					root=root->right;
				else if(root->right==NULL)
					root=root->left;
				printf("\nDeleting element %d",temp->data);
				free(temp);	
			}
		}
		return root;
	}
}

void showTree(struct node * root)
{
if(root)
	{
		showTree(root->left);
		printf("%d	",root->data);
		showTree(root->right);		
	}
}

struct node * deleteAllTree(struct node * root)
{
	if(root)
	{
		root->left=deleteAllTree(root->left);
		root->right=deleteAllTree(root->right);
		printf("\nDeleting element %d",root->data);
		free(root);
		return NULL;
	}
}
int main()
{
	int ch=10;
	int d;
	struct node * root=NULL;
	struct node * temp=NULL;
	while(ch!=0)
	{
		printf("\n\n1:Insert an element into tree ");
		printf("\n2:Search an element in tree ");
		printf("\n3:Find the minimum element in tree ");
		printf("\n4:Find the maximum element in tree ");
		printf("\n5:Delete an element from tree ");
		printf("\n6:Show all the elements");
		printf("\n7:Delete all the elements");
		printf("\n0:EXIT..........!!!!!");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the element to be inserted   ");
				scanf("%d",&d);
				root=insertTree(root,d);
				break;
			case 2:
				printf("\nEnter the element to be searched    ");
				scanf("%d",&d);
				temp=searchTree(root,d);
				if(temp==NULL)
					printf("\nElement not found");
				else
					printf("\nElement present in the list");	
				break;	
			case 3:
				temp=minTree(root);
				if(temp)
					printf("\nMinimum Element is %d"+temp->data);
				else
					printf("\nNo element is present in the tree");
				break;
			case 4:
				temp=maxTree(root);
				if(temp)
					printf("\nMaximum Element is %d",temp->data);
				else
					printf("\nNo element is present in the tree");
				break;
			case 5:
				printf("\nEnter the Element to be deleted ");
				scanf("%d",&d);
				root=deleteTree(root,d);
				break;
			case 6:
				if(root)
				{
					printf("\nDisplaying the elements present in the Tree \n");
					showTree(root);
				}
				else
					printf("\nNo elment present in the tree");			
				break;
			case 7:
				if(root)
				root=deleteAllTree(root);
				else
				printf("\nNo element to delete in tree.......!!!!!!");
				break;	
			case 0:
				printf("\nExiting................!!!!!");
				break;
			default:
				printf("\nEnter the correct option no ");
				break;										
		}
	}
	
}
