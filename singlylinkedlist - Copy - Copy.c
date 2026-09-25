#include<stdio.h>
#include<stdlib.h>
int i,data,pos,key;
struct node{
int data;
struct node*next;
};
struct node* head=NULL;
struct node*temp,*prev,*curr;
void insertatbegin(int data)
{
struct node* newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=data;
newnode->next=head;
head=newnode;
return;
}
void insertatend(int data)
{
struct node* newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=data;
newnode->next=NULL;
if(head==NULL){
head=newnode;
return;
}
temp=head;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=newnode;
return;
}
void insertatpos(int data,int pos)
{
struct node*newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=data;
if(pos==1){
newnode->next=head;
head=newnode;
return;
}
temp=head;
i=1;
while(i<pos-1)
{
temp=temp->next;
i++;
if(temp==NULL){
printf("enter a valid position \n");
return;
}
}
newnode->next=temp->next;
temp->next=newnode;
return;
}
void deleteatbegin()
{
temp=head;
if(temp==NULL)
{
printf("List is empty\n");
return;
}
head=temp->next;
free(temp);
}
void deleteatend()
{
temp=head;
if(temp==NULL)
{
printf("List is empty\n");
return ;
}
if(temp->next==NULL)
{
head=NULL;
free(temp);
return;
}
prev=NULL,curr=head;
while(curr->next!=NULL)
{
prev=curr;
curr=curr->next;
}
prev->next=NULL;
free(curr);
}
void deleteatpos(int pos)
{
temp=head;
if(temp==NULL)
{
printf("List is empty \n");
return;
}
if(pos==1)
{
head=temp->next;
free(temp);
return;
}
i=1,prev=NULL,curr=head;
while(i<=pos-1)
{
prev=curr;
curr=curr->next;
i++;
if(curr==NULL)
{
printf("Enter valid position \n");
return;
}
prev->next=curr->next;
free(curr);
}
}
void display()
{
temp=head;
while(temp!=NULL){
printf("%d\t",temp->data);
temp=temp->next;
}
return;
}
void search(int data)
{
key=data,pos=1;
temp=head;
if(temp==NULL)
{
printf("Empty list\n");
return;
}
while(temp!=NULL)
{
if(temp->data==key)
{
printf("Element found position is %d",pos);
return;
}
temp=temp->next;
pos++;
}
printf("Element not found \n");
}
int main(){
int op;
while(1){
printf("\nSLL operations \n");
printf("1.insertatbegin\n2.insertatend\n3.insertatpos\n");
printf("4.deleteatbegin\n5.deleteatend\n6.deleteatpos\n");
printf("7.display\n8.search\n9.exit\n");
printf("Enter an option:\n");
scanf("%d",&op);
switch(op)
{
case 1:
printf("Enter element to add at begin\n");
scanf("%d",&data);
insertatbegin(data);
break;
case 2:
printf("Enter the value to insert at end\n");
scanf("%d",&data);
insertatend(data);
break;
case 3:
printf("Enter the element to add and it's position:\n");
scanf("%d %d",&data,&pos);
insertatpos(data,pos);
break;
case 4:
deleteatbegin();
break;
case 5:
deleteatend();
break;
case 6:
printf("Enter the position to delete element \n");
scanf("%d",&pos);
deleteatpos(pos);
break;
case 7:
printf("list elements are:\n");
display();
break;
case 8:
printf("Enter element to search:\n");
scanf("%d",&data);
search(data);
break;
case 9:
exit(0);
break;
default:
printf("Enter valid option\n");
break;
}
}
}