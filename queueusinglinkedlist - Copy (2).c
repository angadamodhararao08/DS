#include<stdio.h>
#include<stdlib.h>
int data;
typedef struct node{
int data;
struct node*next;
}Node;
Node *front=NULL,*rear=NULL,*temp;
void Enqueue(int data)
{
   Node *newNode=(Node*)malloc(sizeof(Node));
   newNode->data=data;
   newNode->next=NULL;
   if(rear==NULL)
   {
       front=newNode;
       rear=newNode;
       return;
   }
       rear->next=newNode;
       rear=newNode;
       printf("Element iserted successfully\n");
}
void Dequeue()
{

}
void Peek()
{
if(front==NULL)
{
    printf("Queue is empty\n");
        return;
}
printf("Front element=%d",front->data);
}
void Display()
{
    if(front==NULL)
    {
        printf("Queue is empty");
        return;
    }
    temp=front;
    printf("Queue elements are:");
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
        printf("\n---Queue operations using array---\n");
        printf("1.Enqueue\n2.Dequque\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter an option:");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                printf("Enter the element to insert:");
                scanf("%d",&data);
                Enqueue(data);
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                Peek();
                break;
            case 4:
                Display();
                break;
            case 5:
                printf("Program completed...\n");
                exit(0);
                break;
            default:
                printf("Enter a valid option\n");
                break;
        }
    }
}

