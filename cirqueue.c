#include<stdio.h>
#include<stdlib.h>
#define size 5
int queue[size];
int front=-1,rear=-1,i;
void Enqueue(int data)
{
    if((rear+1)%size==front)
    {
        printf("Queue is overflow\n");
        return;
    }
    if(front==-1)
    {
        front=0;
        rear=0;
    }
    else
    {
        rear=(rear+1)%size;
    }
    queue[rear]=data;
    printf("Inserted element=%d\n",data);
}
void Dequeue()
{
    int value;
    if(front==-1)
    {
        printf("Queue is underfloe\n");
        return;
    }
    value=queue[front];
    printf("Deleted element=%d\n",value);
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        front=(front+1)%size;
    }
}
void Display()
{
    if(front==-1)
    {
        printf("Queue is empty\n");
        return;
    }
    i=front;
    printf("Queue elements are:");
    while(i!=-1)
    {
     printf("%d\t",queue[i]);
     if(i==rear)
     {
         break;
     }
     i=(i+1)%size;
    }
}
int main()
{
    int op,data;
    while(1)
    {
        printf("\nCircular Queue operations.....\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
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
            Display();
            break;
        case 4:
            printf("Program completed\n");
            exit(0);
            break;
        default:
            printf("Enter a valid option\n");
            break;
        }

    }
}

