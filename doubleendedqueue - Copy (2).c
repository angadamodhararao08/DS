#include<stdio.h>
#include<stdlib.h>
#define size 10
int queue[size];
int front=-1,rear=-1,i,value;
void Insert_front(int data)
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
        front=(front-1+size)%size;
    }
    queue[front]=data;
    printf("Inserted at front element=%d\n",data);
}
void Insert_rear(int data)
{
    if((rear+1)%size==front)
    {
        printf("queue is overflow\n");
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
    printf("Inserted at rear element=%d\n",data);
}
void Delete_front()
{
    if(front==-1)
    {
        printf("Queue is underflow\n");
        return;
    }
    value=queue[front];
    printf("Deleted at front element=%d\n ",value);
    if(front==rear)
    {
        rear=-1;
        front=-1;
    }
    else
    {
        front=(front+1)%size;
    }

}
void Delete_rear()
{
    if(front==-1)
    {
        printf("Queue is underflow\n");
        return;
    }
    value=queue[rear];
    printf("Deleted at rear element=%d\n",value);
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        rear=(rear-1+size)%size;
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
        printf("\nDouble Ended Queue Operations....\n");
        printf("1.Inser at front\n2.Insert at rear\n3.Delete at front\n");
        printf("4.Delete at rear\n5.Display\n6.Exit\n");
        printf("Enter an option:");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            printf("Enter element to insert at front:");
            scanf("%d",&data);
            Insert_front(data);
            break;
        case 2:
            printf("Enter elemnt to insert at rear:");
            scanf("%d",&data);
            Insert_rear(data);
            break;
        case 3:
            Delete_front();
            break;
        case 4:
            Delete_rear();
            break;
        case 5:
            Display();
            break;
        case 6:
            printf("Program completeed\n");
            exit(0);
            break;
        default:
            printf("Enter a valid option\n");
            break;
        }
    }
}
