//program for polynomial addition//
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
int coef;
int exp;
struct node*next;
}Node;
Node *r=NULL,*p=NULL,*q=NULL;
void InsertAtEndRes(int coef,int exp)
{
    Node*temp=r;
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->coef=coef;
    newNode->exp=exp;
    newNode->next=NULL;
    if(r==NULL)
    {
        r=newNode;
        return;
    }
    while(temp->next!=NULL)
    {
     temp=temp->next;
    }
    temp->next=newNode;

}
void display(Node*poly)
{
    printf("\nPolynomial=");
    Node*temp=poly;
    while(temp!=NULL)
    {
        printf("%+dx^%d",temp->coef,temp->exp);
        temp=temp->next;
    }
}
void InsertAtBeginpoly1(int coef,int exp)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->coef=coef;
    newNode->exp=exp;
    newNode->next=p;
    p=newNode;
}
void InsertAtBeginpoly2(int coef,int exp)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->coef=coef;
    newNode->exp=exp;
    newNode->next=q;
    q=newNode;
}
void Addpolynomials()
{
    int coef,exp;
    Node*p1=p;
    Node*q1=q;
    while(p1!=NULL&&q1!=NULL)
    {
        if(p1->exp==q1->exp)
        {
            coef=p1->coef+q1->coef;
            exp=p1->exp;
            InsertAtEndRes(coef,exp);
            p1=p1->next;
            q1=q1->next;
        }
        else if(p1->exp>q1->exp)
        {
          InsertAtEndRes(p1->coef,p1->exp);
        p1=p1->next;
        }
        else
        {
            InsertAtEndRes(q1->coef,q1->exp);
            q1=q1->next;
        }
    }
    while(p1!=NULL)
    {
     InsertAtEndRes(p1->coef,p1->exp);
     p1=p1->next;
    }
    while(q1!=NULL)
    {
     InsertAtEndRes(q1->coef,q1->exp);
     q1=q1->next;
    }
}

int main()
{
    //p=5x^6+4x^3+5x^0,q=4x^3+6x^2+7x^1//
    InsertAtBeginpoly1(5,0);
    InsertAtBeginpoly1(4,3);
    InsertAtBeginpoly1(5,6);
    InsertAtBeginpoly2(7,1);
    InsertAtBeginpoly2(6,2);
    InsertAtBeginpoly2(4,3);
    display(p);
    display(q);
    Addpolynomials();
    display(r);
}
