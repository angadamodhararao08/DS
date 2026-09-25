#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node*next;
}Node;
Node*top=NULL,*temp;
int data;
void Push(int data)
{
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=top;
    top=newNode;

}
void Pop()
{
if(top==NULL){
    printf("Stack is underflow\n");
    return;
}
temp=top;
top=top->next;
printf("Deleted element=%d\n",temp->data);
free(temp);
}
void Peek()
{
    if(top==NULL)
    {
        printf("Stack is Empty\n");
        return;
    }
    printf("Top element=%d\n",top->data);

}
void Display()
{
    if(top==NULL)
    {
    printf("Stack is Empty\n");
    return;
    }
    temp=top;
    printf("Stack elements are:\n");
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }

}
int main()
{
    int op;
    while(1)
    {
        printf("\n-------STACK OPERATIONS-----\n");
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("enter an option\n");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            printf("Enter an element to push:");
            scanf("%d",&data);
            Push(data);
            break;
        case 2:
            Pop();
            break;
        case 3:
            Peek();
            break;
        case 4:
            Display();
            break;
        case 5:
            printf("Program completed\n");
            exit(0);
            break;
        default:
            printf("Enter a valid position\n");
            break;
        }
    }
}

