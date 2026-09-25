#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* createnode(int data)
{
 struct node*newnode=(struct node*)malloc(sizeof(struct node));
 newnode->data=data;
 newnode->left=NULL;
 newnode->right=NULL;
 return newnode;
}
struct node*insert(struct node*root,int data)
{
 if(root==NULL)
        return createnode(data);
 else if(data<root->data)
    root->left=insert(root->left,data);
 else if(data>root->data)
    root->right=insert(root->right,data);
 return root;
}
void preorder(struct node*root)
{
    if(root==NULL)
        return;
    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node*root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}
void postorder(struct node*root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->data);
}
int main()
{
    int n,i,data;
    struct node*root=NULL;
    printf("Enter the no. of element to insert:");
    scanf("%d",&n);
    printf("Enter the %d values:",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&data);
        root=insert(root,data);
    }
    printf("\n___BST Traversal___\n");
    printf("Preorder Traversal:");
    preorder(root);
    printf("\nInorder Traversal:");
    inorder(root);
    printf("\nPostorder Traversal:");
    postorder(root);
}
