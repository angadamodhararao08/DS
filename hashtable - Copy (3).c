#include<stdio.h>
#include<stdlib.h>
#define size 10
#define empty -1
int hashtable[size];
int i;
void setempty()
{
    for(i=0;i<size;i++)
    {
        hashtable[i]=empty;
    }
}
int hash(int data)
{
    return data%size;
}
void insert(int data)
{
    int index=hash(data);
    int i=0,pos;
    while(i<size)
    {
        pos=(index+i)%size;
        if(hashtable[pos]==empty)
        {
            hashtable[pos]=data;
            printf("Inserted %d at index %d\n",data,pos);
            return;
        }
        else
            i++;

    }
    printf("Hashtable is full,we can not insert\n");
}
int search(int data)
{
    int index=hash(data);
    int i,pos;
    while(i<size)
    {
        pos=(index+i)%size;
        if(pos==empty)
        {
            return -1;
        }
        if(hashtable[pos]==data)
            return pos;
        else
            i++;
    }
    return -1;
}
void display()
{
    int i;
    printf(".......Hash Table.....\n");
    for(i=0;i<size;i++)
    {
        if(hashtable[i]==empty)
        printf("Index  %d =....\n",i);
        else
            printf("Index %d =%d\n",i,hashtable[i]);
    }
}
int main()
{
    int i,n,data,key,k;
    setempty();
    printf("Enter the no. of values to insert:");
    scanf("%d",&n);
    printf("Enter the %d values:",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&data);
        insert(data);
    }
    display();
    printf("Enter the elemnt to search:");
    scanf("%d",&key);
    k=search(key);
    if(k==-1)
    printf("Element is not found\n");
 else
    printf("Index of %d is:%d",key,k);
}
    