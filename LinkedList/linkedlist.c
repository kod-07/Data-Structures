#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * next;
};
struct node * insertatfirst(struct node *head,int data){
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	ptr->next = head;
	ptr->data =data;
	return ptr;
}

struct node * insertlast(struct node *head,int data)
{
	struct node * ptr = (struct node *)malloc(sizeof(struct node));
	struct node * p = head;
	while(p->next!=NULL)
	{
		p = p->next;
	}
	p->next = ptr;
	ptr -> data = data;
	ptr -> next = NULL;
	return head;
}

struct node * insertat(struct node *head ,int data, int index)
{
	struct node * ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=data;
	struct node * p = head;
	for(int i=0;index-1;i++)
	{
		p = p->next;
	}
	ptr->next = p->next;
	p->next =ptr;
	return head;
}


void traversal(struct node *ptr)
{
	while(ptr!=NULL)
	{
		printf("Element: %d \n",ptr->data);
		ptr = ptr->next;
	}
}
int main()
{
	struct node *head;
	struct node *second;
	struct node *third;
	struct node *fourth;
	head = (struct node *)malloc(sizeof(struct node));
	second =(struct node *)malloc(sizeof(struct node));
	third =(struct node *)malloc(sizeof(struct node));
	fourth =(struct node *)malloc(sizeof(struct node));
	head->data=10;
	head->next=second;
	second->data=20;
	third->data=30;
	fourth->data=40;
	second->next=third;
	third->next=fourth;
	fourth->next=NULL;

	printf("Linked list before insertion: \n");
	traversal(head);

	printf("\nLinked list after insertion at first node \n");

	head = insertatfirst(head,56);
	traversal(head);

	printf("\nLinked list after insertion at indexed node \n");


	printf("\n");

	head = insertat(head,100,1);
	traversal(head);
	printf("\nLinked list after insertion of node at last");
	head = insertlast(head,10);
	traversal(head);
	return 0;
}
