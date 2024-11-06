#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * next;
};
struct node * deletingparticularnode(struct node *head,int data){
	struct node *ptr = head;
	struct node *ptr1= head->next;
	while (ptr1->data!=data)
	{
		ptr1=ptr1->next;
		ptr=ptr->next;
	}
	ptr->next=ptr1->next;
	free(ptr1);
	return head;
}

struct node * deletingfirst(struct node *head){
	struct node * ptr1 = head->next;
	do
	{
		ptr1=ptr1->next;
	} while (ptr1->next!=head);
	ptr1->next=head->next;
	free(head);
	return (ptr1->next);
}
struct node * deletinglast(struct node *head){
	struct node * ptr = head;
	struct node * ptr1 = head->next;
	do
	{
		ptr1=ptr1->next;
		ptr = ptr->next;
	} while (ptr1->next!=head);
	ptr->next=head;
	free(ptr1);
	return head;
}
struct node * deletingatindex(struct node *head,int index){
	struct node * ptr=head->next;
	struct node * ptr1=head;
	for (int i = 0; i < index-1; i++)
	{
		ptr=ptr->next;
		ptr1=ptr1->next;
	}
	ptr1->next=ptr->next;
	free(ptr);
	return head;
}
void traversal(struct node *head)
{
	struct node *ptr=head;
	do
	{
		printf("Element: %d \n",ptr->data);
		ptr = ptr->next;
	}while(ptr->next!=head);
	printf("Element: %d \n",ptr->data);
}
struct node * insertatfirst(struct node *head,int data){

	struct node * nod = (struct node *)malloc(sizeof(struct node));
	nod->data=data;
	nod->next=head;
	struct node * ptr = head;
	do
	{
		ptr=ptr->next;
	} while (ptr->next!=head);
	ptr->next=nod;
	return nod;
}
struct node * insertatindex(struct node *head,int data,int index){
	struct node * ptr=head;
	struct node * nod = (struct node *)malloc(sizeof(struct node));
	nod->data=data;
	for (int i = 0; i < index-1; i++)
	{
		ptr=ptr->next;
	}
	nod->next=ptr->next;
	ptr->next=nod;
	return head;
}
struct node * insertatlast(struct node *head,int data){

	struct node * nod = (struct node *)malloc(sizeof(struct node));
	nod->data=data;
	nod->next=head;
	struct node * ptr = head;
	do
	{
		ptr=ptr->next;
	} while (ptr->next!=head);
	ptr->next=nod;
	return head;
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
	fourth->next=head;

	printf("Linked list before insertion: \n");
	traversal(head);
	
	printf("\nNode add at first place \n");
	head = insertatfirst(head,50);
	traversal(head);
	
	printf("\nNode inserting at index \n");
	head = insertatindex(head,99,2);
	traversal(head);
	printf("\nNode add at last place \n");
	head = insertatlast(head,32);
	traversal(head);
	printf("\nDeleting last node \n");
	head = deletinglast(head);
	traversal(head);
	printf("\nDeleting index node \n");
	head = deletingatindex(head,3);
	traversal(head);
	printf("\nDeleting head node \n");
	head = deletingfirst(head);
	traversal(head);
	printf("\nDeleting particular head node \n");
	head = deletingparticularnode(head,99);
	traversal(head);
	return 0;
}
