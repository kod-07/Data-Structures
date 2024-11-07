#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node *left;
        struct node *right;
};
void insert(struct node *root,int data){    
    struct node *pre;
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data=data;
    p->left=NULL;
    p->right=NULL;
    while (root!=NULL)
    {
        if (root->data==data)
        {
            return ;
        }
        if (root->data>data)
        {
            pre=root;
            root=root->left;

        }
        else{
            pre =root;
            root=root->right;
        }
        
    }
    if (data<pre->data)
    {
        pre->left=p;
    }
    else{
        pre->right=p;
    }
    
   
    
}
struct node * searchitr(struct node *root,int data){
    while (root!=NULL)
    {
        if (root->data==data)
        {
            return root;
        }
        if (root->data>data)
        {
            root=root->left;
        }
        else{
            root=root->right;
        }
        
    }
    return NULL;
    
    
}
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
struct node * search(struct node *root,int data){
    if (root==NULL) 
    {
        return NULL;
    }
    if (root->data>data)
    {
        return search(root->left,data);
    }
    if (root->data<data)
    {
        return search(root->right,data);
    }
    if (root->data==data)
    {
        return root;
    }
    
}
int isBST(struct node *root){
    static struct node *pre=NULL;
    if (root!=NULL)
    {
        if(!isBST(root->left)){
            return 0;
        }
        if (pre!=NULL && root->data<=pre->data){
            return 0;
        }
        pre = root;
        return isBST(root->right);
    }    
    else{
        return 1;
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
    root->data=50;
    struct node *p1,*p2,*p3,*p4;
    p1= create(20);
    p2 = create(30);
    p3= create(99);
    p4 = create(11);

    root->left=p1;
    root->right=p3;
    p1->left=p4;
    p1->right=p2;
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    printf("%d",isBST(root));
    printf("\n");
    printf("%d",search(root,0));
    printf("\n");
    printf("%d",searchitr(root,30));
    printf("\n");
    insert(root,80);
    insert(root,0);
    insert(root,99);
    inOrder(root);
    return 0;
}