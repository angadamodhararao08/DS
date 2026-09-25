#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node* next;
};
int pos;
struct Node* head=NULL,*temp,*curr,*prev;
void InsertAtBegin(int data)
{
struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
newNode->data=data;
newNode->next=head;
head=newNode;
printf("\nData inserted at begin succesfully\n");
}
void InsertAtEnd(int data)
{
struct Node* temp;
struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
newNode->data=data;
newNode->next=NULL;
if(head==NULL){
    head=newNode;
    return;
    }
temp=head;
while(temp->next!=NULL){
temp=temp->next;
}
temp->next=newNode;
printf("Data inserted at end successfully\n");
}
void InsertAtPosition(int data,int pos)
{
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    if(pos==1){
        newNode->next=head;
        head=newNode;
        return;
    }
    int i=1;
    temp=head;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
        if(temp==NULL){
            printf("Invalid position\n");
            return;
        }
    }
    newNode->next=temp->next;
    temp->next=newNode;
}
void DeleteAtBegin()
{
    if(head==NULL){
        printf("List is Empty\n");
        return;
    }
    temp=head;
    head=temp->next;
    free(temp);
}
void DeleteAtEnd()
{
    temp=head;
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    if(head->next==NULL)
    {
    head=NULL;
    free(temp);
    return;
    }
    curr=head,prev=NULL;
    while(curr->next!=NULL)
    {
    prev=curr;
    curr=curr->next;
    }
    prev->next=NULL;
    free(curr);
}
void DeleteAtPosition(int pos)
{
    temp=head;
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    if(pos==1){
     head=head->next;
     free(temp);
     return;
    }
    int i=1;
    curr=head,prev=NULL;
    while(i<=pos-1)
    {
        prev=curr;
        curr=curr->next;
        i++;
        if(curr==NULL){
            printf("Invalid position\n");
            return;
        }
        prev->next=curr->next;
        free(curr);
    }
}
void Display()
{
    struct Node* temp=head;
    if(temp==NULL){
        printf("List is Empty");
        return;
    }
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }

}
void Search(int data)
{
    temp=head;
int key=data;
if(head==NULL)
{
    printf("List is empty\n");
    return;
}
pos=1;
while(temp!=NULL)
{
if(temp->data==key){
    printf("Element found at %d position\n",pos);
    return;
}
temp=temp->next;
pos++;
}
printf("Enter a valid element\n");
}
int main()
{

    int op,data;
    while(1){
    printf("\nSLL Operations............\n");
    printf("1.InsertAtBegin\n2.InsertAtEnd\n3.InsertAtPosition\n");
    printf("4.DeleteAtBegin\n5.DeleteAtEnd\n6.DeleteAtPosition\n");
    printf("7.Display\n8.Search\n9.Quit\n");
    printf("Enter an option:");
    scanf("%d",&op);
    switch(op)
    {
    case 1:
        printf("\nEnter element to add at begin\n");
        scanf("%d",&data);
        InsertAtBegin(data);
        break;
    case 2:
        printf("\nEnter data to insert at end:\n");
        scanf("%d",&data);
        InsertAtEnd(data);
        break;
    case 3:
        printf("Enter data to add and its position to insert:\n");
        scanf("%d %d",&data,&pos);
        InsertAtPosition(data,pos);
        break;
    case 4:
        DeleteAtBegin();
        break;
    case 5:
        DeleteAtEnd();
        break;
    case 6:
        printf("Enter position to delete element\n");
        scanf("%d",&pos);
        DeleteAtPosition(pos);
        break;
    case 7:
        Display();
        break;
    case 8:
        printf("Enter element to search:\n");
        scanf("%d",&data);
        Search(data);
        break;
    case 9:
        exit(0);
        break;
    default:
        printf("Enter a valid option\n");
        break;

    }
    }

}
