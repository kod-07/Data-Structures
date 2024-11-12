#include<stdlib.h>
#include<stdio.h>
struct node {
    int data;
    struct node * left;
    struct node * right;
    int height;
};
int getBalanceFactor(struct node *n){
    if (n==NULL)
    {
        return 0;
    }
    return n->height;
}
struct node * createNode(int key) 
{
    struct node * p = (struct node *)malloc(sizeof(struct node));
    p->data=key;
    p->left=NULL;
    p->right=NULL;
    p->height = 1;
    return p;
}
int getHeight(struct node *p){
    if (p==NULL)
    {
        return NULL;
    }
    return getHeight(p->left)-getHeight(p->height);
}

struct node * rightRotate(struct node * y){
    struct node * x =y->left;
    struct node * T2=x->right;
    x->right=y;
    y->left=T2;
    y->height=max(getHeight(y->left),getHeight(y->right))+1;
    x->height=max(getHeight(x->left),getHeight(x->right))+1;
    return x;
}
struct node * leftRotate(struct node * x){
    struct node * y=x->right;
    struct node * T2=y->left;

    y->left=x;
    x->right=T2;
    
    y->height=max(getHeight(y->left),getHeight(y->right))+1;
    x->height=max(getHeight(x->left),getHeight(x->right))+1;
    return y;
}
struct node * insert(struct node * Node ,int data){
    if (Node==NULL)
    {
        return createNode(data);
    }
    if (data<Node->data)
    {
        Node->left = insert(Node->left,data);
    }
    else if (data>Node->data)
    {
        Node->right =insert(Node->right,data);

    }
    Node->height = 1 + max(getHeight(Node->left),getHeight(Node->right));
    int bf = getBalanceFactor(Node);
    
}
int main(){
     
}