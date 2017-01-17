 #include<stdio.h>
 #include<conio.h>
 #include<stdlib.h>
 struct node
 {
    int data;
    struct node* next;
 };
 void insertLinkedList(struct node **start,int d)
 {
 	struct node *newNode,*last;
 	newNode=(struct node *)malloc(sizeof(struct node));
 	if(!newNode)	//if unable to allocate new node								
 	{
 		printf("\nMemory error Exiting!!!!!!!!");
 		return;
	 }
	 else	//initializing new nude
	 {
	 	newNode->data=d;
	 	newNode->next=NULL;
	 }
 	if(!(*start))	//if first node
 	{
 		*start=newNode;
	 }
	 else	//adding new node at the end of linked list
	 {
	 	last=*start;
	 	while(last->next)	//traversing until last node
	 	last=last->next;
	 	last->next=newNode;
	 }
 }
 
 void showLinkedList(struct node *start)
 {
 	
 	if(!start)
 	{
 		printf("\nList is empty..........!!!!!!!!!");
 		return;
 		}
 	while(start)
 	{
	 printf("%d  ",start->data);
	 start=start->next;	
		}
	 }
	 
 void delLinkedList(struct node *start)
 {
 	struct node *delNode;
 	if(!start)	//if list is empty
 	{
 		printf("\nThere is nothing to delete..Returning....!!");
 		return;
	 }
	 while(start)
	 {		
	 	delNode=start;
		start=start->next;
		free(delNode);	 	
	 }
 }

 int main()
 {
 	int d,ch=0;
 	struct node * start=NULL;
 	while(ch!=4)
 	{
 	printf("\n1 :Insert into linked list");
 	printf("\n2 :Show content of Linked List");
 	printf("\n3 :Delete whole linked List");
 	printf("\n4 :Exit  		");
 	scanf("%d",&ch);
 	switch(ch)
 	{
 		case 1:
 			printf("\nEnter the data to be inserted ");
 			scanf("%d",&d);
 			insertLinkedList(&start,d);
 			break;
 		case 2:
 			printf("\nShowing the data in Linked List ");
			showLinkedList(start);
			break;
		case 3:
			printf("\nDeleting the Linked List");
			delLinkedList(start);
			start=NULL;
			break;
		case 4:
			printf("\nEXITING..................!!!!!!!!!!!!!!!!!!");
			break;					
	 }
 }
 return 0;
}
