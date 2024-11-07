#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node *left;
        struct node *right;
};
void preOrder(struct node *root){
    if (root!=NULL)
    {
        printf(" %d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct node *root){
    if (root!=NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d ",root->data);
    }
    
}
void inOrder(struct node *root){
    if (root!=NULL)
    {
        inOrder(root->left);
        printf(" %d ",root->data);
        inOrder(root->right);
    }    
}
struct node * create(int data){
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node ));
    p->left=NULL;
    p->right=NULL;
    p->data=data;
    return p;
}

int main(){
    struct node *root;
    root = (struct node *)malloc(sizeof(struct node ));
    root->left=NULL;
    root->right=NULL;
    root->data=100;
    struct node *p1,*p2,*p3,*p4;
    p1= create(20);
    p2 = create(30);
    p3= create(99);
    p4 = create(11);
    root->left=p1;
    root->right=p2;
    p1->left=p3;
    p1->right=p4;
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);
    return 0;
}