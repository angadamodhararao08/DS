#include<stdio.h>
void swaparray(int a[],int n)
{
    int i=0,j=n-1,temp;
    while(i<j)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        i++;
        j--;
    }
}
int main()
{
    int i,n=6;
    int a[]={1,2,4,5,6,5};
    printf("before\n");
    for(i=0;i<6;i++)
        printf("%d\t",a[i]);
    swaparray(a,n);
    printf("\nafter\n");
    for(i=0;i<6;i++)
    printf("%d\t",a[i]);
}
